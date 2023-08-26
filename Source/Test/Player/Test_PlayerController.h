// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Test_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API ATest_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ATest_PlayerController();

protected:

	virtual void SetupInputComponent() override;

	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void LookUp(float value);

	void Jump();
	void StopJump();

	void Attack();
};
