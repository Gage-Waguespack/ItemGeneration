// Fill out your copyright notice in the Description page of Project Settings.

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
	UFUNCTION(BlueprintCallable, Category = "PRItem")
	UPRGunBases* GenerateGunBase(int rarity);
	UPRGunBases* RerollGunBase();
	UFUNCTION(BlueprintCallable, Category = "PRItem")
	UPRGunParts* GenerateGunParts(int rarity);
	UPRGunParts* RerollGunParts();

private:
	//void PostEditChangeProperty(struct FPropertyChangedEvent& event) override;

};
