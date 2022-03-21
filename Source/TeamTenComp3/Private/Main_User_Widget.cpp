// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_User_Widget.h"

void UMain_User_Widget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (PlayerTankPtrs) {
		Rest_Of_Ammo = (float)PlayerTankPtrs->AmmoAmount;
		if (Rest_Of_Ammo <= 10 && Rest_Of_Ammo >= 5) {
			Ammo_Bar->SetColorAndOpacity(FLinearColor(100.f, 1.f, 1.f));
		}

	 }
}
