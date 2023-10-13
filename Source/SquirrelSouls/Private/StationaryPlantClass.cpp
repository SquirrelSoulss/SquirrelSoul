// Fill out your copyright notice in the Description page of Project Settings.


#include "StationaryPlantClass.h"
#include "StateManagerComponent.h"
#include "Perception\PawnSensingComponent.h"

void AStationaryPlantClass::BeginPlay()
{
	AEnemyBaseClass::BeginPlay();
}

void AStationaryPlantClass::PostInitializeComponents()
{
	AEnemyBaseClass::PostInitializeComponents();

	pawnSenser->OnSeePawn.AddDynamic(this, &AStationaryPlantClass::OnSePawn);
}

void AStationaryPlantClass::PlayerSpotted_Implementation()
{
	AEnemyBaseClass::PlayerSpotted_Implementation();
}

void AStationaryPlantClass::Tick(float DeltaTime)
{
	AEnemyBaseClass::Tick(DeltaTime);
}

void AStationaryPlantClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	AEnemyBaseClass::SetupPlayerInputComponent(PlayerInputComponent);
}

void AStationaryPlantClass::OnSePawn(APawn* player)
{
	APawn* Player = Cast<APawn>(player); //should cast to the main character blueprint
	{
		if (Player == nullptr)
			return;
	}
	mainCharacter = player;
	stateManager->SwitchStateByKey("Aggro");
}


