// Fill out your copyright notice in the Description page of Project Settings.


#include "Def.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ADef::ADef()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject <USpringArmComponent>(TEXT("CameraBoom"));

	CameraBoom -> SetupAttachment(RootComponent);

	CameraBoom -> bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject <UCameraComponent>(TEXT("FollowCamera"));

	FollowCamera -> SetupAttachment(CameraBoom);


}

void ADef::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADef::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADef::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent -> BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent -> BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent -> BindAxis("MoveForward", this, &ADef::MoveForward);
	PlayerInputComponent -> BindAxis("MoveRight", this, &ADef::MoveRight);

	PlayerInputComponent -> BindAxis("Turn", this, &ADef::AddControllerYawInput);
	PlayerInputComponent -> BindAxis("LookUp", this, &ADef::AddControllerPitchInput);

}

void ADef::MoveForward(float AxisValue) {
	if ((Controller != NULL) && (AxisValue != 0.0f)) {
		const FRotator Rotation = Controller -> GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
	}
}

void ADef::MoveRight(float AxisValue) {
	if ((Controller != NULL) && (AxisValue != 0.0f)) {
		const FRotator Rotation = Controller -> GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, AxisValue);
	}
}

