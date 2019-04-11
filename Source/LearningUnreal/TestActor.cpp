// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

#include "Engine/Classes/Components/BoxComponent.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pBox = CreateDefaultSubobject<UStaticMeshComponent>(FName("PushBox"));
	RootComponent = m_pBox;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> pushBoxVisual(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube_Chamfer.1M_Cube_Chamfer'"));
	if (pushBoxVisual.Succeeded())
	{
		m_pBox->SetStaticMesh(pushBoxVisual.Object);
		m_pBox->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		m_pBox->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));
		m_pBox->SetWorldScale3D(FVector(1.0f));
	}

	m_pBoxCollider = CreateDefaultSubobject<UBoxComponent>(FName("PushBoxCollider"));
	m_pBoxCollider->AttachToComponent(m_pBox, FAttachmentTransformRules::KeepRelativeTransform);
	m_pBoxCollider->SetWorldScale3D(FVector(2.0f));

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

