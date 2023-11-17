// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Planner/GOAPNode.h"

void UGOAPNode::InitializeFields(UGOAPNode* inParent, float inRunningcost, TMap<FString,bool> inState, UGOAPAction* inAction)
{
	parent = inParent;
	runningCost = inRunningcost;
	state = inState;
	action = inAction;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("gjorde ett lv!"));

}
