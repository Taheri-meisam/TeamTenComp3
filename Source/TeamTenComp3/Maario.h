// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "Maario.generated.h"

UCLASS()
class TEAMTENCOMP3_API AMaario : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMaario();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Maario Charcter will point at pick-ups when he notices them, need support for animation, will need to be able to point at the pick-up */
	/** Sphere component, when overlap begins, maario points in the right direction*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitDetection")
	USphereComponent* HitDetection{nullptr};

	/** variable is false, when inside sphere component it will check if it is it is true*/
	/** how to make mesh point in the right direction? vectors and a boom?*/

	/** Overlap functions - on begin overlap the bool InPointingDistance turns true*/
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	/** Overlap functions - on ends overlap the bool InPointingDistance turns false*/
	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};

	