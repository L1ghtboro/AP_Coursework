using UnrealBuildTool;

public class AP_Coursework : ModuleRules{
	public AP_Coursework(ReadOnlyTargetRules Target) : base(Target){
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		//PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AIModule", "GameplayTasks" });
		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
