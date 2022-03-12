// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet_Actor.generated.h"

UCLASS()
class TEAMTENCOMP3_API ABullet_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BulletMesh")
		class UStaticMeshComponent* BulletMesh;


	FVector NewLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BulletCharacteristic")
	float LivingTimeOfBullets = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BulletCharacteristic")
	float BulletSpeed = 10;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BulletCharacteristic")
	float Bullets = 10;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BulletCharacteristic")
		float EndOfLiving = 10;
};
