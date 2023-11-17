// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpAmmo.h"
#include "Drone.h"

APickUpAmmo::APickUpAmmo(){

}

void APickUpAmmo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADrone* Drone = Cast<ADrone>(OtherActor);
	if (Drone) {
		Drone->AddAmmo(GiveAmmo);
		Destroy();
	}
}
