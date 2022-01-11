// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PARTRANDOMIZATION_API LootPool
{
public:
	LootPool();
	~LootPool();

public:
	int RandomNumber();
	enum rarity {common=1, rare, legendary, exotic};
};
