// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/PawnMovementComponent.h"

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
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));

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
	//define new location
	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	//set new location
	SetActorLocation(NewLocation);
}

// Called to bind functionality to input
void APlayerTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Forward", this, &APlayerTank::MoveForward);
	InputComponent->BindAxis("Right", this, &APlayerTank::MoveRight);
}

//virtual class UPawnMovementComponent* GetMoveComp() const
//{
//	return MoveComp;
//}

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

