// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/DelegateCombinations.h" //  Pour les macros de d�l�gation
#include "MasterMindGM.generated.h"

//  D�claration propre de l'�v�nement
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSolutionChecked, uint8, GoodPlaces, uint8, WrongPlaces);

UCLASS()
class MONMASTERMINF_API AMasterMindGM : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMasterMindGM();

	//  �v�nement diffus� � la fin d'une v�rif de solution
	UPROPERTY(BlueprintAssignable)
	FOnSolutionChecked OnSolutionChecked;

	//  Couleurs possibles (modifiable dans l'�diteur ou en BP)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TArray<FLinearColor> Colors{
		FLinearColor::Red,
		FLinearColor::Yellow,
		FLinearColor::Green,
		FLinearColor::Blue,
		FLinearColor::Gray,
		FLinearColor::White
	};

	//  Solution g�n�r�e (indices de couleurs, ex: [0, 3, 2, 1])
	UPROPERTY(EditAnywhere)
	TArray<uint8> Solution;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//  R�cup�re une couleur selon son index
	UFUNCTION()
	FLinearColor GetColor(uint8 ColorNumber);

	//  Cr�e une solution al�atoire (appel�e au BeginPlay)
	UFUNCTION()
	void CreateSolution();

	//  Compare la r�ponse du joueur avec la solution
	UFUNCTION(BlueprintCallable)
	bool CheckAnswer(TArray<uint8> Answer);
};
