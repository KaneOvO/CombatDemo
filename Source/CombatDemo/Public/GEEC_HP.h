// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GameplayTagContainer.h"
#include "GEEC_HP.generated.h"


/**
 * 
 */
UCLASS()
class COMBATDEMO_API UGEEC_HP : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UGEEC_HP();

protected:
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GameplayEffect")
    TMap<FGameplayTag, float> DamageMultiplierMap;
	
};