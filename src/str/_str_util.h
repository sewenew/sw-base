/**************************************************************************
   Copyright 2016 sewenew

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

#ifndef SW_BASE_STR__STR_UTIL_H
#define SW_BASE_STR__STR_UTIL_H

#include <string>

namespace sw {

namespace str {

// Join strings with 'delimiter'.
template <typename Iter>
std::string join(const std::string &delimiter, Iter first, Iter last);

// Join strings for which 'pred' returns true with 'delimiter'.
template <typename Iter, typename Pred>
std::string join_if(const std::string &delimiter, Iter first, Iter last, Pred pred);

// Split a string with 'delimiter' into pieces.
template <typename Iter>
void split(const std::string &str, const std::string &delimiter, Iter result);

}

}

#endif // end SW_BASE_STR__STR_UTIL_H
