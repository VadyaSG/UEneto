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
	ACppHubActor();
	virtual void Tick(float DeltaTime) override;
	void OnTimeToSpawn();
	void OnTimeToDestroy();

	UFUNCTION(BlueprintCallable, Category = "SinMovement")
	void SinMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SinMovement")
	float amplitude = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SinMovement")
	float frequency = 1.f;

protected:
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

private:
	FVector InitialLocation;

};
