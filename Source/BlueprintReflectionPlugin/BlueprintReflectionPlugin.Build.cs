//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2014 Get Set Games Inc. All rights reserved.
//

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class BlueprintReflectionPlugin : ModuleRules
	{
        private string ModulePath
        {
            get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
        }

        private string ThirdPartyPath
        {
            get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
        }

		public BlueprintReflectionPlugin(TargetInfo Target)
		{
			PrivateIncludePaths.AddRange(
				new string[] {
					"BlueprintReflectionPlugin/Private",
				});

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine"
				});
		}
	}
}