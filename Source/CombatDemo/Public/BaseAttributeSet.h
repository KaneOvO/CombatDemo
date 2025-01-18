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

	
	void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
