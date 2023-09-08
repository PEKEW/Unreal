// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Def.generated.h"

UCLASS()
class PVZ_TEST_API ADef : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADef();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	class UCameraComponent* FollowCamera;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
