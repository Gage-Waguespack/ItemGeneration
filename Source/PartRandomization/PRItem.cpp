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

int UPRItem::RandomRarity()
{
	int CurrentRarity = 0;

	int randomNum = rand() % 100 + 1;

	if (randomNum <= 5)
	{
		return 4;
	}
	else if (randomNum <= 25)
	{
		return 3;
	}
	else if (randomNum <= 50)
	{
		return 2;
	}
	else if (randomNum <= 100)
	{
		return 1;
	}

	return 5;
}

void UPRItem::GenerateGun()
{
	GenerateGunBase();
	GenerateGunParts();
	GenerateGunAccessory();
}
void UPRItem::GenerateGunBase()
{
	//Sets the CurrentGunBases array to empty to reset it every time this function is used
	CurrentGunBases.Empty();

	//Generate a random rarity between 1 and 4
	int RandRarity = RandomRarity();

	//Step through all of the bases
	for (int i = 0; i < GunBases->Bases.Num(); i++)
	{
		//Check if the bases rarity equals the random rarity
		if (GunBases->Bases[i].Rarity == RandRarity)
		{
			//Add the bases with the same rarity to a separate array
			CurrentGunBases.Add(GunBases->Bases[i]);
		}
	}

	//Set the array length to be the length of the current array
	int ArrayLength = CurrentGunBases.Num();

	//Generate a random number
	int RandomGunBase = rand() % ArrayLength;

	//Next, just simply return a random base
	FinalGunBase = CurrentGunBases[RandomGunBase];
}

void UPRItem::GenerateGunParts()
{
	//Generate all of the gun parts by setting them all in this function
	FinalGunBarrel = GenerateGunBarrel();
	FinalGunUnderBarrel = GenerateGunUnderBarrel();
	FinalGunMagazine = GenerateGunMag();
	FinalGunStock = GenerateGunStock();
}

void UPRItem::RerollGunBarrel()
{
	FinalGunBarrel = GenerateGunBarrel();
}

void UPRItem::RerollGunUnderBarrel()
{
	FinalGunUnderBarrel = GenerateGunUnderBarrel();
}

void UPRItem::RerollGunMag()
{
	FinalGunMagazine = GenerateGunMag();
}

void UPRItem::RerollGunStock()
{
	FinalGunStock = GenerateGunStock();
}

FPRBarrels UPRItem::GenerateGunBarrel()
{
	//Sets the CurrentGunBarrels array to empty to reset it every time this function is used
	CurrentGunBarrels.Empty();

	//Generate a random rarity between 1 and 4
	int RandRarity = RandomRarity();

	//Step through all of the barrels
	for (int i = 0; i < GunParts->Barrels.Num(); i++)
	{
		//Check if the barrels rarity equals the random rarity
		if (GunParts->Barrels[i].Rarity == RandRarity)
		{
			//Add the barrels with the same rarity to a separate array
			CurrentGunBarrels.Add(GunParts->Barrels[i]);
		}
	}

	//Set the array length to be the length of the current array
	int BarrelArrayLength = CurrentGunBarrels.Num();

	//Generate a random number
	int RandomGunBarrel = rand() % BarrelArrayLength;

	//Next, just simply return a random barrel
	return CurrentGunBarrels[RandomGunBarrel];
}

FPRUnderBarrels UPRItem::GenerateGunUnderBarrel()
{
	//Sets the CurrentGunUnderBarrels array to empty to reset it every time this function is used
	CurrentGunUnderBarrels.Empty();

	//Generate a random rarity between 1 and 4
	int RandRarity = RandomRarity();

	//Step through all of the underbarrels
	for (int i = 0; i < GunParts->UnderBarrels.Num(); i++)
	{
		//Check if the underbarrels rarity equals the random rarity
		if (GunParts->UnderBarrels[i].Rarity == RandRarity)
		{
			//Add the underbarrels with the same rarity to a separate rarity
			CurrentGunUnderBarrels.Add(GunParts->UnderBarrels[i]);
		}
	}

	//Set the array length to be the length of the current array
	int UnderBarrelArrayLength = CurrentGunUnderBarrels.Num();

	//Generate a random number
	int RandomGunUnderBarrel = rand() % UnderBarrelArrayLength;

	//Return a random underbarrel
	return CurrentGunUnderBarrels[RandomGunUnderBarrel];
}

FPRMagazines UPRItem::GenerateGunMag()
{
	//Sets the CurrentGunMagazines array to empty to reset it every time this function is used
	CurrentGunMagazines.Empty();

	//Generate a random rarity between 1 and 4
	int RandRarity = RandomRarity();

	//Step through all of the mags
	for (int i = 0; i < GunParts->Mags.Num(); i++)
	{
		//Check if the mags rarity equals the random rarity
		if (GunParts->Mags[i].Rarity == RandRarity)
		{
			//Add the mags with the same rarity to a separate array
			CurrentGunMagazines.Add(GunParts->Mags[i]);
		}
	}

	//Set the array length to be the length of the current array
	int MagArrayLength = CurrentGunMagazines.Num();

	//Generate a random number
	int RandomGunMag = rand() % MagArrayLength;

	//Return a random mag
	return CurrentGunMagazines[RandomGunMag];
}

FPRStocks UPRItem::GenerateGunStock()
{
	//Sets the CurrentGunStocks array to empty to reset it every time this function is used
	CurrentGunStocks.Empty();

	//Generate a random rarity between 1 and 4
	int RandomRarity = rand() % 4 + 1;

	//Step through all of the stocks
	for (int i = 0; i < GunParts->Stocks.Num(); i++)
	{
		//Check if the stocks' rarity equals the random rarity
		if (GunParts->Stocks[i].Rarity == RandomRarity)
		{
			//Add the stocks with the same rarity to a separate array
			CurrentGunStocks.Add(GunParts->Stocks[i]);
		}
	}

	//Set the array length to be the length of the current array
	int StockArrayLength = CurrentGunStocks.Num();

	//Generate a random number
	int RandomGunStock = rand() % StockArrayLength;

	//Return a random stock
	return CurrentGunStocks[RandomGunStock];
}

void UPRItem::GenerateGunAccessory()
{
	//Sets the CurrentGunAccessories array to empty to reset it every time this function is used
	CurrentGunAccessories.Empty();

	//Generate a random rarity between 1 and 4
	int RandRarity = RandomRarity();

	//Step through all of the bases
	for (int i = 0; i < GunAccessories->Accessories.Num(); i++)
	{
		//Check if the accessories rarity equals the random rarity
		if (GunAccessories->Accessories[i].Rarity == RandRarity)
		{
			//Add the accessories with the same rarity to a separate array
			CurrentGunAccessories.Add(GunAccessories->Accessories[i]);
		}
	}

	//Set the array length to be the length of the current array
	int ArrayLength = CurrentGunAccessories.Num();

	//Generate a random number
	int RandomAccessory = rand() % ArrayLength;

	//Return a random base
	FinalGunAccessory = CurrentGunAccessories[RandomAccessory];
}
