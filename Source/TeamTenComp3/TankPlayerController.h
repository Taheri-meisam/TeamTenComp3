// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerTank.h"
#include "TeamTenComp3GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TEAMTENCOMP3_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	

	//Variable to hold the widget after creating this widget
	

	virtual void BeginPlay() override;



public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget>HUDOverlayAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* HUDOverlay=nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,  Category = "Widgets")
	TSubclassOf<UUserWidget> W_Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> W_Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> W_Progress;

};
