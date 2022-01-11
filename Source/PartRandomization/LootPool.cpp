// Fill out your copyright notice in the Description page of Project Settings.


#include "LootPool.h"

LootPool::LootPool()
{
}

LootPool::~LootPool()
{
}

int LootPool::RandomNumber()
{
	int CurrentRarity = 0;

	int randomNum = rand() % 100 + 1;

	if (randomNum <= 5)
	{
		CurrentRarity = exotic;
	}
	else if (randomNum <= 15)
	{
		CurrentRarity = legendary;
	}
	else if (randomNum <= 25)
	{
		CurrentRarity = rare;
	}
	else if (randomNum <= 55)
	{
		CurrentRarity = common;
	}

	return CurrentRarity;
}
