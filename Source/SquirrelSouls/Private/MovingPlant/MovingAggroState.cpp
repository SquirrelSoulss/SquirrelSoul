// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingAggroState.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"
#include "AIController.h"
#include "NavigationData.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include <Kismet/GameplayStatics.h>
#include "MovingPlant/MovingDecideState.h"
#include "GameFramework/CharacterMovementComponent.h"


void UMovingAggroState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner); 
	//sprint toward target 
	if (mainCharacter == nullptr) {
		mainCharacter = UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCharacter::StaticClass());
	}

	
	mPlant->ChangeMovementSpeed(mPlant->maxMovementSpeed + 300);
	aiController->MoveToActor(mainCharacter, 50); // set movementspeed to greater
}

void UMovingAggroState::OnExitState()
{
	Super::OnExitState();
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	canTriggerLunge = true;
}

void UMovingAggroState::TickState()
{
	Super::TickState();
	if (FVector::Distance(mPlant->GetActorLocation(), mainCharacter->GetActorLocation()) <= 400.f) //turn into variable
	{
		if (canTriggerLunge == true) {
			mPlant->attackTrigger = true;
			GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingAggroState::ChangeToLunge, 0.25f, false);
			canTriggerLunge = false;
		}

		//unleash melee attack
	}
}

void UMovingAggroState::Damaged(float damage)
{
	Super::Damaged(damage);
}

void UMovingAggroState::ChangeToLunge()
{
	mPlant->stateManager->SwitchStateByKey("lunge");
}
