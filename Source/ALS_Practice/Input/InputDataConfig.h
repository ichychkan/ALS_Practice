#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputDataConfig.generated.h"


class UInputAction;

UCLASS()
class ALS_PRACTICE_API UInputDataConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> EquipMainWeaponAction;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> EquipAdditionalWeaponAction;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> RemoveWeaponAction;
};
