// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) \

/**
 * 
 */
UCLASS()
class COMBATDEMO_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData HP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, HP);


	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxHP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHP);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData SkillCounts;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, SkillCounts);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxSkillCounts;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxSkillCounts);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData SkillRecoverTimer;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, SkillRecoverTimer);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData SP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, SP);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxSP;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxSP);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData StunValue;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, StunValue);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxStunValue;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxStunValue);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData StunRecoverTime;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, StunRecoverTime);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData DefenseCD;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, DefenseCD);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData PerfectSprintCD;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, PerfectSprintCD);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData PerfectSprintGain;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, PerfectSprintGain);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData DashCount;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, DashCount);

	UPROPERTY(BlueprintReadOnly, Category = "BaseAttributeSet")
	FGameplayAttributeData MaxDashCount;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxDashCount);
	
	
	
	void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
