// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateBase.h"
#include "Components/ActorComponent.h"
#include "StateManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SQUIRRELSOULS_API UStateManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "State Machine")
	FString InitialState;

	UPROPERTY(EditDefaultsOnly, Category = "State Machine")
	TMap<FString, TSubclassOf<UStateBase>> AvailableStates;

	UPROPERTY(EditDefaultsOnly, Category = "State Machine")
	bool shouldTrackStateHistory = false;


	UPROPERTY(BlueprintReadOnly)
	TArray<UStateBase*> StateHistory;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "State Machine Debug", meta = (ClampMin = "0", ClampMax = "10", UIMin = "0", UIMax = "10"))
	int32 StateHistoryLenght = 10;
	UPROPERTY(BlueprintReadOnly, Category = "State Machine")
	UStateBase* CurrentState;

	UPROPERTY()
	TMap<FString, UStateBase*> StateMap;

	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void SwitchStateByKey(FString StateKey);
	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void SwitchState(UStateBase* NewState);
	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void InitStateManager();
	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void PlayerOverlapped();

private:

	bool bCanTickState = false;
	void InitializeStates();
};
