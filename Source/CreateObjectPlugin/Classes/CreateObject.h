//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2014 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "CreateObject.generated.h"

UCLASS(NotBlueprintable)
class UCreateObject : public UObject {
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (Keywords = "class name"), Category = Game)
	static UClass* GetClassByName(FString Name);
	
	UFUNCTION(BlueprintPure, meta = (Keywords = "new create object"), Category = Game)
	static UObject* CreateObjectFromClass(TSubclassOf<UObject> Class);
	
	UFUNCTION(BlueprintPure, meta = (Keywords = "new create object class name"), Category = Game)
	static UObject* CreateObjectFromClassName(FString Name);
};