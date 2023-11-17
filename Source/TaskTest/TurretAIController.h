// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TurretAIController.generated.h"

/**
 * 
 */
UCLASS()
class TASKTEST_API ATurretAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
	bool isDead() const;

protected:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehaviorTree;
	UPROPERTY(EditAnywhere)
	float RotateSpeed = 50;
	UPROPERTY(EditAnywhere)
	float DistanceOfView = 200;

};
