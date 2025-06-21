// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigger_Component.h"



UTrigger_Component::UTrigger_Component()
{
	PrimaryComponentTick.bCanEverTick = true;
}



// Called when the game starts
void UTrigger_Component::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UTrigger_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);  // Tick Component calls on the Box Component from the hearder file of this
   
    AActor* Actor = GetAcceptableActor();
    if (Actor != nullptr)
    {
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if (Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
    }
    else
    {
        Mover->SetShouldMove(false);
    }
}


void UTrigger_Component::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}


AActor* UTrigger_Component::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for (AActor* Actor : Actors)
    {
        bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
        bool IsGrabbed = Actor->ActorHasTag("Grabbed");
        if (HasAcceptableTag && !IsGrabbed)
        {
            return Actor;
        }
    }
    return nullptr;
}

/*
    for (int32 i = 0; i < Actors.Num(); i++)
    {
        FString ActorName = Actors[i]->GetActorNameOrLabel();
        UE_LOG(LogTemp, Display, TEXT("Overlapping: %s"), *ActorName);
    }
    
*/



