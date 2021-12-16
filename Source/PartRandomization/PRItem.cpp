// Fill out your copyright notice in the Description page of Project Settings.


#include "PRItem.h"

// Sets default values for this component's properties
UPRItem::UPRItem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPRItem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPRItem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UPRGunBases* UPRItem::GenerateGunBase(int rarity)
{
	//First I need to get the array of GunBases from the scriptable Object in Unreal

	//Then I need to get the loot pool of the the base

	//After this I need to grab a base with this loot pool

	//Once I find this base, I need to set it as the current base

	//Next, just simply return the current base
	return nullptr;
}

UPRGunBases* UPRItem::RerollGunBase()
{
	//First I need to call GenerateGunBase

	//The I need to set the current base to be the new generated base.

	//Finally I return the new current base
	return nullptr;
}

UPRGunParts* UPRItem::GenerateGunParts(int rarity)
{
	//First I need to get the array of GunParts from the scriptable Object in Unreal

	//Then I need to get the loot pool of the the parts

	//After this I need to randomly grab the parts with this loot pool

	//Once I find these parts, I need to set it as the current parts

	//Next, just simply return the current parts
	return nullptr;
}

UPRGunParts* UPRItem::RerollGunParts()
{
	//First I need to call GenerateGunParts

	//The I need to set the current parts to be the new generated parts.

	//Finally I return the new current parts
	return nullptr;
}

//#if WITH_EDITOR
//void UPRItem::PostEditChangeProperty(FPropertyChangedEvent& event)
//{
//	FName propertyName = (event.MemberProperty != NULL) ? event.MemberProperty->GetFName() : NAME_None;
//	if (propertyName == GET_MEMBER_NAME_CHECKED(UPRItem, "Variable"))
//	{
//		"Function";
//	}
//	else if (propertyName == GET_MEMBER_NAME_CHECKED("Class", "Variable"))
//	{
//		"Function";
//	}
//	else if (propertyName == GET_MEMBER_NAME_CHECKED("Class", "Variable"))
//	{
//		"Function";
//	}
//
//	Super::PostEditChangeProperty(event);
//}
//#endif