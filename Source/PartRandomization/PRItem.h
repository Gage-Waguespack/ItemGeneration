// Fill out your copyright notice in the Description page of Project Settings.

//Next step is to reference the data asset and each part and to generate them.
//This being said, I should redo the loot pool in C++ and I will the be able to
//Generate everything in code.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "PRGunBases.h"
#include "PRGunParts.h"

#include "PRItem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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
	UBlueprint* currentBase;
	UPRGunBases* GunBases;
	UPRGunParts* GunParts;

public:

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Base")
	UPRGunBases* GenerateGunBase(int rarity);

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Reroll Base")
	void RerollGunBase();

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Gun Item")
	UPRGunParts* GenerateGunParts(int rarity);

	UFUNCTION(CallInEditor, BlueprintCallable, category = "PR Reroll Parts")
	void RerollGunParts();

private:
	//void PostEditChangeProperty(struct FPropertyChangedEvent& event) override;

};
