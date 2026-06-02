#include "ALSCharacter.h"

#include "ALS_Practice/Animation/ALSBaseInterface.h"

void AALSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	ChangeEquippedWeapon(EquippedWeapon);
}

void AALSCharacter::ChangeEquippedWeapon(EWeaponType WeaponType)
{
	if (EquippedWeapon == WeaponType)
	{
		return;
	}
	
	EquippedWeapon = WeaponType;
	
	USkeletalMeshComponent* MeshComponent = GetMesh();
	if (!IsValid(MeshComponent))
	{
		return;
	}
	
	UAnimInstance* AnimInstance = MeshComponent->GetAnimInstance();
	if (!IsValid(AnimInstance))
	{
		return;
	}
	
	if (AnimInstance->GetClass()->ImplementsInterface(UALSBaseInterface::StaticClass()))
	{
		IALSBaseInterface::Execute_OnEquippedWeaponChanged(AnimInstance, EquippedWeapon);
	}
	
	UE_LOG(LogTemp, Error, TEXT("%hhu"), EquippedWeapon);
}
