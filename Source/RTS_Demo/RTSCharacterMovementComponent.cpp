// Fill out your copyright notice in the Description page of Project Settings.


#include "RTSCharacterMovementComponent.h"

void URTSCharacterMovementComponent::CalcVelocity(float DeltaTime, float Friction, bool bFluid,
	float BrakingDeceleration)
{
	Super::CalcVelocity(DeltaTime, Friction, bFluid, BrakingDeceleration);
	
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Speed for current frame OG X:%f, Y:%f"), Velocity.X, Velocity.Y));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("MaxSpeed X:%f"), GetMaxSpeed()));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Acceleration X:%f, Y:%f"), Acceleration.X, Acceleration.Y));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("SafeNormal X:%f, Y:%f"), Acceleration.GetSafeNormal().X, Acceleration.GetSafeNormal().Y));
	Velocity += GetMaxSpeed() * Acceleration.GetSafeNormal();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Speed for current frame NEW X:%f, Y:%f"), Velocity.X, Velocity.Y));
	
	/*if (Acceleration.IsZero())
	{
		Velocity = FVector::ZeroVector;
	}
	else
	{
		// Ignore magnitude
		
	}*/
}