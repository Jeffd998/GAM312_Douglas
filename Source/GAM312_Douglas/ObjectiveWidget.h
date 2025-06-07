// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectiveWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAM312_DOUGLAS_API UObjectiveWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatematObj(float matsCollected); //function to track and update materials for building

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatebuildObj(float objectsBuilt); //function to track and update objects built
};
