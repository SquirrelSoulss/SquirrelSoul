// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlant/MovingPlantBase.h"
#include "MovingHurtState.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UMovingHurtState : public UMovingPlantBase
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;

	virtual void TickState() override;
	virtual void Damaged(float damage) override;
	void SwitchToDecide();
	void SwitchToDodge();
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float timeBetweenTransition = .2f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAnimMontage* animMontage;
	bool canDodge = true;
};
