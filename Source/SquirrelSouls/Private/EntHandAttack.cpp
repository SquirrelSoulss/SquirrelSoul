// Fill out your copyright notice in the Description page of Project Settings.


#include "EntHandAttack.h"

void UEntHandAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	EntRef->StartHandAttack(EntRef->IsCombo, EntRef->IsFireCombo);
}

void UEntHandAttack::OnExitState()
{
}

void UEntHandAttack::TickState()
{
	//EntRef->CheckForHit();
}
