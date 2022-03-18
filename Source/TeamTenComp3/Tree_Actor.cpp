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
<<<<<<< Updated upstream
	
=======
	TreeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBoxTree = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	CollisionBoxTree->SetBoxExtent(FVector(1.5f, 1.5f, 3.f));
	CollisionBoxTree->SetWorldScale3D(FVector(1.5f, 1.5f, 3.f));
	RootComponent = CollisionBoxTree;
>>>>>>> Stashed changes
	//SetRootComponent(CollisionBoxTree);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>TMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (TMesh.Succeeded()) {
		TreeMesh->SetStaticMesh(TMesh.Object);
	}
	TreeMesh->SetWorldScale3D(FVector(1.5f, 1.5f, 3.f));
<<<<<<< Updated upstream
	SetRootComponent(TreeMesh);
	CollisionBoxTree = CreateDefaultSubobject<UBoxComponent>(TEXT("TreeCollComp"));
	TreeMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
=======

>>>>>>> Stashed changes
	
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
<<<<<<< Updated upstream
	UE_LOG(LogTemp, Warning, TEXT("The tree is dead"));
	if (OtherActor->ActorHasTag("Bullets")) {
		
		ABullet_Actor* NewBullet = Cast<ABullet_Actor>(OtherActor);
		SetActorHiddenInGame(true);
	
=======
	if (OtherActor->ActorHasTag("Bullet")) {
		UE_LOG(LogTemp, Warning, TEXT("The tree is dead"));
		ABullet_Actor* NewBullet = Cast<ABullet_Actor>(OtherActor);
		FTimerHandle UnusedHadle;
		GetWorldTimerManager().SetTimer(UnusedHadle, this, &ATree_Actor::Destroy_Tree, 0.1f, false);
		SetActorHiddenInGame(true);

>>>>>>> Stashed changes
	}
}

void ATree_Actor::Destroy_Tree()
{
	
}




