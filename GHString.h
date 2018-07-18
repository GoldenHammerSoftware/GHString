// Copyright 2018 Golden Hammer Software.
#pragma once

#include <stdlib.h>

// A convenience and safety wrapper for char*s.
class GHString
{
public:
	enum CharHandlingType {
		// just point to the new chars
		CHT_REFERENCE,
		// make a copy of the chars
		CHT_COPY,
		// point to the new chars, and take responsibility for deletion.
		CHT_CLAIM
	};

	GHString(void);
	GHString(const GHString& rhs);
	GHString(const char* text, CharHandlingType type=CHT_REFERENCE);
	~GHString(void);

	void setConstChars(const char* chars, CharHandlingType type);
	void setChars(char* chars, CharHandlingType type);

	// become a truncation of chars.  if char length > maxLen then add "..." at the end.
	void truncateChars(const char* chars, size_t maxLen);
    
    void format(const char* str, ...);

	const char* getChars(void) const;
    char* getNonConstChars(void);
	
	size_t getCharLen(void) const { if (!mChars && !mConstChars) return 0; return mCharLen; }
    // return true if string is 0 or ""
    bool isEmpty(void) const;
    
    operator const char*(void) const { return getChars(); }
	bool operator < (const GHString& other) const;
	bool operator ==(const GHString& other) const;
	bool operator ==(const char* other) const;
	bool operator !=(const GHString& other) const;
	bool operator !=(const char* other) const;
    
    GHString& operator=(const GHString& rhs);

private:
	void clearNonConstChars(void);

private:
	/// A string is expected to have either const chars or chars but not both.
	const char* mConstChars{ 0 };
	char* mChars{ 0 };
	bool mOwnsChars{ false };
	size_t mCharLen{ 0 };
};
