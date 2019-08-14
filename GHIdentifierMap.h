// Copyright 2018 Golden Hammer Software.
#pragma once

#include "GHIdentifier.h"
#include "GHStringIdFactory.h"
#include <map>
#include <stddef.h> //for size_t

// A place to store out a map of GHIdentifier to value.
// Adds convenience methods for looking up by GHIdentifier or char*
template< typename T >
class GHIdentifierMap
{
public:
	GHIdentifierMap(const GHStringIdFactory& hashTable)
	: mHashTable(hashTable)
	{
	}

	void add(GHIdentifier id, const T& val)
	{
		mMap.insert(std::pair<GHIdentifier, T>(id, val));
	}

	const T* find(GHIdentifier id) const
	{
		size_t debugSize = mMap.size();
		if (!debugSize) {
			return 0;
		}

		typename std::map<GHIdentifier, T>::const_iterator findIter;
		findIter = mMap.find(id);
		if (findIter == mMap.end()) return 0;
		return &findIter->second;
	}

	void add(const char* str, const T& val)
	{
		add(mHashTable.generateHash(str), val);
	}
	const T* find(const char* str) const
	{
		return find(mHashTable.generateHash(str));
	}

	const GHStringIdFactory& getHashTable(void) const {return mHashTable;}

private:
	const GHStringIdFactory& mHashTable;
	std::map<GHIdentifier, T> mMap;
};
