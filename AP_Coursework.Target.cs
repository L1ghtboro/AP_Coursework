using UnrealBuildTool;
using System.Collections.Generic;

public class AP_CourseworkTarget : TargetRules{
	public AP_CourseworkTarget( TargetInfo Target) : base(Target){
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "AP_Coursework" } );
	}
}
