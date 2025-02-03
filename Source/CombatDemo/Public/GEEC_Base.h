// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GameplayTagContainer.h"
#include "GEEC_Base.generated.h"


/**
 * 
 */
UCLASS()
class COMBATDEMO_API UGEEC_Base : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UGEEC_Base();

protected:
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffect")
    TMap<FGameplayTag, float> DamageMultiplierMap;
	
};
