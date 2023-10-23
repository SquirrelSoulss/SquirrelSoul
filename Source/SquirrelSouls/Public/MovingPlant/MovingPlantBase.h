// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlantClass.h"
#include "PlantBaseState.h"
#include "MovingPlantBase.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UMovingPlantBase : public UPlantBaseState
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	AMovingPlantClass* mPlant = nullptr;
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void Damaged(float damage) override;
};
