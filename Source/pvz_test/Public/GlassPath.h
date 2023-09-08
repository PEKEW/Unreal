// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GlassPath.generated.h"

UCLASS()
class PVZ_TEST_API AGlassPath : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;
	
public:	
	AGlassPath();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path")
	float OpenSpeed = 2.0f;



protected:
	virtual void BeginPlay() override;

public:	
	void Open(float ScaleFactor);

private:
	bool hasOpen = false;
	

};
