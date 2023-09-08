

#include "GlassPath.h"

AGlassPath::AGlassPath()
{
	PrimaryActorTick.bCanEverTick = true;


	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded()){
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AGlassPath::BeginPlay(){
	Super::BeginPlay();
}


void AGlassPath::Open(float ScaleFactor) {
	FVector CurrentScale = GetActorScale3D();
	FVector NewScale = FVector(CurrentScale.X, CurrentScale.Y * ScaleFactor, CurrentScale.Z);
	SetActorScale3D(NewScale);
}
