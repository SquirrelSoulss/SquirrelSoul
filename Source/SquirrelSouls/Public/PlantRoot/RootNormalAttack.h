// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlantRoot/RootStateBase.h"
#include "RootNormalAttack.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API URootNormalAttack : public URootStateBase
{
	GENERATED_BODY()
	
public:

	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
};
