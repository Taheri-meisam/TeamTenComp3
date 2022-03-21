// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MaarioAIController.generated.h"

/**
 * 
 */
UCLASS()
class TEAMTENCOMP3_API AMaarioAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	/** decide the size of acceptance radius*/
	UPROPERTY(EditAnywhere)
	float AcceptanceRadiusMaario = 200;
	
};
