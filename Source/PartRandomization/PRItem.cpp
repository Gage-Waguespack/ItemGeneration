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

void UPRItem::GenerateGunBase()
{
	CurrentGunBases.Empty();

	//Generate a random rarity between 1 and 4
	int RandomRarity = rand() % 4 + 1;

	//First I need to get the array of GunBases from the scriptable Object in Unreal
	for (int i = 0; i < GunBases->Bases.Num(); i++)
	{
		if (GunBases->Bases[i].Rarity == RandomRarity)
		{
			CurrentGunBases.Add(GunBases->Bases[i]);
		}
	}

	int ArrayLength = CurrentGunBases.Num();

	//Generate a random number
	int RandomGunBase = rand() % ArrayLength;

	//Next, just simply return a random base
	FinalGunBase = CurrentGunBases[RandomGunBase];
}

void UPRItem::GenerateGunParts()
{
	FinalGunBarrel = GenerateGunBarrel();
	FinalGunUnderBarrel = GenerateGunUnderBarrel();
	FinalGunMagazine = GenerateGunMag();
	FinalGunStock = GenerateGunStock();
}

FPRBarrels UPRItem::GenerateGunBarrel()
{
	CurrentGunBarrels.Empty();

	//Generate a random rarity between 1 and 4
	int RandomRarity = rand() % 4 + 1;

	for (int i = 0; i < GunParts->Barrels.Num(); i++)
	{
		if (GunParts->Barrels[i].Rarity == RandomRarity)
		{
			CurrentGunBarrels.Add(GunParts->Barrels[i]);
		}
	}

	int BarrelArrayLength = CurrentGunBarrels.Num();

	int RandomGunBarrel = rand() % BarrelArrayLength;

	return CurrentGunBarrels[RandomGunBarrel];
}

FPRUnderBarrels UPRItem::GenerateGunUnderBarrel()
{
	CurrentGunUnderBarrels.Empty();

	//Generate a random rarity between 1 and 4
	int RandomRarity = rand() % 4 + 1;

	//UnderBarrels
	for (int i = 0; i < GunParts->UnderBarrels.Num(); i++)
	{
		if (GunParts->UnderBarrels[i].Rarity == RandomRarity)
		{
			CurrentGunUnderBarrels.Add(GunParts->UnderBarrels[i]);
		}
	}

	int UnderBarrelArrayLength = CurrentGunUnderBarrels.Num();

	int RandomGunUnderBarrel = rand() % UnderBarrelArrayLength;

	return CurrentGunUnderBarrels[RandomGunUnderBarrel];
}

FPRMagazines UPRItem::GenerateGunMag()
{
	CurrentGunMagazines.Empty();

	//Generate a random rarity between 1 and 4
	int RandomRarity = rand() % 4 + 1;

	//Magazines
	for (int i = 0; i < GunParts->Mags.Num(); i++)
	{
		if (GunParts->Mags[i].Rarity == RandomRarity)
		{
			CurrentGunMagazines.Add(GunParts->Mags[i]);
		}
	}

	int MagArrayLength = CurrentGunMagazines.Num();

	int RandomGunMag = rand() % MagArrayLength;

	return CurrentGunMagazines[RandomGunMag];
}

FPRStocks UPRItem::GenerateGunStock()
{
	CurrentGunStocks.Empty();

	//Generate a random rarity between 1 and 4
	int RandomRarity = rand() % 4 + 1;

	for (int i = 0; i < GunParts->Stocks.Num(); i++)
	{
		if (GunParts->Stocks[i].Rarity == RandomRarity)
		{
			CurrentGunStocks.Add(GunParts->Stocks[i]);
		}
	}

	int StockArrayLength = CurrentGunStocks.Num();

	int RandomGunStock = rand() % StockArrayLength;

	return CurrentGunStocks[RandomGunStock];
}

void UPRItem::GenerateGunAccessories()
{
	CurrentGunAccessories.Empty();

	//Generate a random rarity between 1 and 4
	int RandomRarity = rand() % 4 + 1;

	for (int i = 0; i < GunAccessories->Accessories.Num(); i++)
	{
		if (GunAccessories->Accessories[i].Rarity == RandomRarity)
		{
			CurrentGunAccessories.Add(GunAccessories->Accessories[i]);
		}
	}

	int ArrayLength = CurrentGunAccessories.Num();

	int RandomAccessory = rand() % ArrayLength;

	FinalGunAccessory = CurrentGunAccessories[RandomAccessory];
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