// Copyright 2018 Golden Hammer Software.
#pragma once

#include "GHIdentifier.h"
#include <stddef.h> // for size_t

// Interface for converting char*s to GHIdentifiers.
class GHStringHashTable
{
public:
	virtual ~GHStringHashTable(void) {}
	
    // if len == 0 use the full length of the string
	virtual GHIdentifier generateHash(const char* str, size_t len=0) const = 0;
};
