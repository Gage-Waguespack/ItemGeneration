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
struct FPRBarrelsViewOnly
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		FString Name = "";

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		UMeshComponent* Mesh;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		int Rarity = 0;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		int BulletCount = 0;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		int BulletSpread = 0;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		int DamageModifier = 0;
};

USTRUCT(BlueprintType)
struct FPRUnderBarrels
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Rarity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ADSTime = 0;
};

USTRUCT(BlueprintType)
struct FPRUnderBarrelsViewOnly
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		FString Name = "";

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		UMeshComponent* Mesh;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		int Rarity = 0;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
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
struct FPRMagazinesViewOnly
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		FString Name = "";

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		UMeshComponent* Mesh;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		int Rarity = 0;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		int AmmoConsumption = 0;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
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

USTRUCT(BlueprintType)
struct FPRStocksViewOnly
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		FString Name = "";

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		UMeshComponent* Mesh;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		int Rarity = 0;

	UPROPERTY(VisableAnywhere, BlueprintReadOnly)
		int RecoilReduction = 0;
};

UCLASS()
class PARTRANDOMIZATION_API UPRGunParts : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Gun Parts")
		TArray<FPRBarrels> Barrels;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Gun Parts")
		TArray<FPRUnderBarrels> UnderBarrels;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Gun Parts")
		TArray<FPRMagazines> Mags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Gun Parts")
		TArray<FPRStocks> Stocks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Gun Parts View Only")
		TArray<FPRBarrelsViewOnly> BarrelsViewOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Gun Parts View Only")
		TArray<FPRUnderBarrelsViewOnly> UnderBarrelsViewOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Gun Parts View Only")
		TArray<FPRMagazinesViewOnly> MagsViewOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Gun Parts View Only")
		TArray<FPRStocksViewOnly> StocksViewOnly;
};
