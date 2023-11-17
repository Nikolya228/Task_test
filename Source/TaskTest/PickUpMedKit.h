// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUpItems.h"
#include "PickUpMedKit.generated.h"


UCLASS()
class TASKTEST_API APickUpMedKit : public APickUpItems
{
	GENERATED_BODY()
	
public:
	APickUpMedKit();

	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UPROPERTY(EditAnywhere)
	float GiveHealth = 20;
};
