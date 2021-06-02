using UnrealBuildTool;
using System.Collections.Generic;

public class AP_CourseworkEditorTarget : TargetRules{
	public AP_CourseworkEditorTarget( TargetInfo Target) : base(Target){
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "AP_Coursework" } );
	}
}
