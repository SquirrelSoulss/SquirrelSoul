// Fill out your copyright notice in the Description page of Project Settings.


#include "EntStompAttack.h"

void UEntStompAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Stomp"));

	EntRef->StartStompAttack(EntRef->IsCombo);
}

void UEntStompAttack::OnExitState()
{
}

void UEntStompAttack::TickState()
{
}
