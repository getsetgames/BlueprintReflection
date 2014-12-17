//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2014 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "BlueprintReflectionFunctions.generated.h"

UCLASS(NotBlueprintable)
class UBlueprintReflectionFunctions : public UObject {
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (Keywords = "class name"), Category = Game)
	static UClass* GetClassByName(FString Name);
	
	UFUNCTION(BlueprintPure, meta = (Keywords = "new create object"), Category = Game)
	static UObject* ConstructObjectFromClass(TSubclassOf<UObject> Class);
	
	UFUNCTION(BlueprintPure, meta = (Keywords = "new create object class name"), Category = Game)
	static UObject* ConstructObjectFromClassName(FString Name);
};