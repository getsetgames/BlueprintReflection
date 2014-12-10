//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2014 Get Set Games Inc. All rights reserved.
//

#include "CreateObjectPluginPrivatePCH.h"

class FCreateObjectPlugin : public ICreateObjectPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{

	}

	virtual void ShutdownModule() override
	{

	}
};

IMPLEMENT_MODULE( FCreateObjectPlugin, CreateObjectPlugin )

DEFINE_LOG_CATEGORY(LogCreateObject);
