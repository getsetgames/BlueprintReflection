//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2014 Get Set Games Inc. All rights reserved.
//

#include "BlueprintReflectionPluginPrivatePCH.h"
#include "AssetRegistryModule.h"

UClass* UBlueprintReflectionFunctions::GetClassByNameImpl(FString Name) {
	if (UClass* result = FindObject<UClass>(ANY_PACKAGE, *Name)) {
		return result;
	}
	
	if (UObjectRedirector* RenamedClassRedirector = FindObject<UObjectRedirector>(ANY_PACKAGE, *Name)) {
		return CastChecked<UClass>(RenamedClassRedirector->DestinationObject);
	}
	
	return nullptr;
}

UClass* UBlueprintReflectionFunctions::GetClassByName(FString Name) {
	if (UClass *result = UBlueprintReflectionFunctions::GetClassByNameImpl(Name)) {
		return result;
	}
	
	FString BlueprintName = FString::Printf(TEXT("%s_C"),*Name);

	if (UClass *result = UBlueprintReflectionFunctions::GetClassByNameImpl(BlueprintName)) {
		return result;
	}
	
	UE_LOG(LogBlueprintReflection, Log, TEXT("Could not find class in memory, searching asset registry for class: %s"), *Name);

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(FName("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
	
	TArray<FAssetData> AssetList;
	FARFilter AssetFilter;
	AssetFilter.ClassNames.Add(UBlueprint::StaticClass()->GetFName());
	AssetRegistry.GetAssets(AssetFilter, AssetList);
	
	for (auto Itr(AssetList.CreateIterator()); Itr; Itr++)
	{
		if (Itr->AssetName.ToString().Equals(Name)) {
			if (UClass* result = LoadObject<UClass>(nullptr, *Itr->ObjectPath.ToString())) {
				return result;
			}
			
			if (UClass *result = UBlueprintReflectionFunctions::GetClassByNameImpl(BlueprintName)) {
				return result;
			}
		}
	}

	return nullptr;
}

UObject* UBlueprintReflectionFunctions::ConstructObjectFromClass(TSubclassOf<UObject> Class) {
	if (Class) {
		return StaticConstructObject_Internal(Class);
	}
	
	return nullptr;
}

UObject* UBlueprintReflectionFunctions::ConstructObjectFromClassName(FString Name) {
	return UBlueprintReflectionFunctions::ConstructObjectFromClass(UBlueprintReflectionFunctions::GetClassByName(Name));
}