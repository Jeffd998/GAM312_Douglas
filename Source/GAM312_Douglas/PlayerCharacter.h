// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Resource_M.h"
#include "Kismet/GameplayStatics.h"
#include "BuildingPart.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class GAM312_DOUGLAS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float axisvalue);
	
	UFUNCTION()
	void MoveRight(float axisvalue);

	UFUNCTION()
	void StartJump();
	
	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void Interact();

	UFUNCTION()
	void FindObject();


	UPROPERTY(VisibleAnywhere)
	UCameraComponent* PlayerCamComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float Health = 100.0f; //default player health

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float Hunger = 100.0f; //default player hunger

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float Stamina = 100.0f; //default player stamina


	UFUNCTION(BlueprintCallable)
	void SetHealth(float amount); //set health function

	UFUNCTION(BlueprintCallable)
	void SetHunger(float amount); //set hunger function

	UFUNCTION(BlueprintCallable)
	void SetStamina(float amount); //set stamina function

	UPROPERTY(EditAnywhere, Category = "Resources")
	int Wood;  //wood property

	UPROPERTY(EditAnywhere, Category = "Resources")
	int Stone; //stone property

	UPROPERTY(EditAnywhere, Category = "Resources")
	int Berry; //berry property

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	TArray<int> ResourcesArray; //Array for resource to set them to an array int

	UPROPERTY(EditAnywhere, Category = "Resources")
	TArray<FString> ResourcesNameArray; //array for resources to set the name to the array int

	UPROPERTY(EditAnywhere, Category = "HitMarker")
	UMaterialInterface* hitDecal; //visual hit feedback for line trace

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Supplies")
	TArray<int> BuildingArray;

	UPROPERTY()
	bool isBuilding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ABuildingPart> BuildPartClass;

	UPROPERTY()
	ABuildingPart* SpawnedPart;
	

	UFUNCTION()
	void DecreaseStats(); //decrease stats function

	UFUNCTION()
	void GiveResource(float amount, FString resourceType); //give resources function

	UFUNCTION(BlueprintCallable)
	void UpdateResources(float woodAmount, float stoneAmount, FString buildingObject);

	UFUNCTION(BlueprintCallable)
	void SpawnBuilding(int buildingID, bool& isSuccess);

	UFUNCTION()
	void RotateBuilding();






};
