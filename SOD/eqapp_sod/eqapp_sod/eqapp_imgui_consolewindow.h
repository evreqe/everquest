#ifndef EQAPP_IMGUI_CONSOLEWINDOW_H
#define EQAPP_IMGUI_CONSOLEWINDOW_H

#include "eqapp_imgui.h"

#include "eqapp_interpretcommand.h"

struct EQAPPIMGUIConsoleWindow
{
    char                  m_inputBuffer[256];
    ImVector<char*>       m_items;
    bool                  m_bScrollToBottom;
    ImVector<char*>       m_history;
    int                   m_historyPosition; // -1: new line, 0..m_history.Size-1 browsing history.
    ImVector<const char*> m_commands;
    std::vector<std::string> m_interpretCommands;

    EQAPPIMGUIConsoleWindow()
    {
        ClearLog();
        memset(m_inputBuffer, 0, sizeof(m_inputBuffer));
        m_historyPosition = -1;
        m_commands.push_back("HELP");
        m_commands.push_back("HISTORY");
        m_commands.push_back("CLEAR");

        // auto completion for console commands
        for (auto& command : g_interpretCommandList)
        {
            m_commands.push_back(command.c_str());
        }
    }

    ~EQAPPIMGUIConsoleWindow()
    {
        ClearLog();

        for (int i = 0; i < m_history.Size; i++)
        {
            free(m_history[i]);
        }
    }

    // portable helpers
    static int   Stricmp(const char* str1, const char* str2)         { int d; while ((d = toupper(*str2) - toupper(*str1)) == 0 && *str1) { str1++; str2++; } return d; }
    static int   Strnicmp(const char* str1, const char* str2, int n) { int d = 0; while (n > 0 && (d = toupper(*str2) - toupper(*str1)) == 0 && *str1) { str1++; str2++; n--; } return d; }
    static char* Strdup(const char *str)                             { size_t len = strlen(str) + 1; void* buff = malloc(len); return (char*)memcpy(buff, (const void*)str, len); }

    void ClearLog()
    {
        for (int i = 0; i < m_items.Size; i++)
        {
            free(m_items[i]);
        }
        m_items.clear();

        m_bScrollToBottom = true;
    }

    void AddLog(const char* fmt, ...) IM_PRINTFARGS(2)
    {
        char buf[1024];
        va_list args;
        va_start(args, fmt);
        vsnprintf_s(buf, IM_ARRAYSIZE(buf), fmt, args);
        buf[IM_ARRAYSIZE(buf) - 1] = 0;
        va_end(args);

        m_items.push_back(Strdup(buf));

        m_bScrollToBottom = true;
    }

    void Draw(const char* title, bool* p_open)
    {
        ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiSetCond_FirstUseEver);
        if (!ImGui::Begin(title, p_open))
        {
            ImGui::End();
            return;
        }

        ImGui::TextWrapped("Enter 'HELP' for help, press TAB to use text completion.");

        if (ImGui::SmallButton("Clear")) ClearLog(); ImGui::SameLine();
        if (ImGui::SmallButton("Scroll to Bottom")) m_bScrollToBottom = true;

        ImGui::Separator();

        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
        static ImGuiTextFilter filter;
        filter.Draw("Filter (\"incl,-excl\") (\"error\") (\"debug\")", 180);
        ImGui::PopStyleVar();

        ImGui::Separator();

        ImGui::BeginChild("ScrollingRegion", ImVec2(0, -ImGui::GetItemsLineHeightWithSpacing()), false, ImGuiWindowFlags_HorizontalScrollbar);

