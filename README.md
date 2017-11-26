# What is MurmurHash3?
MurmurHash3 is non-cryptographic hash function([Github](https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp)), and my plugin allow working with it

# Natives
```pawn
native MurmurHash(const key[], len, seed);
```

# Example
## Example #1 - Not random hash
### Step one
Let's make a test hash. Create variable with your key string
```pawn
new key[] = "This is test string";
```
### Step two
And now we'll print a hash in the console
```pawn
printf("Hash: %d",MurmurHash(key,sizeof(key),0));
```
Done. I got `Hash: 733688637`

## Example #2 - Random hash
### Step one
Let's make a test random hash. Create variable with your key string
```pawn
new key[] = "This is test string";
```
### Step two
Crate variable with random number
```pawn
new randomvalue = random(9999);
```
### Step three
And now we'll print a hash in the console
```pawn
printf("Random hash: %d",MurmurHash(key,sizeof(key),randomvalue));
```

# Installation
1. Download MurmurHash from [Releases](https://github.com/ShapeDev/MurmurHash3/releases) page
2. Extract `MurmurHash.inc` to folder `pawno/include`
3. In your mode include MurmurHash (`#include <MurmurHash>`)
4. Extract `MurmurHash.so` or `MurmurHash.dll` to folder `plugins`
5. In server.cfg on line `plugins` add `MurmurHash.dll` or `MurmurHash.so`
