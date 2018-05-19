#pragma once

template <class T>
void EQAPP_LoadOption(T& option, const char* optionName, boost::property_tree::ptree& pt);
void EQAPP_LoadOptions();

template <class T>
void EQAPP_LoadOption(T& option, const char* optionName, boost::property_tree::ptree& pt)
{
    std::stringstream ssOptionName;
    ssOptionName << "Options." << optionName;

    boost::optional<T> result = pt.get_optional<T>(ssOptionName.str().c_str());
    if (result)
    {
        option = result.get();

        std::stringstream ssDebugText;
        ssDebugText << optionName << "=" << option;

        EQAPP_PrintDebugText(__FUNCTION__, ssDebugText.str().c_str());
    }
}

void EQAPP_LoadOptions()
{
    std::stringstream ssFileName;
    ssFileName << g_EQAppName << ".ini";

    boost::property_tree::ptree pt;
    boost::property_tree::read_ini(ssFileName.str().c_str(), pt);

    EQAPP_LoadOption<bool>(g_AlwaysAttackIsEnabled, "bAlwaysAttack", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_AlwaysAttackTimerInterval, "iAlwaysAttackTimerInterval", pt);
    EQAPP_LoadOption<float>(g_AlwaysAttackDistance, "fAlwaysAttackDistance", pt);

    EQAPP_LoadOption<bool>(g_AlwaysHotButtonIsEnabled, "bAlwaysHotButton", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_AlwaysHotButtonTimerInterval, "iAlwaysHotButtonTimerInterval", pt);
    EQAPP_LoadOption<signed int>(g_AlwaysHotButtonIndex, "iAlwaysHotButtonIndex", pt);

    EQAPP_LoadOption<bool>(g_AutoAlternateAbilityIsEnabled, "bAutoAlternateAbility", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_AutoAlternateAbilityTimerInterval, "iAutoAlternateAbilityTimerInterval", pt);

    EQAPP_LoadOption<bool>(g_AutoGroupIsEnabled, "bAutoGroup", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_AutoGroupTimerInterval, "iAutoGroupTimerInterval", pt);

    EQAPP_LoadOption<bool>(g_CombatAlternateAbilityIsEnabled, "bCombatAlternateAbility", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_CombatAlternateAbilityTimerInterval, "iCombatAlternateAbilityTimerInterval", pt);
    EQAPP_LoadOption<float>(g_CombatAlternateAbilityDistance, "fCombatAlternateAbilityDistance", pt);

    EQAPP_LoadOption<bool>(g_CombatHotButtonIsEnabled, "bCombatHotButton", pt);
    EQAPP_LoadOption<EQApp::TimerInterval>(g_CombatHotButtonTimerInterval, "iCombatHotButtonTimerInterval", pt);
    EQAPP_LoadOption<signed int>(g_CombatHotButtonIndex, "iCombatHotButtonIndex", pt);
    EQAPP_LoadOption<float>(g_CombatHotButtonDistance, "fCombatHotButtonDistance", pt);
}