        if (ImGui::BeginPopupContextWindow())
        {
            if (ImGui::Selectable("Clear"))
            {
                ClearLog();
            }
            ImGui::EndPopup();
        }

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1));
        for (int i = 0; i < m_items.Size; i++)
        {
            const char* item = m_items[i];

            if (!filter.PassFilter(item))
            {
                continue;
            }

            ImVec4 col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
            if (strstr(item, "[error]"))
            {
                col = ImColor(1.0f, 0.4f, 0.4f, 1.0f);
            }
            else if (strstr(item, "[error]"))
            {
                col = ImColor(1.0f, 1.0f, 0.4f, 1.0f);
            }
            else if (strncmp(item, "# ", 2) == 0)
            {
                col = ImColor(1.0f, 0.78f, 0.58f, 1.0f);
            }

            ImGui::PushStyleColor(ImGuiCol_Text, col);
            ImGui::TextUnformatted(item);
            ImGui::PopStyleColor();
        }

        if (m_bScrollToBottom == true)
        {
            ImGui::SetScrollHere();
        }

        m_bScrollToBottom = false;

        ImGui::PopStyleVar();
        ImGui::EndChild();
        ImGui::Separator();

        if (ImGui::InputText("Input", m_inputBuffer, IM_ARRAYSIZE(m_inputBuffer), ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory, &TextEditCallbackStub, (void*)this))
        {
            char* input_end = m_inputBuffer + strlen(m_inputBuffer);

            while (input_end > m_inputBuffer && input_end[-1] == ' ')
            {
                input_end--;
                *input_end = 0;
            }

            if (m_inputBuffer[0])
            {
                ExecCommand(m_inputBuffer);
            }

            strcpy_s(m_inputBuffer, 256, "");
        }

        if (ImGui::IsItemHovered() || (ImGui::IsRootWindowOrAnyChildFocused() && !ImGui::IsAnyItemActive() && !ImGui::IsMouseClicked(0)))
        {
            ImGui::SetKeyboardFocusHere(-1);
        }

        ImGui::End();
    }

    void ExecCommand(const char* commandLine)
    {
        AddLog("# %s\n", commandLine);

        m_historyPosition = -1;
        for (int i = m_history.Size - 1; i >= 0; i--)
        {
            if (Stricmp(m_history[i], commandLine) == 0)
            {
                free(m_history[i]);
                m_history.erase(m_history.begin() + i);
                break;
            }
        }

        m_history.push_back(Strdup(commandLine));

        if (Stricmp(commandLine, "CLEAR") == 0)
        {
            ClearLog();
        }
        else if (Stricmp(commandLine, "HELP") == 0)
        {
            AddLog("Commands:");
            for (int i = 0; i < m_commands.Size; i++)
                AddLog("- %s", m_commands[i]);
        }
        else if (Stricmp(commandLine, "HISTORY") == 0)
        {
            for (int i = m_history.Size >= 10 ? m_history.Size - 10 : 0; i < m_history.Size; i++)
                AddLog("%3d: %s\n", i, m_history[i]);
        }
        else
        {
            //AddLog("Unknown command: '%s'\n", commandLine);
            m_interpretCommands.push_back(commandLine);
        }
    }

    static int TextEditCallbackStub(ImGuiTextEditCallbackData* data)
    {
        EQAPPIMGUIConsoleWindow* console = (EQAPPIMGUIConsoleWindow*)data->UserData;
        return console->TextEditCallback(data);
    }

    int TextEditCallback(ImGuiTextEditCallbackData* data)
    {
        //AddLog("cursor: %d, selection: %d-%d", data->CursorPos, data->SelectionStart, data->SelectionEnd);

        switch (data->EventFlag)
        {
        case ImGuiInputTextFlags_CallbackCompletion:
        {
            // Example of TEXT COMPLETION

            // Locate beginning of current word
            const char* word_end = data->Buf + data->CursorPos;
            const char* word_start = word_end;
            while (word_start > data->Buf)
            {
                const char c = word_start[-1];
                if (c == ' ' || c == '\t' || c == ',' || c == ';')
                    break;
                word_start--;
            }

            // Build a list of candidates
            ImVector<const char*> candidates;
            for (int i = 0; i < m_commands.Size; i++)
                if (Strnicmp(m_commands[i], word_start, (int)(word_end - word_start)) == 0)
                    candidates.push_back(m_commands[i]);

            if (candidates.Size == 0)
            {
                // No match
                AddLog("No match for \"%.*s\"!\n", (int)(word_end - word_start), word_start);
            }
            else if (candidates.Size == 1)
            {
                // Single match. Delete the beginning of the word and replace it entirely so we've got nice casing
                data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
                data->InsertChars(data->CursorPos, candidates[0]);
                data->InsertChars(data->CursorPos, " ");
            }
            else
            {
                // Multiple matches. Complete as much as we can, so inputing "C" will complete to "CL" and display "CLEAR" and "CLASSIFY"
                int match_len = (int)(word_end - word_start);
                for (;;)
                {
                    int c = 0;
                    bool all_candidates_matches = true;
                    for (int i = 0; i < candidates.Size && all_candidates_matches; i++)
                        if (i == 0)
                            c = toupper(candidates[i][match_len]);
                        else if (c != toupper(candidates[i][match_len]))
                            all_candidates_matches = false;
                    if (!all_candidates_matches)
                        break;
                    match_len++;
                }

                if (match_len > 0)
                {
                    data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
                    data->InsertChars(data->CursorPos, candidates[0], candidates[0] + match_len);
                }

                // List matches
                AddLog("Possible matches:\n");
                for (int i = 0; i < candidates.Size; i++)
                    AddLog("- %s\n", candidates[i]);
            }

            break;
        }
        case ImGuiInputTextFlags_CallbackHistory:
        {
            // Example of HISTORY
            const int prev_history_pos = m_historyPosition;
            if (data->EventKey == ImGuiKey_UpArrow)
            {
                if (m_historyPosition == -1)
                    m_historyPosition = m_history.Size - 1;
                else if (m_historyPosition > 0)
                    m_historyPosition--;
            }
            else if (data->EventKey == ImGuiKey_DownArrow)
            {
                if (m_historyPosition != -1)
                    if (++m_historyPosition >= m_history.Size)
                        m_historyPosition = -1;
            }

            // A better implementation would preserve the data on the current input line along with cursor position.
            if (prev_history_pos != m_historyPosition)
            {
                data->CursorPos = data->SelectionStart = data->SelectionEnd = data->BufTextLen = (int)_snprintf_s(data->Buf, (size_t)data->BufSize, _TRUNCATE, "%s", (m_historyPosition >= 0) ? m_history[m_historyPosition] : "");
                data->BufDirty = true;
            }
        }
        }
        return 0;
    }
};

#endif // EQAPP_IMGUI_CONSOLEWINDOW_H
