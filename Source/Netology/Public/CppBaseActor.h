// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UENUM(BlueprintType)
enum class E_movement_state :uint8
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct F_transform_struct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector current_location = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator current_rotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector current_scale = FVector(2.f, 1.f, 1.f);
};

UCLASS()
class NETOLOGY_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACppBaseActor();
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere)
	FString player_name = "Vadyas";

	UPROPERTY(EditAnywhere)
	int enemy_num = 50;

	UPROPERTY(EditDefaultsOnly)
	float current_health = 32.5f;

	UPROPERTY(EditInstanceOnly)
	bool is_alive = true;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* mesh;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void show_information();

private:


	
};
