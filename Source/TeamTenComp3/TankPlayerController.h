// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TEAMTENCOMP3_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
	class UUserWidget* Screen_UI=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,  Category = "Widget_Ammo")
	TSubclassOf<UUserWidget> W_Ammo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget_Screen")
		TSubclassOf<UUserWidget> W_Screen;

	virtual void BeginPlay() override;
};
