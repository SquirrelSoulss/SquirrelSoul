// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBaseClass.h"
#include "Perception\PawnSensingComponent.h"
#include "SquirrelSouls/PlayerCharacter.h"
#include "StateManagerComponent.h"
#include "IDamageRecievers.h"
#include <Kismet/KismetMathLibrary.h>
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyBaseClass::AEnemyBaseClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	stateManager = CreateDefaultSubobject<UStateManagerComponent>(TEXT("State Manager"));
	pawnSenser = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Senser"));
}
//kind of like awake?
void AEnemyBaseClass::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//pawnSenser->OnSeePawn.AddDynamic(this, &AEnemyBaseClass::OnSeePawn);
}
// Called when the game starts or when spawned
void AEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();
	mainCharacter = UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCharacter::StaticClass());
}

// Called every frame
void AEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (shouldTrack && mainCharacter != nullptr) {

	}
}

// Called to bind functionality to input
void AEnemyBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

void AEnemyBaseClass::OnSeePawn(APawn* player)
{


	APawn* Player = Cast<APlayerCharacter>(player); //should cast to the main character blueprint

	{
		if (Player == nullptr)
			return;

		mainCharacter = player;
	}
	
	
	//stateManager->SwitchStateByKey("Aggro");
}

void AEnemyBaseClass::PlayerSpotted_Implementation()
{
	
	
}



FRotator AEnemyBaseClass::FixRotation(FVector actorLocation, FVector targetLocation, float deltaTime, float turnSpeed)
{
	FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(actorLocation, targetLocation);
	FRotator newRotation = FMath::RInterpTo(GetActorRotation(), targetRot, deltaTime, turnSpeed);
	return newRotation;
}

//void AEnemyBaseClass::TakeDamage(float damageTaken)
//{
//	health -= damageTaken;
//}


