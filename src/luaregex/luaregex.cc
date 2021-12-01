
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "luaregex.h"
#include <iostream>
#include <regex>

Cluaregex::Cluaregex(sol::this_state L)
    : m_oState(L)
{

}

std::vector<std::string> Cluaregex::match(const std::string& strSrc, const std::string& reg)
{
    std::regex e(reg);

    std::smatch cm;
    std::regex_match(strSrc, cm, e, std::regex_constants::match_default);

    std::vector<std::string> vec;
    for (auto it : cm)
    {
        vec.push_back(it);
    }
    return vec;
}

std::vector<std::string> Cluaregex::search(const std::string& strSrc, const std::string& reg)
{
    std::regex e(reg);

    std::smatch cm;
    std::string strData = strSrc;
    std::vector<std::string> vec;
    for (; std::regex_search(strData, cm, e, std::regex_constants::match_default);)
    {
        vec.push_back(cm.str());
        strData = cm.suffix().str();
    }

    return vec;
}
