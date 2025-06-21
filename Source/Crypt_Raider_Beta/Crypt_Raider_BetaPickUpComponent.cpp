// Copyright Epic Games, Inc. All Rights Reserved.

#include "Crypt_Raider_BetaPickUpComponent.h"

UCrypt_Raider_BetaPickUpComponent::UCrypt_Raider_BetaPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UCrypt_Raider_BetaPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UCrypt_Raider_BetaPickUpComponent::OnSphereBeginOverlap);
}

void UCrypt_Raider_BetaPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	ACrypt_Raider_BetaCharacter* Character = Cast<ACrypt_Raider_BetaCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
