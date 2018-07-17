// Copyright 2010 Golden Hammer Software
#pragma once

#include "GHString/GHStringHashTable.h"

// Simple implementation of the DJB2 hashing algorithm
// Currently does not handle collisions
class GHStringHashTableDJB2 : public GHStringHashTable
{
public:
	virtual GHIdentifier generateHash(const char* str, int len=0) const;
};
