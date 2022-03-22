// Fill out your copyright notice in the Description page of Project Settings.


#include "Maario.h"
#include "Components/SphereComponent.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h" //Vector_Distance to make Maario not 'notice' the pickups inside radius, see Discord from Marcus H
// Sets default values
AMaario::AMaario()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HitDetection = CreateDefaultSubobject<USphereComponent>(TEXT("HitDetection"));
	HitDetection->SetupAttachment(RootComponent);
	HitDetection->SetSphereRadius(1000);
	
}

// Called when the game starts or when spawned
void AMaario::BeginPlay()
{
	Super::BeginPlay();
	HitDetection->OnComponentBeginOverlap.AddDynamic(this, &AMaario::OnOverlapBegin);
	HitDetection->OnComponentEndOverlap.AddDynamic(this, &AMaario::OnOverlapEnd);
}

// Called every frame
void AMaario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();
	FVector End = Location + Rotation.Vector() * MaxRangeLineOfSight;
	FHitResult Hit;

	bool bSuccess = GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1);

	float DistanceToTarget = UKismetMathLibrary::Vector_Distance(GetActorLocation(), End);

	if (DistanceToTarget < MaxRangeLineOfSight)
	{
		if (bSuccess)
        	{
        		DrawDebugLine(GetWorld(), Location, End, FColor::Green);
        		//bool LineOfSightTo(const class AActor * Other, FVector ViewPoint, bool bAlternateChecks ) const;
        
        	}
	}
	
}

// Called to bind functionality to input
void AMaario::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMaario::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, (TEXT("Overlap Begins!")));
	InPointingDistance = true;
	UE_LOG(LogTemp, Warning, (TEXT("InPointingDistance = true")));
}

void AMaario::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, (TEXT("Overlap End!")));
	InPointingDistance = false;
	UE_LOG(LogTemp, Warning, (TEXT("InPointingDistance = false")));
}

bool AMaario::SendInRange()
{
	
	if (InPointingDistance)
	{
		return InPointingDistance;
	}
	else
	{
		return InPointingDistance;
	}
}
