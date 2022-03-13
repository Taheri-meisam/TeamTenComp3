// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Bullet_Actor.h"


// Sets default values
APlayerTank::APlayerTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//set SphereComponent to Root
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SetRootComponent(Sphere);

	//set mesh to Root
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Sphere);

	//Set boom to Root
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(Sphere);
	//define boom
	CameraBoom->TargetArmLength = 1000.f;
	CameraBoom->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->CameraLagSpeed = 10.f;

	//Set Camera to boom
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	//Movement
	//MovementComponenet
	MoveComp = CreateDefaultSubobject<UPawnMovementComponent, UFloatingPawnMovement>(TEXT("MoveComp"));
	MoveComp->UpdatedComponent = Sphere;
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
	
}

// Called every frame
void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Movement Location
	//define new location
	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	//set new location
	SetActorLocation(NewLocation);
	//Movement Rotation
	FRotator NewRotation = GetActorRotation();
	//Yaw -
	NewRotation.Yaw += CameraInput.X;
	SetActorRotation(NewRotation);
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
		//GEngine->AddOnScreenDebugMessage(-1,12.f, FColor::Black, FString::Printf((TEXT("There is how much ammo is left: %d"))));
		UWorld* World = GetWorld();
		if (World) {
			FVector PlayerLocation = GetActorLocation();
			World->SpawnActor<ABullet_Actor>(PlayerLocation + FVector(100.f, 0, 0.f), GetActorRotation());
			//bullets are spawned on mesh' X-vector creating an odd effect when shooting in -X direction bullets shoots through mesh
			//UGameplayStatics::PlaySound2D(World, FireSound, 1.f, 1.f, 0.f, 0.f);
		}
		if (AmmoAmount == 0) {
			//no fire
		}
	}
}

