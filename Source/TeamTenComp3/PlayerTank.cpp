// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Math/Rotator.h"
#include "Components/ArrowComponent.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"
#include "Blueprint/UserWidget.h"
#include "AmmoWidget.h"
//#include "GameFramework/PlayerStart.h"
//#include "Bullet_Actor.h"


// Sets default values
APlayerTank::APlayerTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//set SphereComponent to Root
	//Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	//SetRootComponent(Sphere);

	//set mesh to Root
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
		SetRootComponent(Mesh);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Sheep(TEXT("StaticMesh'/Game/Assets/JohannaAssests/Bullet.Bullet'"));
    if (Sheep.Succeeded())
    {
	    Mesh->SetStaticMesh(Sheep.Object);
    }

	//attach SphereComponent to Root
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Mesh);
	Sphere->OnComponentHit.AddDynamic(this, &APlayerTank::OnHit);

	//Arrow component
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Mesh);

	//Set boom to Root
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(Mesh);
	//define boom
	CameraBoom->TargetArmLength = 1000.f;
	CameraBoom->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->CameraLagSpeed = 10.f;

	//Set Camera to boom
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	//Boom connecting Maario and PlayerTank
	MaarioBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("MaarioBoom"));
	MaarioBoom->SetupAttachment(Mesh);
	FRotator UpwardsVector = GetActorRotation();
	UpwardsVector += FRotator(0.f, 0.f, 100.f);
	MaarioBoom->SetRelativeRotation(UpwardsVector);
	MaarioBoom->bEnableCameraLag = false;
	MaarioBoom->TargetArmLength = 1000.f;
	//Set MaarioBoom to Maario
	
	//Movement
	//MovementComponenet
	MoveComp = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MoveComp"));
	MoveComp->UpdatedComponent = Mesh;
	//speed
	CurrentVelocity = FVector(0.f);
	Speed = 100;
	//CameraControl pitch/yaw
	CameraInput = FVector2D(0.f,0.f);

	//makes pawn accessible
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APlayerTank::BeginPlay()
{
	Super::BeginPlay();

	//Spawning in Maario with this class -> the class is not specified in OutputLog
	UWorld* World = GetWorld();
	FVector MaarioSpot = GetActorLocation();
	FVector BackwardVector = GetActorForwardVector();
	BackwardVector.Y *= -100;
	MaarioSpot += BackwardVector;
	World->SpawnActor<ACharacter>(MaarioSpawn, MaarioSpot, GetActorRotation());
	
}

// Called every frame
void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Movement Location
	//define new location
	NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	//set new location
	SetActorRelativeLocation(NewLocation);
	//Movement Rotation
	NewRotation = GetActorRotation();
	//Yaw -
	NewRotation.Yaw += CameraInput.X;
	SetActorRelativeRotation(NewRotation);
	//Pitch -
	//Get CameraBoom Rotation
	FRotator NewCameraBoomRotation = CameraBoom->GetComponentRotation();
	NewCameraBoomRotation.Pitch = FMath::Clamp(NewCameraBoomRotation.Pitch += CameraInput.Y, -80.f, -15.f);
	CameraBoom->SetWorldRotation(NewCameraBoomRotation);
}

// Called to bind functionality to input
void APlayerTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Forward", this, &APlayerTank::MoveForward);
	InputComponent->BindAxis("Right", this, &APlayerTank::MoveRight);

	InputComponent->BindAxis("CameraPitch", this, &APlayerTank::CameraPitch);
	InputComponent->BindAxis("CameraYaw", this, &APlayerTank::CameraYaw);

	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &APlayerTank::Fire);
}

void APlayerTank::MoveForward(float Value)
{
	//CurrentVelocity.X = FMath::Clamp(Value, -1.f, 1.f) * Speed;
	FVector Forward = GetActorForwardVector();

	if (MoveComp)
	{
		MoveComp->AddInputVector(Forward*Value);
	}
}

void APlayerTank::MoveRight(float Value)
{
	//CurrentVelocity.Y = FMath::Clamp(Value, -1.f, 1.f) * Speed;
	FVector Right = GetActorRightVector();

	if (MoveComp)
	{
		MoveComp->AddInputVector(Right*Value);
	}
}

void APlayerTank::CameraPitch(float AxisValue)
{
	CameraInput.X = AxisValue;
}

void APlayerTank::CameraYaw(float AxisValue)
{
	CameraInput.Y = AxisValue;
}



void APlayerTank::Fire()
{
	if (AmmoAmount > 0) {
		AmmoAmount--;

		UWorld* World = GetWorld();

		if (World) {

			FVector PlayerLocation = GetActorLocation();
			/** Bjorn Joakim suggegsted this addition - adding a forward vector and multiplying it to the location vector*/
			FVector ForwardVector = GetActorForwardVector();
			ForwardVector *= 200;
			PlayerLocation += ForwardVector;
			/** made a pointer ABullet_Actor, added a variable name and assignment sign*/
			World->SpawnActor<AActor>(BulletSpawn, PlayerLocation, GetActorRotation());  // AAcor added
		}
		if (AmmoAmount == 0) {
			//no fire
		}
	}
}

void APlayerTank::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	NumberHits++;
}

int APlayerTank::PlayerHealth()
{
	NumberHits *= -20;

	HealthAmmount += NumberHits;
	
	return HealthAmmount;
}


float APlayerTank::ReturnAmmo()
{
	return AmmoAmount;
}

float APlayerTank::ReturnMaxAmmo()
{
	return MaxAmmo;
}

void APlayerTank::SwitchLevel(FName LevelName) {
	UWorld* World = GetWorld();
	if (World) {
		FString CurrentLevel = World->GetMapName();

		FName CurrentLevelName(CurrentLevel);
		if (CurrentLevelName != LevelName) {
			UGameplayStatics::OpenLevel(World, LevelName);
		}
	}
}
