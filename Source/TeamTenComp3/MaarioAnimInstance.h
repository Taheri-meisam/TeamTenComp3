// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MaarioAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TEAMTENCOMP3_API UMaarioAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	/** */
	virtual void NativeInitializeAnimation() override;
	
	/** int to differentiate between animation instances*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	int PointingPickups;

	/** points to the playercharacter that we will interact with*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	class APawn* PlayerPawn{nullptr};
	
};
