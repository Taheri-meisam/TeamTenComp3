// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tree_Actor.generated.h"

UCLASS()
class TEAMTENCOMP3_API ATree_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATree_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TreeMesh")
		class UStaticMeshComponent* TreeMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CollisionComponent")
		class UBoxComponent* CollisionBoxTree=nullptr;
	UPROPERTY(EditAnywhere, Category = "Bullet_Actors")
		TSubclassOf<AActor> Bullets;
	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void Destroy_Tree();

	FVector ActorLocation;
};
