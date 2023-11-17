// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretAIController.h"
#include "kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Turret.h"

void ATurretAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(AIBehaviorTree);
}

void ATurretAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	if (LineOfSightTo(PlayerPawn) && FVector::Distance(GetPawn()->GetActorLocation(), PlayerPawn->GetActorLocation()) <= DistanceOfView) {
		GetBlackboardComponent()->SetValueAsVector(TEXT("DroneLocation"), PlayerPawn->GetActorLocation());

		FRotator RightRotation = FRotationMatrix::MakeFromX(PlayerPawn->GetActorLocation() - GetPawn()->GetActorLocation()).Rotator();
		GetPawn()->SetActorRotation(FMath::RInterpConstantTo(GetPawn()->GetActorRotation(), RightRotation, DeltaTime, RotateSpeed));
	}
	else {
		GetBlackboardComponent()->ClearValue(TEXT("DroneLocation"));
	}
}

bool ATurretAIController::isDead() const
{
	ATurret* Turret = Cast<ATurret>(GetPawn());
	if (Turret) {
		return Turret->isDead();
	}
	return true;
}
