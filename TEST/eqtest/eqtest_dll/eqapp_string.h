#pragma once

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

bool EQAPP_String_Contains(std::string& subject, const std::string& search);
bool EQAPP_String_BeginsWith(std::string& subject, const std::string& search);
bool EQAPP_String_EndsWith(std::string& subject, const std::string& search);
void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace);
std::string EQAPP_String_GetBetween(std::string& subject, const std::string& begin, const std::string& end);
std::string EQAPP_String_GetBefore(const std::string& subject, const std::string& search);
std::string EQAPP_String_GetAfter(const std::string& subject, const std::string& search);
std::string EQAPP_String_JoinStrings(const std::vector<std::string>& elements, const std::string& separator);
std::vector<std::string> EQAPP_String_Split(const std::string& subject, char delimiter);
bool EQAPP_String_IsDigits(const std::string &subject);

bool EQAPP_String_Contains(std::string& subject, const std::string& search)
{
    return (subject.find(search) != std::string::npos);
}

bool EQAPP_String_BeginsWith(std::string& subject, const std::string& search)
{
    return (subject.compare(0, search.size(), search) == 0);
}

bool EQAPP_String_EndsWith(std::string& subject, const std::string& search)
{
    if (subject.length() >= search.length())
    {
        return (subject.compare (subject.length() - search.length(), search.length(), search) == 0);
    }

    return false;
}

void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace)
{
    std::size_t position = 0;
    while ((position = subject.find(search, position)) != std::string::npos)
    {
         subject.replace(position, search.length(), replace);
         position += replace.length();
    }
}

std::string EQAPP_String_GetBetween(std::string& subject, const std::string& begin, const std::string& end)
{
    std::size_t beginPosition;
    if ((beginPosition = subject.find(begin)) != std::string::npos)
    {
        beginPosition = beginPosition + begin.length();

        std::size_t endPosition;
        if ((endPosition = subject.find(end, beginPosition)) != std::string::npos && endPosition != beginPosition)
        {
            return subject.substr(beginPosition, endPosition - beginPosition);
        }
    }

    return std::string();
}

std::string EQAPP_String_GetBefore(const std::string& subject, const std::string& search)
{
    std::string result = std::string();

    std::string::size_type pos = subject.find(search);
    if (pos != std::string::npos)
    {
        result = subject.substr(0, pos);
    }

    return result;
}

std::string EQAPP_String_GetAfter(const std::string& subject, const std::string& search)
{
    std::string result = std::string();

    std::string::size_type pos = subject.find(search);
    if (pos != std::string::npos)
    {
        result = subject.substr(pos + search.length(), subject.length());
    }

    return result;
}

std::string EQAPP_String_JoinStrings(const std::vector<std::string>& elements, const std::string& separator)
{
    if (elements.empty() == false)
    {
        std::stringstream ss;

        auto it = elements.cbegin();
        while (true)
        {
            ss << *it++;

            if (it != elements.cend())
            {
                ss << separator;
            }
            else
            {
                return ss.str();
            }
        }
    }

    return std::string();
}

std::vector<std::string> EQAPP_String_Split(const std::string& subject, char delimiter)
{
    std::vector<std::string> tokens;

    std::istringstream iss(subject);
    for (std::string token; std::getline(iss, token, delimiter); tokens.push_back(token));

    return tokens;
}

bool EQAPP_String_IsDigits(const std::string &subject)
{
    return std::all_of(subject.begin(), subject.end(), ::isdigit);
}
