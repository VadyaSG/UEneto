// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

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

	virtual void BeginPlay() override;

private:
	void show_information();
	void ShowActorInformation();
	
};
