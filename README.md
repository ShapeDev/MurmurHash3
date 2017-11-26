# What is MurmurHash3?
MurmurHash3 is non-cryptographic hash function([Github](https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp)), and my plugin allow working with it

## Natives
```pawn
native MurmurHash(const key[], len, seed);
```

## Example
### Example #1 - Not random hash
Let's make a test hash. Create variable with your key string
```pawn
new key[] = "This is test string";
```
And now we'll print a hash in the console
```pawn
printf("Hash: %d",MurmurHash(key,sizeof(key),0));
```
Done. I got `Hash: 733688637`

### Example #2 - Random hash
Let's make a test random hash. Create variable with your key string
```pawn
new key[] = "This is test string";
```
Crate variable with random number
```pawn
new randomvalue = random(9999);
```
And now we'll print a hash in the console
```pawn
printf("Random hash: %d",MurmurHash(key,sizeof(key),randomvalue));
```

## Installation
1. Download MurmurHash3 from [Releases](https://github.com/ShapeDev/MurmurHash3/releases) page
2. Extract `MurmurHash3.inc` to folder `pawno/include`
3. In your mode include MurmurHash3 (`#include <MurmurHash3>`)
4. Extract `MurmurHash3.so` or `MurmurHash3.dll` to folder `plugins`
5. In server.cfg on line `plugins` add `MurmurHash3.dll` or `MurmurHash3.so`
