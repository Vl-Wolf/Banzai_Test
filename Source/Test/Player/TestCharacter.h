// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Test/Ability/AttackAbility.h"
#include "Test/Ability/Test_AbilitySystemComponent.h"
#include "TestCharacter.generated.h"


UCLASS(config=Game)
class ATestCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=AbilitySystem, meta = (AllowPrivateAccess = "true"))
	UTest_AbilitySystemComponent* AbilitySystemComponent;


public:
	ATestCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void InitDefaultAbility();

	UPROPERTY(EditDefaultsOnly, Category="GameplayAbility")
	TSubclassOf<UAttackAbility> DefaultAbility;
	
protected:
		
	// To add mapping context
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ability")
	TArray<UAnimMontage*> AttackAnim;

public:
	
	/** Returns CameraBoom subobject **/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

