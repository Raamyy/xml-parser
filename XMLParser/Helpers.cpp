#include "Helpers.h"
#include <algorithm>
#include<ctype.h>


 void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
        }));
}

 void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
        }).base(), s.end());
}

void trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}

vector<string> slice(vector<int>& vec, vector<int>::iterator start, vector<int>::iterator end)
{
    return vector<string>(end-start);
}
