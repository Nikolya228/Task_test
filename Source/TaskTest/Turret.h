// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Turret.generated.h"

UCLASS()
class TASKTEST_API ATurret : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Shoot();

	bool isDead() const;

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaseTurret;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* GunTurret;
	UPROPERTY(EditAnywhere)
	USceneComponent* Muzzle;
	UPROPERTY(EditAnywhere)
	class UHealthComponent* HealthComponent;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABullet> ProjectileClass;

};
