// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "TurretAIController.h"

void ADroneGameMode::KilledPawn(AActor* PawnKilled)
{
	APlayerController* PlayerContoller = Cast<APlayerController>(PawnKilled->GetInstigatorController());
	if (PlayerContoller) {
		EndGame(false);
	}
	else {
		for (ATurretAIController* TurretAIController : TActorRange<ATurretAIController>(GetWorld())) {
			if (!TurretAIController->isDead()) {
				return;
			}
		}
		EndGame(true);
	}
}

void ADroneGameMode::EndGame(bool bIsPlayerWin)
{
	for (AController* Controller : TActorRange<AController>(GetWorld())) {
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWin;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
