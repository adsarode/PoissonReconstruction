/*=========================================================================
 Authors: Michael Kazhdan and Matthew Bolitho
 at Johns Hopkins University, 2006-10

 Copyright (c) 2006-10, Michael Kazhdan and Matthew Bolitho,
 Johns Hopkins University.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 Redistributions of source code must retain the above copyright notice,
 this list of conditions and the following disclaimer.
 Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 Neither the name of the Johns Hopkins University nor the names of its
 contributors may be used to endorse or promote products derived from this
 software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
=========================================================================*/

#ifndef HASH_INCLUDED
#define HASH_INCLUDED

#if __cplusplus < 201103L

#ifdef WIN32
#include <hash_map>
using stdext::hash_map;
#else // !WIN32
#include <ext/hash_map>
using namespace __gnu_cxx;

namespace __gnu_cxx
{
template< >
struct hash< long long > {
  size_t operator()(long long __x) const { return __x; }
};
template< >
struct hash< const long long > {
  size_t operator()(const long long __x) const { return __x; }
};

template< >
struct hash< unsigned long long > {
  size_t operator()(unsigned long long __x) const { return __x; }
};
template< >
struct hash< const unsigned long long > {
  size_t operator()(const unsigned long long __x) const { return __x; }
};
}
#endif // WIN32

#else // __cplusplus >= 201103L
#include <unordered_map>
template<class Key, class Value>
using hash_map = std::unordered_map<Key, Value>;
#endif // __cplusplus

#endif // HASH_INCLUDED
