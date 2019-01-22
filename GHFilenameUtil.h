#pragma once

// A place for common filename manipulation functions.
namespace GHFilenameUtil
{
	// Replace any existing extension or add a new one if not found.
	// Return new memory.
	char* replaceExtension(const char* input, const char* ext);
}
