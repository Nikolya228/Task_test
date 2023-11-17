// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpItems.h"
#include "Components/SphereComponent.h"
#include "Drone.h"

// Sets default values
APickUpItems::APickUpItems()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Item = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item"));
	RootComponent = Item;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SphereComponent->SetupAttachment(Item);

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &APickUpItems::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APickUpItems::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUpItems::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

