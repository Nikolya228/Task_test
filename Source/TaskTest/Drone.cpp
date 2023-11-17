// Fill out your copyright notice in the Description page of Project Settings.


#include "Drone.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Bullet.h"
#include "HealthComponent.h"
#include "AmmoComponent.h"

// Sets default values
ADrone::ADrone()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	Muzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	Muzzle->SetupAttachment(Camera);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	AmmoComponent = CreateDefaultSubobject<UAmmoComponent>(TEXT("AmmoComponent"));
}

// Called when the game starts or when spawned
void ADrone::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
	
}

// Called every frame
void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADrone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ADrone::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ADrone::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("MoveUp"), this, &ADrone::MoveUp);
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &ADrone::Fire);

}

float ADrone::GetHealthPercent() const
{
	return HealthComponent->GetHealthPercent();
}

int ADrone::GetAmmo() const
{
	return AmmoComponent->GetAmmo();
}

void ADrone::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void ADrone::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void ADrone::MoveUp(float AxisValue)
{
	AddMovementInput(GetActorUpVector() * AxisValue);
}

void ADrone::Fire()
{
	if (AmmoComponent->GetAmmo() > 0) {
		ABullet* Projectile = GetWorld()->SpawnActor<ABullet>(ProjectileClass, Muzzle->GetComponentLocation(), Muzzle->GetComponentRotation());
		Projectile->SetOwner(this);
		AmmoComponent->DecreaseOneAmmo();
	}
}

void ADrone::AddAmmo(int Ammo)
{
	AmmoComponent->AddAmmo(Ammo);
}

void ADrone::AddHealth(float Health)
{
	HealthComponent->AddHealth(Health);
}

