#pragma once

#include "CoreMinimal.h"
#include "ALS_Practice/Character/ALSCharacter.h"
#include "UObject/Interface.h"
#include "ALSBaseInterface.generated.h"

UINTERFACE(BlueprintType)
class UALSBaseInterface : public UInterface
{
	GENERATED_BODY()
};

class IALSBaseInterface
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnEquippedWeaponChanged(EWeaponType EquippedGun);
};