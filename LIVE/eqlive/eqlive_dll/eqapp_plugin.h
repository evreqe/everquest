#pragma once

#include <memory>
#include <string>
#include <vector>

namespace EQApp
{

    class Plugin;

    std::vector<Plugin*> PluginList;

    class Plugin
    {
    public:
        Plugin()
        {
            PluginList.push_back(this);
        }
    
        const std::string& GetName()
        {
            return m_name;
        }

        void SetName(const std::string& name)
        {
            m_name = name;
        }

        void SetEnabled(bool bEnabled)
        {
            m_enabled = bEnabled;
        }

        void Toggle()
        {
            EQ_ToggleBool(m_enabled);
            EQAPP_PrintBool(m_name.c_str(), m_enabled);
        }

        void On()
        {
            if (m_enabled == false)
            {
                Toggle();
            }
        }

        void Off()
        {
            if (m_enabled == true)
            {
                Toggle();
            }
        }

        virtual void Load()
        {
            //
        }

        virtual void Unload()
        {
            //
        }

        virtual void Execute()
        {
            //
        }

    private:
        bool m_enabled = false;

        std::string m_name = {};
    };

} // namespace EQApp
