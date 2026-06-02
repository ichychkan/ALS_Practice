#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ALSPlayerController.generated.h"


struct FInputActionValue;
class UInputMappingContext;
class UInputDataConfig;

UCLASS()
class ALS_PRACTICE_API AALSPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	void LookHandle(const FInputActionValue& Value);
	void MoveHandle(const FInputActionValue& Value);
	void JumpHandle();
	
	void ChangeWeaponHandle(const FInputActionValue& Value);
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	
	UPROPERTY(EditDefaultsOnly, Category = "EnhancedInput")
	TObjectPtr<UInputDataConfig> InputActions;
};
