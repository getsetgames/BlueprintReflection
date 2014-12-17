//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2014 Get Set Games Inc. All rights reserved.
//

#include "BlueprintReflectionPluginPrivatePCH.h"

class FBlueprintReflectionPlugin : public IBlueprintReflectionPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{

	}

	virtual void ShutdownModule() override
	{

	}
};

IMPLEMENT_MODULE( FBlueprintReflectionPlugin, BlueprintReflectionPlugin )

DEFINE_LOG_CATEGORY(LogBlueprintReflection);
