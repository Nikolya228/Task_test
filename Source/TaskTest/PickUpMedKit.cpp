// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpMedKit.h"
#include "Drone.h"

APickUpMedKit::APickUpMedKit()
{

}

void APickUpMedKit::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADrone* Drone = Cast<ADrone>(OtherActor);
	if (Drone) {
		Drone->AddHealth(GiveHealth);
		Destroy();
	}
}
