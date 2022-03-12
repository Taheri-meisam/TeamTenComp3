// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree_Actor.h"

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
}

// Called when the game starts or when spawned
void ATree_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATree_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



