// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Test.h"
#include "Abilities/GameplayAbility.h"
#include "Test_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API UTest_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UTest_GameplayAbility();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Ability")
	EGASAbilityInputID AbilityInputID = EGASAbilityInputID::None;
	
};
