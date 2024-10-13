// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None UMETA(DisplayName="None"),
	Tool UMETA(DisplaName="Tool"),
	Fist UMETA(DisplayName="Fist"),
	Sword UMETA(DisplayName="Sword"),
	Spear UMETA(DisplayName="Spear")
};

class RTS_DEMO_API WeaponTypes
{
public:
	WeaponTypes();
	~WeaponTypes();
};
