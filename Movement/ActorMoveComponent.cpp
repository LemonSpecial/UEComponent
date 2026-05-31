#include "ActorMoveComponent.h"

void UActorMoveComponent::MoveForward(FVector forwardVector, float x)
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	FVector deltaLocation = forwardVector * x * maxspeed * deltaTime;
	GetOwner()->AddActorWorldOffset(deltaLocation, true);
}

void UActorMoveComponent::MoveRightward(FVector rightVector, float y)
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	FVector deltaLocation = rightVector * y * maxspeed * deltaTime;
	GetOwner()->AddActorWorldOffset(deltaLocation, true);
}

void UActorMoveComponent::LookX(USceneComponent* component, float x)
{
	if (!component) return;
    
	float deltaTime = component->GetWorld()->GetDeltaSeconds();
	float deltaPitch = x * -180.0f * deltaTime;
	FRotator currentRot = component->GetRelativeRotation();
	float newPitch = currentRot.Pitch + deltaPitch;
	newPitch = FMath::Clamp(newPitch, miny, maxy);
	currentRot.Pitch = newPitch;
	currentRot.Roll = 0.0f;
	component->SetRelativeRotation(currentRot);
}

void UActorMoveComponent::LookY(USceneComponent* component, float y)
{
	if (!component) return;
	
	float deltaTime = component->GetWorld()->GetDeltaSeconds();
	float deltaYaw = y * 180.0f * deltaTime;
    
	FRotator deltaRotation(0.0f, deltaYaw, 0.0f);
	component->AddWorldRotation(deltaRotation);
}