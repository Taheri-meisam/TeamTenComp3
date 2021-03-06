// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet_Actor.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
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

	//UPROPERTY(VisibleAnywhere, Category = "Sphere")
	//class USphereComponent* Sphere{ nullptr };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	class UStaticMeshComponent* Mesh{ nullptr };
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CameraBoom")
	class USpringArmComponent* CameraBoom{ nullptr };

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* Camera{ nullptr };

	//movement
	//speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Speed;

	//movement component
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UPawnMovementComponent* MoveComp{ nullptr };

	//Shoot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	int AmmoAmount = 10;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attack")
	class USoundBase* FireSound{nullptr};

	UPROPERTY(EditAnywhere, meta =(AllowPrivateAccess = "true"), Category = "Bullet"); // changed to EditAnywhere
	TSubclassOf<AActor> BulletSpawn;
	
	void Fire();
	FVector NewLocation;
	FRotator NewRotation;
		
private:

	//Movement
	//direction functions
	void MoveForward(float Value);
	void MoveRight(float Value);
	//current speed
    	FVector CurrentVelocity;

	//CameraControls
	void CameraPitch(float AxisValue);
	void CameraYaw(float AxisValue);
	//vector for camera pitch and yaw
	FVector2D CameraInput;
	
	
	
};
