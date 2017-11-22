/*

	Copyright (c) 2017 ShapeGaz

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.

*/
#include "amx\amx.h"
#include "plugincommon.h"

#include <vector>

#include "MurmurHash3/murmur3.cpp"

#include "natives.h"

typedef void(*logprintf_t)(const char* format, ...);

logprintf_t logprintf;

extern void *pAMXFunctions;

using namespace std;

class murmur {
public:

	static constexpr char
		*name = "MurmurHash3",
		*version = "0.4",
		*author = "ShapeGaz";

	static void AmxLoad(AMX* amx)
	{
		RegisterNatives(amx);
	}

	static void AmxUnload(AMX* amx)
	{
		return;
	}

	static unsigned int Supports()
	{
		return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
	}

	static bool Load(void **ppData)
	{
		logprintf("  **%s v%s by %s loaded", name, version, author);
		return true;
	}

	static void Unload()
	{
		logprintf("  **%s v%s by %s unloaded", name, version, author);
	}
};

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return murmur::Supports();
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
	return murmur::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	murmur::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL AmxLoad(AMX* amx)
{
	murmur::AmxLoad(amx);
}

PLUGIN_EXPORT void PLUGIN_CALL AmxUnload(AMX* amx)
{
	murmur::AmxUnload(amx);
}