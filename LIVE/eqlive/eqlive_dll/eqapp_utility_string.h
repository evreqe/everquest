#pragma once

bool EQAPP_String_Contains(const std::string& subject, const std::string& search);
bool EQAPP_StringView_Contains(std::string_view subject, std::string_view search);
bool EQAPP_String_BeginsWith(const std::string& subject, const std::string& search);
bool EQAPP_StringView_BeginsWith(std::string_view subject, std::string_view search);
bool EQAPP_String_EndsWith(const std::string& subject, const std::string& search);
bool EQAPP_StringView_EndsWith(std::string_view subject, std::string_view search);
void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace);
std::string EQAPP_String_GetBetween(const std::string& subject, const std::string& begin, const std::string& end);
std::string EQAPP_String_GetBetweenBeginAndEnd(const std::string& subject, const std::string& begin, const std::string& end);
std::string EQAPP_String_GetBefore(const std::string& subject, const std::string& search);
std::string EQAPP_String_GetAfter(const std::string& subject, const std::string& search);
std::string EQAPP_String_JoinStrings(const std::vector<std::string>& stringList, const std::string& separator);
std::vector<std::string> EQAPP_String_Split(const std::string& subject, char delimiter);
bool EQAPP_String_IsAlphaNumericWithSpaces(const std::string& subject);
bool EQAPP_String_IsDigits(const std::string &subject);
bool EQAPP_String_IsUppercase(const std::string &subject);
bool EQAPP_String_IsLowercase(const std::string &subject);
void EQAPP_String_ToLowercase(std::string& subject);
void EQAPP_String_ToUppercase(std::string& subject);
std::string EQAPP_String_RemoveHTMLTags(std::string& subject);

bool EQAPP_String_Contains(const std::string& subject, const std::string& search)
{
    return (subject.find(search) != std::string::npos);
}

bool EQAPP_StringView_Contains(std::string_view subject, std::string_view search)
{
    return (subject.find(search) != std::string::npos);
}

bool EQAPP_String_BeginsWith(const std::string& subject, const std::string& search)
{
    return subject.starts_with(search);
}

bool EQAPP_StringView_BeginsWith(std::string_view subject, std::string_view search)
{
    return subject.starts_with(search);
}

bool EQAPP_String_EndsWith(const std::string& subject, const std::string& search)
{
    return subject.ends_with(search);
}

bool EQAPP_StringView_EndsWith(std::string_view subject, std::string_view search)
{
    return subject.ends_with(search);
}

void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace)
{
    std::string newString;
    newString.reserve(subject.length());

    std::string::size_type lastPosition = 0;
    std::string::size_type findPosition;

    while((findPosition = subject.find(search, lastPosition)) != std::string::npos)
    {
        newString.append(subject, lastPosition, findPosition - lastPosition);
        newString += replace;
        lastPosition = findPosition + search.length();
    }

    newString += subject.substr(lastPosition);

    subject.swap(newString);
}

std::string EQAPP_String_GetBetween(const std::string& subject, const std::string& begin, const std::string& end)
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

std::string EQAPP_String_GetBetweenBeginAndEnd(const std::string& subject, const std::string& begin, const std::string& end)
{
    std::size_t beginPosition;
    if ((beginPosition = subject.find(begin)) != std::string::npos)
    {
        std::size_t endPosition;
        if ((endPosition = subject.find(end, beginPosition)) != std::string::npos && endPosition != beginPosition)
        {
            endPosition = endPosition + 1;

            return subject.substr(beginPosition, endPosition - beginPosition);
        }
    }

    return std::string();
}

std::string EQAPP_String_GetBefore(const std::string& subject, const std::string& search)
{
    std::string result = std::string();

    std::string::size_type position = subject.find(search);
    if (position != std::string::npos)
    {
        result = subject.substr(0, position);
    }

    return result;
}

std::string EQAPP_String_GetAfter(const std::string& subject, const std::string& search)
{
    std::string result = std::string();

    std::string::size_type position = subject.find(search);
    if (position != std::string::npos)
    {
        result = subject.substr(position + search.length(), subject.length());
    }

    return result;
}

std::string EQAPP_String_JoinStrings(const std::vector<std::string>& stringList, const std::string& separator)
{
    if (stringList.empty() == false)
    {
        std::stringstream ss;

        auto it = stringList.cbegin();
        while (true)
        {
            ss << *it++;

            if (it != stringList.cend())
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

bool EQAPP_String_IsAlphaNumericWithSpaces(const std::string& subject)
{
    bool result = true;

    for (unsigned int i = 0; i < subject.length(); i++)
    {
        if (::isalnum(subject.at(i)) == 0)
        {
            result = false;
        }

        if (::isspace(subject.at(i)) != 0)
        {
            result = true;
        }

        if (subject.at(i) == ':')
        {
            result = true;
        }

        if (subject.at(i) == '-')
        {
            result = true;
        }

        if (subject.at(i) == ',')
        {
            result = true;
        }

        if (subject.at(i) == '\'')
        {
            result = true;
        }
    }
    
    return result;
}

bool EQAPP_String_IsDigits(const std::string &subject)
{
    return std::all_of(subject.begin(), subject.end(), ::isdigit);
}

bool EQAPP_String_IsLowercase(const std::string &subject)
{
    return std::all_of(subject.begin(), subject.end(), ::islower);
}

bool EQAPP_String_IsUppercase(const std::string &subject)
{
    return std::all_of(subject.begin(), subject.end(), ::isupper);
}

void EQAPP_String_ToLowercase(std::string& subject)
{
    std::transform(subject.begin(), subject.end(), subject.begin(), ::tolower);
}

void EQAPP_String_ToUppercase(std::string& subject)
{
    std::transform(subject.begin(), subject.end(), subject.begin(), ::toupper);
}

std::string EQAPP_String_RemoveHTMLTags(std::string& subject)
{
    std::string result = std::string();

    for (;;)
    {
        std::string::size_type beginPosition = subject.find('<');

        if (beginPosition == std::string::npos)
        {
            result = result + subject;
            break;
        }

        if (beginPosition != 0)
        {
            result = result + subject.substr(0, beginPosition);
            subject = subject.substr(beginPosition, subject.size() - beginPosition);
            beginPosition = 0;
        }

        std::string::size_type endPosition;
        for
        (
            endPosition = beginPosition;
            endPosition < subject.size() && subject[endPosition] != '>';
            ++endPosition
        )
        {
            if (subject[endPosition] == '"')
            {
                endPosition++;
                while (endPosition < subject.size() && subject[endPosition] != '"')
                {
                    endPosition++;
                }
            }
        }

        if (endPosition == subject.size())
        {
            subject = subject.substr(endPosition, subject.size() - endPosition);
            break;
        }
        else
        {
            endPosition++;
            subject = subject.substr(endPosition, subject.size() - endPosition);
        }
    }

    return result;
}

