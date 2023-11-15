// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GOAPGoal.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SQUIRRELSOULS_API UGOAPGoal : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GOAP")
	TMap<FString, bool> goalState;
	int32 priority = 1;
};
