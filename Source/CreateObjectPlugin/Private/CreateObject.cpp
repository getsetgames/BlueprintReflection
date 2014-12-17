//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2014 Get Set Games Inc. All rights reserved.
//

#include "CreateObjectPluginPrivatePCH.h"

UObject* UCreateObject::CreateObject(TSubclassOf<UObject> Class) {
	if (Class) {
		return StaticConstructObject(Class);
	}
	
	return nullptr;
}

UClass* UCreateObject::GetClassByName(FString Name) {
	UObject* ClassPackage = ANY_PACKAGE;
	
	if (UClass* result = FindObject<UClass>(ClassPackage, *Name)) {
		return result;
	}
	
	if (UObjectRedirector* RenamedClassRedirector = FindObject<UObjectRedirector>(ClassPackage, *Name)) {
		return CastChecked<UClass>(RenamedClassRedirector->DestinationObject);
	}
	
	return nullptr;
}