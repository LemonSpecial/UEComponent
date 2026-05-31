#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorMoveComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAKESOMETHING_API UActorMoveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UActorMoveComponent(){PrimaryComponentTick.bCanEverTick = false;}
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Move")
	float maxspeed = 600.0f;
		
public:
	UFUNCTION(BlueprintCallable, Category = "Move")
	void MoveForward(FVector forwardVector, float x);
	UFUNCTION(BlueprintCallable, Category = "Move")
	void MoveRightward(FVector rightVector, float y);
	
	UFUNCTION(BlueprintCallable, Category = "Look")
	void SetScopeAboutYaw(float min, float max) { this->miny = min; this->maxy = max; }
	UFUNCTION(BlueprintCallable, Category = "Look")
	void LookX(USceneComponent *component, float y);
	UFUNCTION(BlueprintCallable, Category = "Look")
	void LookY(USceneComponent *component, float x);
	
	
private:
	float maxy = 90.0f;
	float miny = -90.0f;
};
