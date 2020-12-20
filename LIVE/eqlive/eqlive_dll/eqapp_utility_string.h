#pragma once

bool EQAPP_String_Contains(const std::string& subject, const std::string& search);
bool EQAPP_String_BeginsWith(const std::string& subject, const std::string& search);
bool EQAPP_String_EndsWith(const std::string& subject, const std::string& search);
void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace);
std::string EQAPP_String_GetBetween(const std::string& subject, const std::string& begin, const std::string& end);
std::string EQAPP_String_GetBetweenBeginAndEnd(const std::string& subject, const std::string& begin, const std::string& end);
std::string EQAPP_String_GetBefore(const std::string& subject, const std::string& search);
std::string EQAPP_String_GetAfter(const std::string& subject, const std::string& search);
std::string EQAPP_String_JoinStrings(const std::vector<std::string>& elements, const std::string& separator);
std::vector<std::string> EQAPP_String_Split(const std::string& subject, char delimiter);
bool EQAPP_String_IsDigits(const std::string &subject);
bool EQAPP_String_IsUppercase(const std::string &subject);
bool EQAPP_String_IsLowercase(const std::string &subject);
std::string EQAPP_String_ToLowercase(const std::string& subject);
std::string EQAPP_String_ToUppercase(const std::string& subject);
std::string EQAPP_String_RemoveHTMLTags(std::string& subject);

bool EQAPP_String_Contains(const std::string& subject, const std::string& search)
{
    return (subject.find(search) != std::string::npos);
}

bool EQAPP_String_BeginsWith(const std::string& subject, const std::string& search)
{
/*
    return (subject.compare(0, search.size(), search) == 0);
 */

    return subject.starts_with(search);
}

bool EQAPP_String_EndsWith(const std::string& subject, const std::string& search)
{
/*
    if (subject.length() >= search.length())
    {
        return (subject.compare (subject.length() - search.length(), search.length(), search) == 0);
    }
*/

    //return false;

    return subject.ends_with(search);
}

void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace)
{
/*
    std::size_t position = 0;
    while ((position = subject.find(search, position)) != std::string::npos)
    {
         subject.replace(position, search.length(), replace);
         position += replace.length();
    }
*/

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

bool EQAPP_String_IsLowercase(const std::string &subject)
{
    return std::all_of(subject.begin(), subject.end(), ::islower);
}

bool EQAPP_String_IsUppercase(const std::string &subject)
{
    return std::all_of(subject.begin(), subject.end(), ::isupper);
}

std::string EQAPP_String_ToLowercase(const std::string& subject)
{
    std::string str = subject;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    return str;
}

std::string EQAPP_String_ToUppercase(const std::string& subject)
{
    std::string str = subject;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    return str;
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

