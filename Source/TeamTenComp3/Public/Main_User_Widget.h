// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TeamTenComp3/TeamTenComp3GameModeBase.h"
#include "TeamTenComp3/PlayerTank.h"
#include "Kismet/GamePlayStatics.h"
#include "Main_User_Widget.generated.h"

/**
 * 
 */
UCLASS()
class TEAMTENCOMP3_API UMain_User_Widget : public UUserWidget
{
	GENERATED_BODY()
public:

	APlayerTank* PlayerTankPts = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	ATeamTenComp3GameModeBase* GameModeBasePtrs = Cast<ATeamTenComp3GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
		class UUserWidget* Ammo_Bar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
		class UUserWidget* Ammo_Max_Amount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
		class UUserWidget* Ammo_Zero;

};
