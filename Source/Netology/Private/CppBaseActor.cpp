// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"


// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(mesh);

}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
	show_information();
}

void ACppBaseActor::show_information()
{

	GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::Magenta, player_name, true, FVector2D(2.f, 2.f));

	UE_LOG(LogTemp, Display, TEXT("Player name: %s"), *player_name);

	UE_LOG(LogTemp, Display, TEXT("CppBase is here"));
	UE_LOG(LogTemp, Warning, TEXT("CPPBase class ошибка"));
	UE_LOG(LogTemp, Error, TEXT("CppBase china$$"));

	UE_LOG(LogTemp, Display, TEXT("enemy_num: %d"),enemy_num);
	UE_LOG(LogTemp, Display, TEXT("HP: %f"), current_health);
	UE_LOG(LogTemp, Display, TEXT("is alive?: %i"), is_alive);

}


// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

