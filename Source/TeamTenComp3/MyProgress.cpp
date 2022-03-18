// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProgress.h"


AMyProgress::AMyProgress() {

//	HealthMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HealthMesh"));
//	SetRootComponent(HealthMesh);
//
//	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshComp(TEXT("StaticMesh'/Game/Assets/MaarioAssets/JohannaAssests/Health.Health'"));
//
//	if (MeshComp.Succeeded()) {
//		HealthMesh->SetStaticMesh(MeshComp.Object);
//	}
}

void AMyProgress::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, bFromSweep, bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("testing progress 1"));
	//HealthAmmount = HealthAmmount + 20;

	//if (OtherActor->IsA(APlayerTank::StaticClass()))
	//{
	//	APlayerTank* TempTank;
	//	TempTank = Cast<APlayerTank>(OtherActor);
	//	TempTank->HealthAmmount -= 10;

	//}
}

void AMyProgress::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	UE_LOG(LogTemp, Warning, TEXT("testing progress 2"));
}