// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerTank.h"
#include "Blueprint/UserWidget.h"
#include "TeamTenComp3/PlayerTank.h"
#include "AmmoWidget.generated.h"

/**
 * 
 */
UCLASS()
class TEAMTENCOMP3_API UAmmoWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;


	TWeakObjectPtr<APlayerTank>PlayerTankPtrs;

	void PutNewOwner(APlayerTank* NewPlayerTank) {
		PlayerTankPtrs = NewPlayerTank;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserInterface", meta = (BindWidget))
		class UProgressBar* Ammo_Bar_Progress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserInterface", meta = (BindWidget))
		class UTextBlock* AmmoMax_Text_Block;

	float Rest_Of_Ammo;
	float Ammo_Percent;
};
