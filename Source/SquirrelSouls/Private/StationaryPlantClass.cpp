// Fill out your copyright notice in the Description page of Project Settings.


#include "StationaryPlantClass.h"
#include "StateManagerComponent.h"
#include "Perception\PawnSensingComponent.h"
#include "PlantIdle.h"
#include <Kismet/KismetMathLibrary.h>
#include "SquirrelSouls/PlayerCharacter.h"


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
	if ( mainCharacter != nullptr && shouldTrack) 
	{
		FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), mainCharacter->GetActorLocation());
		FRotator newRotation = FMath::RInterpTo(targetBoneRotation,targetRot, DeltaTime, aturnSpeed); // can change speed in order to speed up tracking during attacks
		targetBoneRotation = FRotator(0,newRotation.Yaw,0); //targetBoneRotation = newRotation;
	}

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
	if(mainCharacter == nullptr && Cast<APlayerCharacter>(player) != NULL)
		mainCharacter = player;

	if (stateManager->CurrentState->IsA(UPlantIdle::StaticClass())) {
		
		stateManager->SwitchStateByKey("Suspicious");
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Sensed"));
	}
		
}


