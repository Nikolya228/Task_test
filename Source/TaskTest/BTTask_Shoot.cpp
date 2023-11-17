// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "Turret.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (OwnerComp.GetAIOwner() == nullptr) {
		return EBTNodeResult::Failed;
	}

	ATurret* AIControlledPawn = Cast<ATurret>(OwnerComp.GetAIOwner()->GetPawn());
	if (AIControlledPawn == nullptr) {
		return EBTNodeResult::Failed;
	}

	AIControlledPawn->Shoot();

	return EBTNodeResult::Succeeded;
}
