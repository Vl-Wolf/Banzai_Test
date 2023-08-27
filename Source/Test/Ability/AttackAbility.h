// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Test/Test.h"
#include "AttackAbility.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API UAttackAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	
	UAttackAbility();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ability")
	EGASAbilityInputID AbilityInputID = EGASAbilityInputID::None;
		
};
