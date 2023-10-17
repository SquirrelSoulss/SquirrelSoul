// Fill out your copyright notice in the Description page of Project Settings.


#include "EntStateBase.h"

void UEntStateBase::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	EntRef = Cast<AEntClass>(stateOwner);
	playerRef = EntRef->playerRef;
}

void UEntStateBase::OnExitState()
{
	Super::OnExitState();
}

void UEntStateBase::TickState()
{
	Super::TickState();
}
