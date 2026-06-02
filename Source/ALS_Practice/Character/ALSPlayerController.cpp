#include "ALSPlayerController.h"

#include "ALSCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ALS_Practice/Input/InputDataConfig.h"
#include "GameFramework/Character.h"

void AALSPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!IsValid(LocalPlayer))
	{
		return;
	}
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	if (!IsValid(Subsystem))
	{
		return;
	}
	
	Subsystem->AddMappingContext(DefaultMappingContext, 0);
}

void AALSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhancedInputComponent))
	{
		return;
	}
	
	EnhancedInputComponent->BindAction(InputActions->LookAction, ETriggerEvent::Triggered, this, &ThisClass::LookHandle);
	EnhancedInputComponent->BindAction(InputActions->MoveAction, ETriggerEvent::Triggered, this, &ThisClass::MoveHandle);
	EnhancedInputComponent->BindAction(InputActions->JumpAction, ETriggerEvent::Started, this, &ThisClass::JumpHandle);
	EnhancedInputComponent->BindAction(InputActions->ChangerWeaponAction, ETriggerEvent::Started, this, &ThisClass::ChangeWeaponHandle);
}

void AALSPlayerController::LookHandle(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();
	
	APawn* PlayerPawn = GetPawn();
	if (!IsValid(PlayerPawn))
	{
		return;
	}
	
	PlayerPawn->AddControllerYawInput(LookVector.X);
	PlayerPawn->AddControllerPitchInput(LookVector.Y);
}

void AALSPlayerController::MoveHandle(const FInputActionValue& Value)
{
	FVector2D MoveVector = Value.Get<FVector2D>();
	
	APawn* PlayerPawn = GetPawn();
	if (!IsValid(PlayerPawn))
	{
		return;
	}
	
	PlayerPawn->AddMovementInput(PlayerPawn->GetActorForwardVector(), MoveVector.Y);
	PlayerPawn->AddMovementInput(PlayerPawn->GetActorRightVector(), MoveVector.X);
}

void AALSPlayerController::JumpHandle()
{
	ACharacter* PlayerCharacter = Cast<ACharacter>(GetPawn());
	if (!IsValid(PlayerCharacter))
	{
		return;
	}
	
	PlayerCharacter->Jump();
}

void AALSPlayerController::ChangeWeaponHandle(const FInputActionValue& Value)
{
	float WeaponType = Value.Get<float>();
	AALSCharacter* PlayerCharacter = Cast<AALSCharacter>(GetPawn());
	if (!IsValid(PlayerCharacter))
	{
		return;
	}
	
	PlayerCharacter->ChangeEquippedWeapon(WeaponType);
}
