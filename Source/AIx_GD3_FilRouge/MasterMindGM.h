// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/DelegateCombinations.h" //  Pour les macros de délégation
#include "MasterMindGM.generated.h"

//  Déclaration propre de l'événement
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSolutionChecked, uint8, GoodPlaces, uint8, WrongPlaces);

UCLASS()
class MONMASTERMINF_API AMasterMindGM : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMasterMindGM();

	//  Événement diffusé à la fin d'une vérif de solution
	UPROPERTY(BlueprintAssignable)
	FOnSolutionChecked OnSolutionChecked;

	//  Couleurs possibles (modifiable dans l'éditeur ou en BP)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TArray<FLinearColor> Colors{
		FLinearColor::Red,
		FLinearColor::Yellow,
		FLinearColor::Green,
		FLinearColor::Blue,
		FLinearColor::Gray,
		FLinearColor::White
	};

	//  Solution générée (indices de couleurs, ex: [0, 3, 2, 1])
	UPROPERTY(EditAnywhere)
	TArray<uint8> Solution;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//  Récupère une couleur selon son index
	UFUNCTION()
	FLinearColor GetColor(uint8 ColorNumber);

	//  Crée une solution aléatoire (appelée au BeginPlay)
	UFUNCTION()
	void CreateSolution();

	//  Compare la réponse du joueur avec la solution
	UFUNCTION(BlueprintCallable)
	bool CheckAnswer(TArray<uint8> Answer);
};
