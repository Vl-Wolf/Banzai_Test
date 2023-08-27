// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Test/Ability/Test_AbilitySystemComponent.h"
#include "Test/Player/Test_PlayerController.h"


//////////////////////////////////////////////////////////////////////////
// ATestCharacter

ATestCharacter::ATestCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	
	AbilitySystemComponent = CreateDefaultSubobject<UTest_AbilitySystemComponent>(TEXT("AbilitySystem"));
}

UAbilitySystemComponent* ATestCharacter::GetAbilitySystemComponent() const
{
	return  AbilitySystemComponent;
}

void ATestCharacter::InitDefaultAbility()
{
	if (DefaultAbility)
	{
		int32 InputID = static_cast<int32>(DefaultAbility.GetDefaultObject()->AbilityInputID);
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(DefaultAbility, 1, InputID, this));
	}
}

void ATestCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	InitDefaultAbility();
	
}

void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	
	APlayerController* MyPlayerController = Cast<APlayerController>(GetController());
	if (MyPlayerController)
	{
		if (AbilitySystemComponent && InputComponent)
		{
			const FGameplayAbilityInputBinds InputBinds
			(
				"Confirm",
				"Cancel",
				"EGASAbilityInputID",
				static_cast<int32>(EGASAbilityInputID::Confirm),
				static_cast<int32>(EGASAbilityInputID::Cancel)
			);

			AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, InputBinds);
		}	
	}
}
