/*
*
*	Version: 0.4
*
*/
#include <a_samp>
#include <MurmurHash3>

main()
{
	new key[] = "This is test key"; // Input -> "This is test key"
	printf("Hash: %d",MurmurHash(key,sizeof(key),0)); // Output -> 2348123412 (random number)
}