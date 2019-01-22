#include "GHFilenameUtil.h"
#include <assert.h>
#include <string.h> // strchr
#include <stdio.h> // sprintf

char* GHFilenameUtil::replaceExtension(const char* input, const char* ext)
{
	assert(input != 0);
	assert(ext != 0);

	const char* existingExt = strchr(input, '.');
	size_t preExtLen = 0;
	if (existingExt)
	{
		preExtLen = existingExt - input;
	}
	else
	{
		preExtLen = strlen(input);
	}
	size_t newExtLen = strlen(ext);

    // +1 for '.'
	size_t newStrLen = preExtLen + 1 + newExtLen;
	char* ret = new char[newStrLen+1]; // +1 for \0
	snprintf(ret, preExtLen+1, "%s", input);
	sprintf(ret, "%s.%s", ret, ext);

	return ret;
}
