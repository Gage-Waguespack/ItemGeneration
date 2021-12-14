// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "Containers/Array.h"

#include "PRGunParts.generated.h"

USTRUCT(BlueprintType)
struct FPRBarrels
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Rarity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BulletCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BulletSpread = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int DamageModifier = 0;
};

USTRUCT(BlueprintType)
struct FPRUnderBarrels
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Rarity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ADSTime = 0;
};

USTRUCT(BlueprintType)
struct FPRMagazines
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Rarity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int AmmoConsumption = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MagSize = 0;
};

USTRUCT(BlueprintType)
struct FPRStocks
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Rarity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int RecoilReduction = 0;
};

UCLASS()
class PARTRANDOMIZATION_API UPRGunParts : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Mags")
		TArray<FPRBarrels> Barrels;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Mags")
		TArray<FPRUnderBarrels> UnderBarrels;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Mags")
		TArray<FPRMagazines> Mags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Mags")
		TArray<FPRStocks> Stocks;
};
