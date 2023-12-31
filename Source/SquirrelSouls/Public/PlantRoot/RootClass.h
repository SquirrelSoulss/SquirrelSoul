// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RootAnimInstance.h"
#include "IDamageRecievers.h"
#include "SquirrelSouls/Public/EnemyBaseClass.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SquirrelSouls/PlayerCharacter.h"
#include "RootClass.generated.h"

UCLASS()
class SQUIRRELSOULS_API ARootClass : public AEnemyBaseClass, public IIDamageRecievers
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARootClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	APlayerCharacter* PlayerRef = nullptr; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	URootAnimInstance* AnimRef = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackVariables")
	bool PlayerIsInRadius = false;

	UPROPERTY(EditAnywhere, Category = "AttackVariables")
	bool PlayerInRadiusCooldown = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackVariables")
	bool CanHit = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackVariables")
	bool CanBeParried = false;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackVariables")
	float DamageToDo = 15.f;

public:

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CheckHit")
	void CheckIfHit();
	virtual void CheckIfHit_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CheckHit")
	void UpdateHealthBar(float DamageTaken);
	virtual void UpdateHealthBar_Implementation(float DamageTaken);

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void PlayerInRadius();

	UFUNCTION(BlueprintCallable, Category = "States")
	void SwitchState(FString key);

	UFUNCTION(BlueprintCallable, Category = "DoDamage")
	void DoDamageToPlayer(float Damage);


	virtual void TakeDamage_Implementation(float Damage, float Poise, bool FireDamage, float KnockbackValue, FVector KnockbackSource) override;

};
