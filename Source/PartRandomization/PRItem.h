// Fill out your copyright notice in the Description page of Project Settings.

//Next step is to reference the data asset and each part and to generate them.
//This being said, I should redo the loot pool in C++ and I will the be able to
//Generate everything in code.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Array.h"

#include "PRBases.h"
#include "PRGunParts.h"
#include "PRGunAccessories.h"

#include "PRItem.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PARTRANDOMIZATION_API UPRItem : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPRItem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	UPROPERTY(EditAnywhere, category = "PR Scriptable Objects")
		UPRBases* GunBases;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "PR Current Gun Selections")
		FPRBase FinalGunBase;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "PR Current Gun Selections")
		FPRBarrels FinalGunBarrel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "PR Current Gun Selections")
		FPRUnderBarrels FinalGunUnderBarrel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "PR Current Gun Selections")
		FPRMagazines FinalGunMagazine;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "PR Current Gun Selections")
		FPRStocks FinalGunStock;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "PR Current Gun Selections")
		FPRGunAccessory FinalGunAccessory;

	UPROPERTY(EditAnywhere, category = "PR Scriptable Objects")
		UPRGunParts* GunParts;

	UPROPERTY(EditAnywhere, category = "PR Scriptable Objects")
		UPRGunAccessories* GunAccessories;

	UPROPERTY(BlueprintReadOnly)
		TArray<FPRBase> CurrentGunBases;
	UPROPERTY(BlueprintReadOnly)
		TArray<FPRBarrels> CurrentGunBarrels;
	UPROPERTY(BlueprintReadOnly)
		TArray<FPRUnderBarrels> CurrentGunUnderBarrels;
	UPROPERTY(BlueprintReadOnly)
		TArray<FPRMagazines> CurrentGunMagazines;
	UPROPERTY(BlueprintReadOnly)
		TArray<FPRStocks> CurrentGunStocks;
	UPROPERTY(BlueprintReadOnly)
		TArray<FPRGunAccessory> CurrentGunAccessories;

public:
	int RandomRarity();

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun All Generation")
		void GenerateGun();

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Generate Base")
		void GenerateGunBase();

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Generate Parts")
		void GenerateGunParts();
	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Generate Parts")
		void RerollGunBarrel();
	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Generate Parts")
		void RerollGunUnderBarrel();
	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Generate Parts")
		void RerollGunMag();
	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Generate Parts")
		void RerollGunStock();

	FPRBarrels GenerateGunBarrel();
	FPRUnderBarrels GenerateGunUnderBarrel();
	FPRMagazines GenerateGunMag();
	FPRStocks GenerateGunStock();

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Generate Accessories")
		void GenerateGunAccessory();
};
