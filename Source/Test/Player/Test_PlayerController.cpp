// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_PlayerController.h"

#include "GameFramework/Character.h"

ATest_PlayerController::ATest_PlayerController()
{
	
}

void ATest_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ATest_PlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATest_PlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &ATest_PlayerController::Turn);
	InputComponent->BindAxis("LookUp", this, &ATest_PlayerController::LookUp);

	InputComponent->BindAction("Jump",IE_Pressed, this, &ATest_PlayerController::Jump);
	InputComponent->BindAction("Jump",IE_Released, this, &ATest_PlayerController::StopJump);
	InputComponent->BindAction("Attack",IE_Pressed, this, &ATest_PlayerController::Attack);
	
}

void ATest_PlayerController::MoveForward(float value)
{
	if (value != 0.0f && GetPawn())
	{
		APawn* MyPawn = GetPawn();
		const FRotator PawnControlRotation = GetControlRotation();
		const FVector ForwardVector = FRotationMatrix(PawnControlRotation).GetScaledAxis(EAxis::X);
		MyPawn->AddMovementInput(ForwardVector, value);
	}
}

void ATest_PlayerController::MoveRight(float value)
{
	if (value != 0.0f && GetPawn())
	{
		APawn* MyPawn = GetPawn();
		const FRotator PawnControlRotation = GetControlRotation();
		const FVector RightVector = FRotationMatrix(PawnControlRotation).GetScaledAxis(EAxis::Y);
		MyPawn->AddMovementInput(RightVector, value);
	}
}

void ATest_PlayerController::Turn(float value)
{
	AddYawInput(value);
}

void ATest_PlayerController::LookUp(float value)
{
	AddPitchInput(value);
}

void ATest_PlayerController::Jump()
{
	if (GetPawn())
	{
		ACharacter* MyCharacter = Cast<ACharacter>(GetPawn());
		if (MyCharacter)
		{
			MyCharacter->Jump();
		}
	}
}

void ATest_PlayerController::StopJump()
{
	if (GetPawn())
	{
		ACharacter* MyCharacter = Cast<ACharacter>(GetPawn());
		if (MyCharacter)
		{
			MyCharacter->StopJumping();
		}
	}
}

void ATest_PlayerController::Attack()
{
}
