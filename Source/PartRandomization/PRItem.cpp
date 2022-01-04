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

FPRGunBase UPRItem::GenerateGunBase(int rarity)
{
	CurrentGunBases.Empty();
	//UE_LOG(LogTemp, Log, TEXT("%s"))
	//First I need to get the array of GunBases from the scriptable Object in Unreal
	for (int i = 0; i < GunBases->Bases.Num(); i++)
	{
		if (GunBases->Bases[i].Rarity == rarity)
		{
			CurrentGunBases.Add(GunBases->Bases[i]);
		}
	}

	int ArrayLength = CurrentGunBases.Num();

	//Generate a random number
	int RandomGunBase = rand() % ArrayLength;

	//Next, just simply return a random base
	return CurrentGunBases[RandomGunBase];
}

void UPRItem::RerollGunBase()
{
	//Generate a random rarity between 1 and 4
	int RandomRarity = rand() % 4 + 1;

	//Call GenerateGunBase
	GenerateGunBase(RandomRarity);
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

void UPRItem::RerollGunParts()
{
	//Call GenerateGunParts
}

//This is the function that will hold information on the button to reroll GunBase or GunParts
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