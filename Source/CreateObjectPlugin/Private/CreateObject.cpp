//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2014 Get Set Games Inc. All rights reserved.
//

#include "CreateObjectPluginPrivatePCH.h"

UObject* UCreateObject::CreateObject(UObject* WorldContextObject, TSubclassOf<UObject> Class)
{
	return StaticConstructObject(Class);
}