#ifndef NATIVES_H_
#define NATIVES_H_

// native MurmurHash3(key[], len, seed)
static cell AMX_NATIVE_CALL n_MurmurHash3_x86_32(AMX* amx, cell* params)
{
	cell
		*addr;
	int
		len = params[2];
	int
		result;
	if (amx_GetAddr(amx, params[1], &addr) == AMX_ERR_NONE)
	{
		char* key = new char[len + 1];
		amx_GetString(key, addr, 0, len + 1);
		MurmurHash3_x86_32(key, len, params[3], &result);
		delete[] key;
		return result;
	}
	return false;
}

static void RegisterNatives(AMX* amx)
{
	std::vector<AMX_NATIVE_INFO> MurmurNatives{
		{ "MurmurHash", n_MurmurHash3_x86_32 }
	};
	amx_Register(amx, MurmurNatives.data(), MurmurNatives.size());
}

#endif