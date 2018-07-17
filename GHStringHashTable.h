// Copyright 2010 Golden Hammer Software
#pragma once

#include "GHString/GHIdentifier.h"

class GHStringHashTable
{
public:
	virtual ~GHStringHashTable(void) {}
	
    // if len == 0 use the full length of the string
	virtual GHIdentifier generateHash(const char* str, int len=0) const = 0;
};
