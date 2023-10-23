// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantDeathState.h"
#include "StationaryPlantClass.h"

void UPlantDeathState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	thisPlant->dead = true;
}

void UPlantDeathState::OnExitState()
{
}

void UPlantDeathState::TickState(float DeltaTime)
{
}
