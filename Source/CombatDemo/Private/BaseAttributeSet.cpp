// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAttributeSet.h"
#include "GameplayEffectExtension.h"

void UBaseAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData &Data)
{
    Super::PostGameplayEffectExecute(Data);

    if(Data.EvaluatedData.Attribute == GetHPAttribute())
    {
        SetHP(FMath::Clamp(GetHP(), 0.0f, GetMaxHP()));
    }

    if(Data.EvaluatedData.Attribute == GetSPAttribute())
    {
        SetSP(FMath::Clamp(GetSP(), 0.0f, GetMaxSP()));
    }

    if(Data.EvaluatedData.Attribute == GetSkillCountsAttribute())
    {
        SetSkillCounts(FMath::Clamp(GetSkillCounts(), 0.0f, GetMaxSkillCounts()));
    }

    if(Data.EvaluatedData.Attribute == GetStunValueAttribute())
    {
        SetStunValue(FMath::Clamp(GetStunValue(), 0.0f, GetMaxStunValue()));
    }

    if(Data.EvaluatedData.Attribute == GetDashCountAttribute())
    {
        SetDashCount(FMath::Clamp(GetDashCount(), 0.0f, GetMaxDashCount()));
    }
    
        

    
}
