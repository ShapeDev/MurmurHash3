#ifndef NATIVES_H_
#define NATIVES_H_

static int f_MurmurHash3_x86_32(char* key, int len, int seed);

// native MurmurHash3(key[], len, seed)
static cell AMX_NATIVE_CALL n_MurmurHash3_x86_32(AMX* amx, cell* params)
{
	cell
		*addr;
	int
		len;
	if (amx_GetAddr(amx, params[1], &addr) == AMX_ERR_NONE)
	{
		amx_StrLen(addr, &len);
		char* key = new char[len + 1];
		amx_GetString(key, addr, 0, len + 1);
		return f_MurmurHash3_x86_32(key, len, params[3]);
	}
	return false;
}

// Functions
static int f_MurmurHash3_x86_32(char* key, int len, int seed)
{
	int
		result;
	MurmurHash3_x86_32(key, len, 0, &result);
	return result;
}

static void RegisterNatives(AMX* amx)
{
	std::vector<AMX_NATIVE_INFO> MurmurNatives{
		{ "MurmurHash", n_MurmurHash3_x86_32 }
	};
	amx_Register(amx, MurmurNatives.data(), MurmurNatives.size());
}

#endif