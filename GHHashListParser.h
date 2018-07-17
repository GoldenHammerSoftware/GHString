// Copyright 2010 Golden Hammer Software
#pragma once

#include <vector>
#include "GHString/GHIdentifier.h"
#include "GHString/GHIdentifierMap.h"

class GHStringHashTable;

// utility class for turning a space separated list into a vector of string hashes
class GHHashListParser
{
public:
    static void parseHashList(const char* str, const GHStringHashTable& hashTable,
                              std::vector<GHIdentifier>& ret);
    static void parseHashEnumList(const char* str, const GHIdentifierMap<int>& enumStore,
                                  std::vector<int>& ret);
};
