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

		MinimapBlotComponent->AttachToComponent(ParentActor->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
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

void UWorldActor::SetMinimapColor(const FLinearColor& MinimapColor)
{
	UMaterialInterface* Material = MinimapBlotComponent->GetMaterial(0);
		
	if(Material)
	{
		UMaterialInstanceDynamic* MatInst = UMaterialInstanceDynamic::Create(Material, Material);
			
		if (MatInst)
		{
			FName ParamName = TEXT("TeamColor");

			MatInst->SetVectorParameterValue(ParamName, MinimapColor);
			MinimapBlotComponent->SetMaterial(0, MatInst);
			//UE_LOG(LogTemp, Warning, TEXT("Material of %s is %s"), *MeshComp->GetName(), *MeshComp->GetMaterial(0)->GetName());
		}
	}
}

void UWorldActor::ReceiveAnyDamage_Implementation(const float Damage, const EWeaponType WeaponType,
                                                  APlayerController* Instigator, AActor* DamageCauser)
{
	
}