// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "DroneGameMode.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CurrentHealth = MaxHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser)
{
	if (Damage <= 0.f) return;

	CurrentHealth -= Damage;
	
	if (CurrentHealth <= 0.f) {
		ADroneGameMode* GameMode = GetWorld()->GetAuthGameMode<ADroneGameMode>();
		if (GameMode) {
			GameMode->KilledPawn(GetOwner());
		}

		DamagedActor->Destroy();
	}
}

void UHealthComponent::AddHealth(float Health)
{
	if (CurrentHealth + Health <= MaxHealth) {
		CurrentHealth += Health;
	}
	else {
		CurrentHealth = MaxHealth;
	}
}

bool UHealthComponent::isDead() const
{
	return CurrentHealth <= 0;
}

float UHealthComponent::GetHealthPercent() const
{
	return CurrentHealth / MaxHealth;
}

