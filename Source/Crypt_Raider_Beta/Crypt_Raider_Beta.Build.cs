// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Crypt_Raider_Beta : ModuleRules
{
	public Crypt_Raider_Beta(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
