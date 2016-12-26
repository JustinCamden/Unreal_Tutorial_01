// Fill out your copyright notice in the Description page of Project Settings.

#include "Tutorial_01.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	// Find Component Owner
	MyOwner = GetOwner();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	// Create a Rotatpr
	FRotator NewRotation = FRotator(0.0f, OpenAngle, 0.0f);

	// Set door roation
	MyOwner->SetActorRotation(NewRotation);
}

void UOpenDoor::CloseDoor()
{
	// Create a Rotatpr
	FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);

	// Set door roation
	MyOwner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}


	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
	{
		CloseDoor();
	}
}

