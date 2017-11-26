#ifndef NATIVES_H_
#define NATIVES_H_

// native MurmurHash3(key[], len, seed)
static cell AMX_NATIVE_CALL n_MurmurHash3_x86_32(AMX* amx, cell* params)
{
	static char* key;
	int result;
	amx_StrParam(amx, params[1], key);
	MurmurHash3_x86_32(key, params[2], params[3], &result);
	return result;
}

static void RegisterNatives(AMX* amx)
{
	std::vector<AMX_NATIVE_INFO> MurmurNatives {
		{ "MurmurHash", n_MurmurHash3_x86_32 }
	};
	amx_Register(amx, MurmurNatives.data(), MurmurNatives.size());
}

#endif