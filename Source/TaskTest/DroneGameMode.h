// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DroneGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TASKTEST_API ADroneGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void KilledPawn(AActor* PawnKilled);

private:
	void EndGame(bool bIsPlayerWinner);
};
