#include "StringUtils.h"
#include <cctype>
#include <algorithm>

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    ssize_t strlen = str.size();

    if (strlen == 0)
    {
        return "";
    }

    if (end == 0)
    {
        end = strlen;
    }

    if (start < 0)
    {
        start = start + strlen;
    }

    if (start > strlen) 
    {
        start = strlen;
    }

    if(end < 0){
        end = end + strlen;
    }

    if (end > strlen) 
    {
        end = strlen;
    }

    if (end < start)
    {
        return "";
    }

    std::string slice;
    for(ssize_t i = start; i < end; i ++)
    {
        slice += str[i];
    }

    return slice;
}

std::string Capitalize(const std::string &str) noexcept{
    std::string Temp = str;

    ssize_t strlen = str.size();

    if (strlen == 0)
    {
        return "";
    }

    for (ssize_t i = 1; i < strlen; i ++)
    {
        Temp[i] = tolower(Temp[i]);
    }

    Temp[0] = toupper(Temp[0]);
    return Temp;
}

std::string Upper(const std::string &str) noexcept{
    std::string Temp = str;

    ssize_t strlen = str.size();

    if (strlen == 0)
    {
        return "";
    }

    for (ssize_t i = 0; i < strlen; i ++)
    {
        Temp[i] = toupper(Temp[i]);
    }

    return Temp;
}

std::string Lower(const std::string &str) noexcept{
    std::string Temp = str;

    ssize_t strlen = str.size();

    if (strlen == 0)
    {
        return "";
    }

    for (ssize_t i = 0; i < strlen; i ++)
    {
        Temp[i] = tolower(Temp[i]);
    }

    return Temp;
}

std::string LStrip(const std::string &str) noexcept{
    std::string Temp = str;

    ssize_t strlen = str.size();

    if (strlen == 0)
    {
        return "";
    }

    ssize_t start = 0;
    for (ssize_t i = 0; i < strlen; i ++)
    {
        if (isspace(Temp[start]))
        {
            start ++;
        }
        else
        {
            break;
        }
    }

    return Slice(Temp, start, strlen);
}

std::string RStrip(const std::string &str) noexcept{
    std::string Temp = str;

    ssize_t strlen = str.size();

    if (strlen == 0)
    {
        return "";
    }

    ssize_t end = strlen;
    for (ssize_t i = 0; i < strlen; i ++)
    {
        if (isspace(Temp[end - 1]))
        {
            end --;
        }
        else
        {
            break;
        }
    }

    return Slice(Temp, 0, end);
}

std::string Strip(const std::string &str) noexcept{
    std::string Temp = str;

    ssize_t strlen = str.size();

    if (strlen == 0)
    {
        return "";
    }

    Temp = LStrip(Temp);
    Temp = RStrip(Temp);

    return Temp;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    std::string Temp = str;

    ssize_t strlen = str.size();

    if (width <= strlen)
    {
        return Temp;
    }

    for (ssize_t i = 0; i < width - strlen; i ++)
    {
        Temp = Temp + fill;
    }

    return Temp;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    std::string Temp = str;

    ssize_t strlen = str.size();

    if (width <= strlen)
    {
        return Temp;
    }

    for (ssize_t i = 0; i < width - strlen; i ++)
    {
        Temp = fill + Temp;
    }

    return Temp;
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    std::string Temp = str;

    ssize_t strlen = str.size();

    if (width <= strlen)
    {
        return Temp;
    }

    ssize_t left_fill = (width - strlen) / 2;
    Temp = RJust(Temp, strlen + left_fill, fill);
    Temp = LJust(Temp, width, fill);

    return Temp;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std::string result = "";
    ssize_t strlen = str.size();
    ssize_t oldlen = old.size();

    if (oldlen == 0)
    {
        for (ssize_t i = 0; i < strlen; i ++)
        {
            result += rep;
            result += str[i];
        }
        result += rep;
        return result;
    }

    for (ssize_t i = 0; i < strlen; )
    {
        if (Slice(str, i, i + oldlen) == old)
        {
            result += rep;
            i += oldlen;
        }
        else
        {
            result += str[i];
            i ++;
        }
    }

    return result;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector< std::string > result;
    ssize_t strlen = str.size();
    ssize_t spltlen = splt.size();

    if (strlen == 0)
    {
        return result;
    }

    if (spltlen == 0)
    {
        for (ssize_t i = 0; i < strlen; i ++)
        {
            result.push_back(Slice(str, i, i + 1));
        }
        return result;
    }

    ssize_t start = 0;
    for (ssize_t i = 0; i < strlen; )
    {
        if (Slice(str, i, i + spltlen) == splt)
        {
            result.push_back(Slice(str, start, i));
            i += spltlen;
            start = i;
        }
        else
        {
            i ++;
        }
    }
    result.push_back(Slice(str, start, strlen));

    return result;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string result;
    size_t vectlen = vect.size();

    for (size_t i = 0; i < vectlen; i ++)
    {
        result += vect[i];
        if (i < vectlen - 1)
        {
            result += str;
        }
    }

    return result;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string result;
    ssize_t strlen = str.size();
    ssize_t addlen = 0;

    if (tabsize <= 0)
    {
        return str;
    }

    for (ssize_t i = 0; i < strlen; i ++)
    {

        if (Slice(str, i, i + 1) == "\t")
        {
            ssize_t left = tabsize - (addlen % tabsize);
            for (ssize_t j = 0; j < left; j ++)
            {
                result += ' ';
                addlen ++;
            }
        }
        else
        {
            result += str[i];
            addlen ++;
        }
    }

    return result;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    std::string l = left;
    std::string r = right;
    if (ignorecase)
    {
        l = Lower(left);
        r = Lower(right);
    }
    ssize_t leftlen = l.size();
    ssize_t rightlen = r.size();

    std::vector<std::vector<int>> d(leftlen + 1, std::vector<int>(rightlen + 1, 0));

    for (ssize_t i = 0; i <= leftlen; i++)
    {
        d[i][0] = i;
    }
    for (ssize_t j = 0; j <= rightlen; j++)
    {
        d[0][j] = j;
    }

    for (ssize_t i = 1; i <= leftlen; i++)
    {
        for (ssize_t j = 1; j <= rightlen; j++)
        {
            int substitutionCost;
            if (l[i - 1] == r[j - 1])
            {
                substitutionCost = 0;
            }
            else
            {
                substitutionCost = 1;
            }

            d[i][j] = std::min({d[i - 1][j] + 1, 
        // Deletion
            d[i][j - 1] + 1, 
        // Insertion
            d[i - 1][j - 1] + substitutionCost});
        // Substitution
        }
    }

    return d[leftlen][rightlen];
}

};