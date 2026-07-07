// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.h"
#include "CppHubActor.generated.h"

class ACppBaseActor;

UCLASS()
class NETOLOGY_API ACppHubActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppHubActor();
	virtual void Tick(float DeltaTime) override;
	void OnTimeToSpawn();
	void OnTimeToDestroy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	float spawn_timer_rate = 2.f;

	UPROPERTY(EditAnywhere)
	float destroy_timer_rate = 1.f;

	FTimerHandle spawn_timer_handle;
	FTimerHandle destroy_timer_handle;

	const int32 total_count = 10;
	int32 current_timer_count = 0;

	UPROPERTY()
	TArray<ACppBaseActor*> spawned_objects;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACppBaseActor> cpp_class;

};
