// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlant/MovingPlantBase.h"
#include "MovingDecideState.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UMovingDecideState : public UMovingPlantBase
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void Damaged(float damage) override;
	void SubscribedAttack();
	void ChooseBetweenAttacks();
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float requiredDistance = 120.0f;
};
