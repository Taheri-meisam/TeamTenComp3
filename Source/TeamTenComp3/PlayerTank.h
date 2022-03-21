// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet_Actor.h"
#include "Maario.h"
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

	UPROPERTY(VisibleAnywhere, Category = "Sphere")
	class USphereComponent* Sphere{ nullptr };


	/**Attempting to get the forward direction of the mesh at all times*/
	UPROPERTY(VisibleAnywhere, Category = "Arrow")
	class UArrowComponent* Arrow{nullptr};

	//UPROPERTY(VisibleAnywhere, Category = "Sphere")
	//class USphereComponent* Sphere{ nullptr };

	//UPROPERTY(VisibleAnywhere, Category = "Sphere")
	//class USphereComponent* Sphere{ nullptr };


	/**Mesh component*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	class UStaticMeshComponent* Mesh{ nullptr };

	/**SpringArm component*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CameraBoom")
	class USpringArmComponent* CameraBoom{ nullptr };

	/**Camera component*/
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* Camera{ nullptr };
	
	/** Spring arm holding Maario in place above PlayerTank*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "MaarioBoom")
	class USpringArmComponent* MaarioBoom{nullptr};

	//movement
	//speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Speed;

	//movement component
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UPawnMovementComponent* MoveComp{ nullptr };

	//Shoot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float AmmoAmount = 10;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
		float MaxAmmo = 10;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attack")
	class USoundBase* FireSound{nullptr};

	UPROPERTY(EditAnywhere, meta =(AllowPrivateAccess = "true"), Category = "Bullet"); // changed to EditAnywhere
	TSubclassOf<AActor> BulletSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerHealth")
	int HealthAmmount = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaarioFollower")
	TSubclassOf<AActor> MaarioSpawn;

	void Fire();
	FVector NewLocation;
	FRotator NewRotation;

	/** need function that returns int for Taisa to cast from HUD, it should return current health*/
	/** first tank needs to know if hit
	 * second thank needs to know what to do whwen hit
	 * third tank needs to know new health value after hit - it should return this value to int variable
	 */
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	int PlayerHealth();

	/** counts times PlayerTanks has been hit*/
	int NumberHits = 0;
	
	//getvectordistance - kismet
		
	float ReturnAmmo();
	float ReturnMaxAmmo();
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
