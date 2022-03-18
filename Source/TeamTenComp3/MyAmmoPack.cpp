// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAmmoPack.h"
#include "PlayerTank.h"

AMyAmmoPack::AMyAmmoPack() {

	//static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshComp(TEXT("StaticMesh'/Game/Assets/JohannaAssests/Bullet.Bullet'"));

	//if (MeshComp.Succeeded()) {
	//	AmmoMesh->SetStaticMesh(MeshComp.Object);
	//}

}

void AMyAmmoPack::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, bFromSweep, bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("testing 1"));
	//AmmoAmount = AmmoAmount + 5;
}

void AMyAmmoPack::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	UE_LOG(LogTemp, Warning, TEXT("testing 2!!!!!!!!!!!!!!!!!!!!!!!!!"));
}