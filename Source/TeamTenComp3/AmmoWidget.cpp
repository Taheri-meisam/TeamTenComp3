// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoWidget.h"
#include "Bullet_Actor.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UAmmoWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (PlayerTankPtrs.IsValid()) {
		Rest_Of_Ammo = (float)PlayerTankPtrs->ReturnAmmo();

		Ammo_Percent = float(Rest_Of_Ammo / (float)PlayerTankPtrs->ReturnMaxAmmo());
		if (Rest_Of_Ammo <= 10.f && Rest_Of_Ammo >= 5.f)
			Ammo_Bar_Progress->SetFillColorAndOpacity(FLinearColor(0.f, 0.5f, 1.0f));
		if (Rest_Of_Ammo<5.f)
			Ammo_Bar_Progress->SetFillColorAndOpacity(FLinearColor(1.f, 0.f, 0.f));

		Ammo_Bar_Progress->SetPercent(Ammo_Percent);
		AmmoMax_Text_Block->SetText(FText::AsNumber(PlayerTankPtrs->ReturnAmmo()));
	}
}
