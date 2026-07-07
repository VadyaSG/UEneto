// Fill out your copyright notice in the Description page of Project Settings.


#include "CppHubActor.h"


// Sets default values
ACppHubActor::ACppHubActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACppHubActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(spawn_timer_handle, this, &ACppHubActor::OnTimeToSpawn, spawn_timer_rate, true);
}

// Called every frame
void ACppHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppHubActor::OnTimeToSpawn()
{
	if (++current_timer_count <= total_count)
	{
		const FVector location = GetActorLocation() + FVector(FMath::FRandRange(200.f, 1000.f), FMath::FRandRange(200.f, 1000.f), 0.f);
		const FRotator rotation = FRotator::ZeroRotator;
		ACppBaseActor* spawn_object = GetWorld()->SpawnActor<ACppBaseActor>(cpp_class, location, rotation);
		if (spawn_object)
		{
			spawned_objects.Add(spawn_object);
		}

	}
	else
	{
		GetWorldTimerManager().ClearTimer(spawn_timer_handle);
		for (int i = total_count; i >= 1; --i)
		{
			GetWorldTimerManager().SetTimer(destroy_timer_handle, this, &ACppHubActor::OnTimeToDestroy, destroy_timer_rate, true);
		}
	}
}

void ACppHubActor::OnTimeToDestroy()
{
	if (!spawned_objects.IsEmpty())
	{
		spawned_objects.Top()->Destroy();
		spawned_objects.Pop();

	}
	else
	{
		GetWorldTimerManager().ClearTimer(destroy_timer_handle);
	}
}

