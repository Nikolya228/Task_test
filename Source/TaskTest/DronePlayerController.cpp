// Fill out your copyright notice in the Description page of Project Settings.


#include "DronePlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void ADronePlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget<UUserWidget>(this, HudClass);
	HUD->AddToViewport();
}

void ADronePlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromViewport();
	if (bIsWinner) {
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		if (WinScreen) {
			WinScreen->AddToViewport();
		}
	}
	else {
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if (LoseScreen) {
			LoseScreen->AddToViewport();
		}
	}

	GetWorldTimerManager().SetTimer(FTimerHandle, this, &APlayerController::RestartLevel, RestartDelay);
}
