// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerTank.generated.h"

UCLASS()
class TEAMTENCOMP3_API APlayerTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UPROPERTY(VisibleAnywhere, Category = "Sphere")
	class USphereComponent* Sphere{ nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	class UStaticMeshComponent* Mesh{ nullptr };
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CameraBoom")
	class USpringArmComponent* CameraBoom{ nullptr };

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* Camera{ nullptr };

	//movement
	//speed
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	float Speed = 0;

private:

	
	
};
