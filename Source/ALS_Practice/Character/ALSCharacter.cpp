#include "ALSCharacter.h"

void AALSCharacter::ChangeEquippedWeapon(const uint8& WeaponTypeID)
{
	EWeaponType NewPossibleWeapon = static_cast<EWeaponType>(WeaponTypeID);
	if (!StaticEnum<EWeaponType>()->IsValidEnumValue(WeaponTypeID) || EquippedWeapon == NewPossibleWeapon)
	{
		return;
	}
	
	EquippedWeapon = NewPossibleWeapon;
	
	UE_LOG(LogTemp, Error, TEXT("%hhu"), WeaponTypeID);
}
