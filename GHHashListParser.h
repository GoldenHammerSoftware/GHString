// Copyright 2018 Golden Hammer Software.
#pragma once

#include <vector>
#include "GHString/GHIdentifier.h"
#include "GHString/GHIdentifierMap.h"

class GHStringHashTable;

// Utility for turning a space separated list into a vector of string hashes
namespace GHHashListParser
{
    void parseHashList(const char* str, const GHStringHashTable& hashTable, 
		std::vector<GHIdentifier>& ret);
    void parseHashEnumList(const char* str, const GHIdentifierMap<int>& enumStore, 
		std::vector<int>& ret);
}
