/**************************************************************************
   Copyright (c) 2016 sewenew

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 *************************************************************************/

#ifndef SW_BASE_STR__STR_UTIL_HPP
#define SW_BASE_STR__STR_UTIL_HPP

#include <algorithm>

namespace sw {

namespace str {

template <typename Iter>
std::string join(const std::string &delimiter, Iter first, Iter last) {
    std::string res;
    if (first != last) {
        res += *first;
        ++first;
    }

    while (first != last) {
        res += (delimiter + *first);
        ++first;
    }

    return res;
}

template <typename Iter, typename Pred>
std::string join_if(const std::string &delimiter, Iter first, Iter last, Pred pred) {
    while (first != last && !pred(*first)) {
        ++first;
    }

    std::string res;
    if (first != last) {
        res += *first;
        ++first;
    }

    while (first != last) {
        if (pred(*first)) {
            res += (delimiter + *first);
        }
        ++first;
    }

    return res;
}

template <typename Iter>
void split(const std::string &str, const std::string &delimiter, Iter result) {
    if (str.empty()) {
        return;
    }

    if (delimiter.empty()) {
        std::transform(str.begin(), str.end(), result,
                [] (char c) { return std::string(1, c); } );
        return;
    }

    std::string::size_type pos = 0;
    std::string::size_type idx = 0;
    while (true) {
        pos = str.find(delimiter, idx);
        if (pos == std::string::npos) {
            *result = str.substr(idx);
            ++result;
            break;
        }

        *result = str.substr(idx, pos - idx);
        ++result;
        idx = pos + delimiter.size();
    }
}

}

}

#endif // end SW_BASE_STR__STR_UTIL_HPP
