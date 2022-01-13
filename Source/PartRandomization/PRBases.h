// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "Containers/Array.h"

#include "PRBases.generated.h"

USTRUCT(BlueprintType)
struct FPRBase
{
	GENERATED_USTRUCT_BODY()

public:
	FPRBase() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Rarity = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UMeshComponent* Mesh;
};

UCLASS()
class PARTRANDOMIZATION_API UPRBases : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "PR Bases", meta = (AllowPrivateAccess = "true", TitleProperty = "Name"))
		TArray<FPRBase> Bases;
};
