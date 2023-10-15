// Fill out your copyright notice in the Description page of Project Settings.


#include "EntIdle.h"

void UEntIdle::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Idle"));

	//stateOwner->MoveToPla
}//KALLA P� GREJEN I CLASSEN

void UEntIdle::OnExitState()
{
}

void UEntIdle::TickState()
{
}


void UEntIdle::MoveToPoint_Implementation(FVector point)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("moving time"));

}
