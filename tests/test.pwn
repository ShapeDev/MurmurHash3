#include <a_samp>
#include <MurmurHash3>

main()
{
	new key[] = "This is test key";
	printf("Hash: %d",MurmurHash(key,sizeof(key),0));
}