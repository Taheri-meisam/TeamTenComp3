// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet_Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Tree_Actor.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABullet_Actor::ABullet_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMeshComponent"));
	RootComponent = BulletMesh;
	BulletMesh->SetSimulatePhysics(true);
	BulletMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshComponent(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshComponent.Succeeded()) {
		BulletMesh->SetStaticMesh(MeshComponent.Object);
	}
	BulletMesh->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	BulletMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	
	
}

// Called when the game starts or when spawned
void ABullet_Actor::BeginPlay()
{
	Super::BeginPlay();
	BulletMesh->OnComponentBeginOverlap.AddDynamic(this, &ABullet_Actor::OnOverlap);
}

// Called every frame
void ABullet_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NewLocation = GetActorLocation();
	NewLocation = NewLocation+GetActorForwardVector()*BulletSpeed*DeltaTime;
	SetActorLocation(NewLocation);
	
	LivingTimeOfBullets += DeltaTime;
	if (LivingTimeOfBullets > EndOfLiving /*|| LivingTimeOfBullets == EndOfLiving*/) {
		this->Destroy();
	}
}

void ABullet_Actor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Tree")) {
		UE_LOG(LogTemp, Warning, TEXT("Collidated with a tree"));
		OtherActor->Destroy();
	}
}

