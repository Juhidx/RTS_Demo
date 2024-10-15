// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponTypes.h"
#include "Components/ActorComponent.h"
#include "Util/ColorConstants.h"
#include "WorldActor.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup=(custom), meta=(BlueprintSpawnableComponent) )
class RTS_DEMO_API UWorldActor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWorldActor();

	UPROPERTY(EditDefaultsOnly ,BlueprintReadWrite, Category = "Decals")
	TObjectPtr<UDecalComponent> DecalComponent;

	UPROPERTY(EditDefaultsOnly ,BlueprintReadWrite, Category = "Decals")
	TObjectPtr<UMaterialInterface> PrimaryMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Decals")
	TObjectPtr<UMaterialInterface> HighlightedMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MiniMapComponent")
	TObjectPtr<UStaticMeshComponent> MinimapBlotComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	bool CanTakeDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Stats")
	TMap<EWeaponType, float> DamageTakenModifierTable;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Server, Unreliable, Category = "Damage")
	void ReceiveAnyDamage(const float Damage, const EWeaponType WeaponType, APlayerController* Instigator, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable, Category="Actor")
	void SelectActor();

	UFUNCTION(BlueprintCallable, Category="Actor")
	void DeselectActor();

	UFUNCTION(BlueprintCallable, Category="Actor")
	void HighlightActor();

	UFUNCTION(BlueprintCallable, Category="Actor")
	void UnHighlightActor();

	UFUNCTION(BlueprintCallable, Category="Minimap")
	void SetMinimapColor(const FLinearColor& MinimapColor);
};