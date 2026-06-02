#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ALSCharacter.generated.h"

//It's a bad decision))
//But considering that this project is purely for animation practice, I guess it's okay...
UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Unarmed,
	AdditionalWeapon,
	MainWeapon
};

UCLASS()
class ALS_PRACTICE_API AALSCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	void ChangeEquippedWeapon(EWeaponType WeaponType);
	
protected:
	UPROPERTY(BlueprintReadOnly)
	EWeaponType EquippedWeapon;
	
};
