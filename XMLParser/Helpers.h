#pragma once
#include <string>
#include <vector>
using namespace std;

void ltrim(std::string& s);
void rtrim(std::string& s);
void trim(std::string& s);
vector<string> slice(vector<int>& vec, int startIndex, int endIndex);