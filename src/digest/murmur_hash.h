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

#ifndef SW_BASE_DIGEST_MURMUR_HASH_H
#define SW_BASE_DIGEST_MURMUR_HASH_H

#include <cstdint>
#include "MurmurHash3.h"

namespace sw {

namespace digest {

constexpr uint32_t DEFAULT_SEED = 0;

inline uint64_t murmur_hash(const void *key, int len, uint32_t seed = DEFAULT_SEED) {
    uint64_t res[2];
#ifdef BUILD_X86
    MurmurHash3_x86_128(key, len, seed, res);
#else
    MurmurHash3_x64_128(key, len, seed, res);
#endif // end BUILD_X86
    return res[0];
}

}

}

#endif // end SW_BASE_DIGEST_MURMUR_HASH_H
