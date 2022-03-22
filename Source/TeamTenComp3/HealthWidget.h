// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerTank.h"
#include "HealthWidget.generated.h"

/**
 * 
 */
UCLASS()
class TEAMTENCOMP3_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()


	/*public:
	 *virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;


	TWeakObjectPtr<APlayerTank>PlayerTankPtrs;

	void PutNewOwner(APlayerTank* NewPlayerTank) {
		PlayerTankPtrs = NewPlayerTank;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserInterface", meta = (BindWidget))
		class UProgressBar* Progress_Bar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserInterface", meta = (BindWidget))
		class UTextBlock* Progress_Bar_Text_Block;
		*/

};
