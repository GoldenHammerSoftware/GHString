// Copyright 2010 Golden Hammer Software
#pragma once

#include <vector>

// Util class to take strings and turn them into lists of numbers.
class GHNumberListParser
{
public:
	void parseFloatList(const char* string, float* dest, unsigned int numFloats) const;
	void parseIntList(const char* string, int* dest, unsigned int numInts) const;
	void parseFloatRect(const char* string, float* ul, float* br, unsigned int numFloatsPerCorner) const;
	void parseIntVector(const char* string, std::vector<int>& dest) const;
	void parseFloatVector(const char* string, std::vector<float>& dest) const;    
};
