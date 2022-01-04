// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "Containers/Array.h"

#include "PRGunAccessories.generated.h"

USTRUCT(BlueprintType)
struct FPRGunAccessory
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Rarity = 0;
};

UCLASS()
class PARTRANDOMIZATION_API UPRGunAccessories : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Accessories", meta = (AllowPrivateAccess = "true", TitleProperty = "Name"))
		TArray<FPRGunAccessory> Accessories;
};