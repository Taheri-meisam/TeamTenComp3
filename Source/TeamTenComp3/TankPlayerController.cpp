// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Blueprint/UserWidget.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//if it finds HUDOverlayAsset it will create a widget of HUDOverlay
	if (HUDOverlayAsset) {
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
	}
	//add to viewport
	HUDOverlay->AddToViewport();
	//makes hud visible
	HUDOverlay->SetVisibility(ESlateVisibility::Visible);
}
