#include "GEEC_HP.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.h"

UGEEC_HP::UGEEC_HP()
{
}

void UGEEC_HP::Execute_Implementation(
    const FGameplayEffectCustomExecutionParameters &ExecutionParams,
    OUT FGameplayEffectCustomExecutionOutput &OutExecutionOutput) const
{
    UAbilitySystemComponent *TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
    if (!TargetASC)
        return;

    UAbilitySystemComponent *SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();

    FGameplayTagContainer TargetActiveTags;
    TargetASC->GetOwnedGameplayTags(TargetActiveTags);

    FGameplayTagContainer SourceActiveTags;
    if (SourceASC)
    {
        SourceASC->GetOwnedGameplayTags(SourceActiveTags);
    }

    float BaseDamage = 0.0f;
    const FGameplayEffectSpec &EffectSpec = ExecutionParams.GetOwningSpec();

    for (const FGameplayModifierInfo &Modifier : EffectSpec.Def->Modifiers)
    {
        if (Modifier.Attribute == UBaseAttributeSet::GetDamageAttribute())
        {
            float Magnitude = 0.0f;
            if (Modifier.ModifierMagnitude.GetStaticMagnitudeIfPossible(EffectSpec.GetLevel(), Magnitude))
            {
                BaseDamage = Magnitude;
            }
            break;
        }
    }

    float DamageMultiplier = 1.0f;

    for (const TPair<FGameplayTag, float> &Pair : DamageMultiplierMap)
    {
        if (TargetActiveTags.HasTag(Pair.Key) || SourceActiveTags.HasTag(Pair.Key))
        {
            DamageMultiplier *= Pair.Value;
        }
    }

    float FinalDamage = BaseDamage * DamageMultiplier;

    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(
        UBaseAttributeSet::GetHPAttribute(),
        EGameplayModOp::Additive,
        -FinalDamage));
    
    
}