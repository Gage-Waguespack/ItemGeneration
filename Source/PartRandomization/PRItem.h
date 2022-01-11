// Fill out your copyright notice in the Description page of Project Settings.

//Next step is to reference the data asset and each part and to generate them.
//This being said, I should redo the loot pool in C++ and I will the be able to
//Generate everything in code.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Array.h"

#include "PRGunBases.h"
#include "PRGunParts.h"
#include "PRGunAccessories.h"

#include "PRItem.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
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
	UPROPERTY(EditAnywhere)
	UPRGunBases* GunBases;

	UPROPERTY(VisibleAnywhere)
	FPRGunBase FinalGunBase;

	UPROPERTY(VisibleAnywhere)
	FPRBarrels FinalGunBarrel;

	UPROPERTY(VisibleAnywhere)
	FPRUnderBarrels FinalGunUnderBarrel;

	UPROPERTY(VisibleAnywhere)
	FPRMagazines FinalGunMagazine;

	UPROPERTY(VisibleAnywhere)
	FPRStocks FinalGunStock;

	UPROPERTY(VisibleAnywhere)
	FPRGunAccessory FinalGunAccessory;

	UPROPERTY(EditAnywhere)
	UPRGunParts* GunParts;

	UPROPERTY(EditAnywhere)
	UPRGunAccessories* GunAccessories;

	UPRGunBases* DAGunBases;

	TArray<FPRGunBase> CurrentGunBases;
	TArray<FPRBarrels> CurrentGunBarrels;
	TArray<FPRUnderBarrels> CurrentGunUnderBarrels;
	TArray<FPRMagazines> CurrentGunMagazines;
	TArray<FPRStocks> CurrentGunStocks;
	TArray<FPRGunAccessory> CurrentGunAccessories;


public:

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Base")
	void GenerateGunBase();

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Parts")
	void GenerateGunParts();

	FPRBarrels GenerateGunBarrel();
	FPRUnderBarrels GenerateGunUnderBarrel();
	FPRMagazines GenerateGunMag();
	FPRStocks GenerateGunStock();

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Accessories")
	void GenerateGunAccessories();

private:
	//void PostEditChangeProperty(struct FPropertyChangedEvent& event) override;

};
