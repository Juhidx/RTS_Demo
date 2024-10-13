// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldActor.h"

#include "ComponentUtils.h"
#include "VectorVMExperimental.h"
#include "Components/DecalComponent.h"

// Sets default values for this component's properties
UWorldActor::UWorldActor()
{
	CurrentHealth = MaxHealth;
}


// Called when the game starts
void UWorldActor::BeginPlay()
{
	Super::BeginPlay();
	
	TObjectPtr<AActor> ParentActor = GetOwner();
	if (ParentActor)
	{
		DecalComponent->AttachToComponent(ParentActor->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		DecalComponent->SetVisibility(false);
	}
}


// Called every frame
void UWorldActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UWorldActor::SelectActor()
{
	DecalComponent->SetVisibility(true);
}

void UWorldActor::DeselectActor()
{
	DecalComponent->SetVisibility(false);
}

void UWorldActor::HighlightActor()
{
	DecalComponent->SetMaterial(0, HighlightedMaterial);
}

void UWorldActor::UnHighlightActor()
{
	DecalComponent->SetMaterial(0, PrimaryMaterial);
}

void UWorldActor::ReceiveAnyDamage_Implementation(const float Damage, const EWeaponType WeaponType,
                                                  APlayerController* Instigator, AActor* DamageCauser)
{
	
}