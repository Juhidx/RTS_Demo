// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponTypes.h"
#include "Components/ActorComponent.h"
#include "WorldActor.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RTS_DEMO_API UWorldActor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWorldActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decals")
	TObjectPtr<UDecalComponent> DecalComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decals")
	TObjectPtr<UMaterialInterface> PrimaryMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decals")
	TObjectPtr<UMaterialInterface> HighlightedMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	bool CanTakeDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Stats")
	TMap<EWeaponType, float> DamageTakenModifierTable;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Server, Unreliable, Category = "Damage")
	void ReceiveAnyDamage(const float Damage, const EWeaponType WeaponType, APlayerController* Instigator, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable)
	void SelectActor();

	UFUNCTION(BlueprintCallable)
	void DeselectActor();

	UFUNCTION(BlueprintCallable)
	void HighlightActor();

	UFUNCTION(BlueprintCallable)
	void UnHighlightActor();
};