// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnitActor.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(custom), meta=(BlueprintSpawnableComponent) )
class RTS_DEMO_API UUnitActor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUnitActor();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Team")
	int TeamNumber = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Team")
	FLinearColor TeamColor = FLinearColor(1,1,1);;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	void SetActorMeshesTeamColors(const TObjectPtr<AActor>& ParentActor);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="Team")
	void SetTeamVariabless(const int& NewTeamNumber, const FLinearColor& NewTeamColor);
};
