// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUpItems.h"
#include "PickUpAmmo.generated.h"

/**
 * 
 */
UCLASS()
class TASKTEST_API APickUpAmmo : public APickUpItems
{
	GENERATED_BODY()

private:
	APickUpAmmo();

	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UPROPERTY(EditAnywhere)
	int GiveAmmo = 20;
	
};
