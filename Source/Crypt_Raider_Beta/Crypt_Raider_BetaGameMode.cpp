// Copyright Epic Games, Inc. All Rights Reserved.

#include "Crypt_Raider_BetaGameMode.h"
#include "Crypt_Raider_BetaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACrypt_Raider_BetaGameMode::ACrypt_Raider_BetaGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
