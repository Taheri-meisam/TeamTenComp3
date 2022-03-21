// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProgress.h"
#include "Components/BoxComponent.h"
#include "Components/BillboardComponent.h"
#include "PlayerTank.h"

AMyProgress::AMyProgress() {

	PrimaryActorTick.bCanEverTick = false;

	TransitionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TransitionVolume"));
	RootComponent = TransitionVolume;

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	Billboard->SetupAttachment(GetRootComponent());

	TransistionLevelName = "TankLevel";
}

void AMyProgress::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, bFromSweep, bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("testing progress 1"));
	if (OtherActor) {
		APlayerTank* Tank = Cast<APlayerTank>(OtherActor);
		if (Tank) {
			Tank->SwitchLevel(TransistionLevelName);
		}
	}

}