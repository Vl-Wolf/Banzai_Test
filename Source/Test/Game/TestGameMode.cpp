// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestGameMode.h"
#include "Test/Player/TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestGameMode::ATestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprint/Player/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
