// Fill out your copyright notice in the Description page of Project Settings.


#include "MaarioAIController.h"
#include "Maario.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void AMaarioAIController::BeginPlay()
{
	Super::BeginPlay();
	
	//gets player location
	//APawn* PlayerTank = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

}

void AMaarioAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//gets player location
	APawn* PlayerTank = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	if (LineOfSightTo(PlayerTank))
	{
		//if InPointingDistance is true, SetFocus
        if (&AMaario::InPointingDistance)
        {
        	//sets focus on player
            AAIController::SetFocus(PlayerTank, EAIFocusPriority::Gameplay);
			//once player moves outside navmesh Maario stops moving, most likely loses 'sight' of the player and just stops working
			//not ideal to move into tick, but good enough
			MoveToActor(PlayerTank, AcceptanceRadiusMaario);
        	
        	if (&AMaario::InPointingDistance)
        	{
        		//clears focus
        		AAIController::ClearFocus(EAIFocusPriority::Default);
        	}
        }
	}
	else
	{
		AAIController::ClearFocus(EAIFocusPriority::Default);
		AAIController::StopMovement();
	}
	
}