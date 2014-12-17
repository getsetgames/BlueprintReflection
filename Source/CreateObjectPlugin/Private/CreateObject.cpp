//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2014 Get Set Games Inc. All rights reserved.
//

#include "CreateObjectPluginPrivatePCH.h"

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

UObject* UCreateObject::CreateObjectFromClass(TSubclassOf<UObject> Class) {
	if (Class) {
		return StaticConstructObject(Class);
	}
	
	return nullptr;
}

UObject* UCreateObject::CreateObjectFromClassName(FString Name) {
	return UCreateObject::CreateObjectFromClass(UCreateObject::GetClassByName(Name));
}