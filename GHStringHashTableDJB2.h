// Copyright 2018 Golden Hammer Software.
#pragma once

#include "GHStringHashTable.h"

// Simple implementation of the DJB2 hashing algorithm
// Currently does not handle collisions
class GHStringHashTableDJB2 : public GHStringHashTable
{
public:
	virtual GHIdentifier generateHash(const char* str, size_t len=0) const;
};
