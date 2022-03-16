// Fill out your copyright notice in the Description page of Project Settings.


#include "Maario.h"
#include "Components/SphereComponent.h"
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

	//HitDetection OverlapBegins, it will turn from false to true, changing the animation
	

}

// Called to bind functionality to input
void AMaario::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMaario::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, (TEXT("Overlap Begins!")));
}

void AMaario::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, (TEXT("Overlap End!")));
}