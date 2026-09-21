// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EXTDS : ModuleRules
{
	public EXTDS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"EXTDS",
			"EXTDS/Variant_Platforming",
			"EXTDS/Variant_Platforming/Animation",
			"EXTDS/Variant_Combat",
			"EXTDS/Variant_Combat/AI",
			"EXTDS/Variant_Combat/Animation",
			"EXTDS/Variant_Combat/Gameplay",
			"EXTDS/Variant_Combat/Interfaces",
			"EXTDS/Variant_Combat/UI",
			"EXTDS/Variant_SideScrolling",
			"EXTDS/Variant_SideScrolling/AI",
			"EXTDS/Variant_SideScrolling/Gameplay",
			"EXTDS/Variant_SideScrolling/Interfaces",
			"EXTDS/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
