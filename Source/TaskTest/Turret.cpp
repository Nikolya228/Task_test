// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "HealthComponent.h"
#include "Bullet.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseTurret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseTurret"));
	BaseTurret->SetupAttachment(RootComponent);

	GunTurret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gun Turret"));
	GunTurret->SetupAttachment(BaseTurret);

	Muzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	Muzzle->SetupAttachment(GunTurret);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	//CharacterMovement = CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("CharacterMovementComp"));
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurret::Shoot()
{
	ABullet* Projectile = GetWorld()->SpawnActor<ABullet>(ProjectileClass, Muzzle->GetComponentLocation(), GetActorRotation());
	Projectile->SetOwner(this);
}

bool ATurret::isDead() const
{
	return HealthComponent->isDead();
}

