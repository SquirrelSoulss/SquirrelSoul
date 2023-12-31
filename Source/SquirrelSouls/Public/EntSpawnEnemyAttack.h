// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntStateBase.h"
#include "EntSpawnEnemyAttack.generated.h"

/**
 *
 */
UCLASS()
class SQUIRRELSOULS_API UEntSpawnEnemyAttack : public UEntStateBase
{
	GENERATED_BODY()

	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;

private:
	FTimerHandle TimerHandle_SpawnEnemy;

public:
	UPROPERTY(EditAnywhere)
	float RandomPointRadius = 1000.f;

	UPROPERTY(EditAnywhere)
	float SpawnIntervall = .25f;

	UFUNCTION()
	void SpawnEnemy();
	bool GetRandomPoint(const FVector& Origin, float Radius, FVector& OutLocation);
};
