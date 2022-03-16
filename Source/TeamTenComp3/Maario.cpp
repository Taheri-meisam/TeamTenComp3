// Fill out your copyright notice in the Description page of Project Settings.


#include "Maario.h"

// Sets default values
AMaario::AMaario()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMaario::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMaario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMaario::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

