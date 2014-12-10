//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2014 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "EdGraph/EdGraphNode.h"
#include "EdGraph/EdGraphSchema.h"
#include "CreateObject.generated.h"

UCLASS()
class UCreateObject : public UEdGraphNode
{
	GENERATED_UCLASS_BODY()
 
	UFUNCTION(BlueprintCallable, meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "new create object"), Category = Game)
	static UObject* CreateObject(UObject* WorldContextObject, TSubclassOf<UObject> Class);
};