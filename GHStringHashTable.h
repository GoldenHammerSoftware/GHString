// Copyright 2018 Golden Hammer Software.
#pragma once

#include "GHIdentifier.h"

// Interface for converting char*s to GHIdentifiers.
// TODO: rename to GHStringHashGenerator, it's not a table.
class GHStringHashTable
{
public:
	virtual ~GHStringHashTable(void) {}
	
    // if len == 0 use the full length of the string
	virtual GHIdentifier generateHash(const char* str, size_t len=0) const = 0;
};
