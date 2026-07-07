#include "CppHubActor.h"

ACppHubActor::ACppHubActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACppHubActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(spawn_timer_handle, this, &ACppHubActor::OnTimeToSpawn, spawn_timer_rate, true);
	InitialLocation = GetActorLocation();
}

void ACppHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SinMovement();
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

void ACppHubActor::SinMovement()
{
	float ranning_time = GetGameTimeSinceCreation();
	float delta_z = amplitude * FMath::Sin(frequency * ranning_time);

	FVector new_loc = InitialLocation;
	new_loc.Z += delta_z;
	SetActorLocation(new_loc);
}

