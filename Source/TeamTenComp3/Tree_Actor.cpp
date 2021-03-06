// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree_Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Bullet_Actor.h"

// Sets default values
ATree_Actor::ATree_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TreeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TreeMeshComponent"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>TMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (TMesh.Succeeded()) {
		TreeMesh->SetStaticMesh(TMesh.Object);
	}
	SetRootComponent(TreeMesh);
	TreeMesh->SetWorldScale3D(FVector(1.5f, 1.5f, 3.f));
	CollisionBoxTree = CreateDefaultSubobject<UBoxComponent>(TEXT("TreeBoxComp"));
	TreeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBoxTree->SetBoxExtent(FVector(10.5f, 10.5f, 30.f));
	
}

// Called when the game starts or when spawned
void ATree_Actor::BeginPlay()
{
	Super::BeginPlay();
	CollisionBoxTree->OnComponentBeginOverlap.AddDynamic(this, &ATree_Actor::OnOverlap);
}

// Called every frame
void ATree_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATree_Actor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("BulletActor")) {
		ABullet_Actor* Bullet_Bullet = Cast<ABullet_Actor>(OtherActor);
		SetActorHiddenInGame(true);
	 
	}
}

void ATree_Actor::Destroy_Tree()
{
	this->Destroy();
}




