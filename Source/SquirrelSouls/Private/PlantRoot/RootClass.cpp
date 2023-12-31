// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRoot/RootClass.h"
#include "StateManagerComponent.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ARootClass::ARootClass()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	maxHealth = 75.f;
	health = maxHealth;
}

void ARootClass::BeginPlay()
{
	Super::BeginPlay();


	//Find skeletal mesh and get the ABP class
	//AnimRef = Cast<URootAnimInstance>(FindComponentByClass<USkeletalMeshComponent>()->GetAnimInstance());
	if (!AnimRef)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("anim is null"));
}

void ARootClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CanHit)
		CheckIfHit();

	if (PlayerRef != nullptr && shouldTrack)
	{
		FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), PlayerRef->GetActorLocation());
		FRotator newRotation = FMath::RInterpTo(GetActorRotation(), targetRot, DeltaTime, 2.f); // can change speed in order to speed up tracking during attacks
		SetActorRotation(FRotator(0, newRotation.Yaw, 0));
	}
}

void ARootClass::CheckIfHit_Implementation()
{
}

void ARootClass::UpdateHealthBar_Implementation(float currentHealth)
{
}

void ARootClass::PlayerInRadius()
{
	bool IsNormal = FMath::RandBool();

	if (IsNormal)
		SwitchState("Normal");
	else
		SwitchState("Swipe");
}

void ARootClass::SwitchState(FString key)
{
	stateManager->SwitchStateByKey(key);
}

void ARootClass::DoDamageToPlayer(float Damage)
{
}

void ARootClass::TakeDamage_Implementation(float Damage, float Poise, bool FireDamage, float KnockbackValue, FVector KnockbackSource)
{
	health -= Damage;
	health = FMath::Clamp(health, 0, maxHealth);

	UpdateHealthBar(Damage);

	if (health <= 0)
	{
		SwitchState("Death");
	}
}