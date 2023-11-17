// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoComponent.h"

// Sets default values for this component's properties
UAmmoComponent::UAmmoComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAmmoComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CurrentAmmo = MaxAmmo;
}


// Called every frame
void UAmmoComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAmmoComponent::AddAmmo(int Ammo)
{
	if (CurrentAmmo + Ammo <= MaxAmmo) {
		CurrentAmmo += Ammo;
	}
	else {
		CurrentAmmo = MaxAmmo;
	}
}

void UAmmoComponent::DecreaseOneAmmo()
{
	if (CurrentAmmo != 0) CurrentAmmo--;
}

int UAmmoComponent::GetAmmo()
{
	return CurrentAmmo;
}



