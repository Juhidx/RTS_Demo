// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitActor.h"

#include "WorldActor.h"

// Sets default values for this component's properties
UUnitActor::UUnitActor()
{
	
}


// Called when the game starts
void UUnitActor::BeginPlay()
{
	Super::BeginPlay();
	
	TObjectPtr<AActor> ParentActor = GetOwner();
	if (ParentActor)
	{
		SetActorMeshesTeamColors(ParentActor);
	}
}

void UUnitActor::SetActorMeshesTeamColors(const TObjectPtr<AActor>& ParentActor)
{
	TArray<UMeshComponent*> MeshComponents;
	ParentActor->GetComponents(MeshComponents);

	for (UMeshComponent* MeshComp : MeshComponents)
	{
		UMaterialInterface* Material = MeshComp->GetMaterial(0);
		
		if(Material)
		{
			UMaterialInstanceDynamic* MatInst = UMaterialInstanceDynamic::Create(Material, Material);
			
			if (MatInst)
			{
				FName ParamName = TEXT("TeamColor");

				MatInst->SetVectorParameterValue(ParamName, TeamColor);
				MeshComp->SetMaterial(0, MatInst);
				//UE_LOG(LogTemp, Warning, TEXT("Material of %s is %s"), *MeshComp->GetName(), *MeshComp->GetMaterial(0)->GetName());
			}
		}
	}
}




// Called every frame
void UUnitActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UUnitActor::SetTeamVariabless(const int& NewTeamNumber, const FLinearColor& NewTeamColor)
{
	TeamNumber = NewTeamNumber;
	TeamColor = NewTeamColor;
	
	TObjectPtr<AActor> ParentActor = GetOwner();
	if (ParentActor)
	{
		UActorComponent* Component = ParentActor->GetComponentByClass(UWorldActor::StaticClass());

		if (Component)
		{
			UWorldActor* WorldActor = Cast<UWorldActor, UActorComponent>(Component);

			if(WorldActor)
			{
				WorldActor->SetMinimapColor(NewTeamColor);
			}
		}
	}
}