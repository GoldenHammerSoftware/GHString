// Copyright 2010 Golden Hammer Software
#pragma once

#include "GHString/GHIdentifier.h"
#include "GHString/GHStringHashTable.h"
#include <map>
#include <stddef.h> //for size_t

// A place to store out a map of ghidentifier to value.
//  used for looking stuff up from file.
template< typename T >
class GHIdentifierMap
{
public:
	GHIdentifierMap(const GHStringHashTable& hashTable)
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

	const GHStringHashTable& getHashTable(void) const {return mHashTable;}

private:
	const GHStringHashTable& mHashTable;
	std::map<GHIdentifier, T> mMap;
};
