# MurmurHash3
MurmurHash3 for SA:MP

## Natives
```pawn
native MurmurHash(const key[], len, seed);
```

## Example
Let's make a test hash, create variable with your string.
```pawn
new key[] = "This is my test string"; 
```
And now print hash in console.
```pawn
printf("Hash: %d",MurmurHash(key, sizeof(key), 0));
```
I got `Hash: 733688637`

## Installation
1. Download MurmurHash from [Releases][download] page.
2. Extract `MurmurHash3.inc` to `./pawno/include` folder.
3. In your mode include `MurmurHash3.inc`
4. Extract `MurmurHash3.so` or `MurmurHash3.dll` to `./plugins` folder.
5. In server.cfg on line `plugins` add `MurmurHash3.dll` or `MurmurHash3.so`.
