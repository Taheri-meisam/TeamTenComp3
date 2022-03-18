// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyItems.h"
#include "MyAmmoPack.generated.h"

/**
 * 
 */
UCLASS()
class TEAMTENCOMP3_API AMyAmmoPack : public AMyItems
{
	GENERATED_BODY()
	
public:

	AMyAmmoPack();

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "AmmoMesh")
	UStaticMeshComponent* AmmoMesh = nullptr;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
