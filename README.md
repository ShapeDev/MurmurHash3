# MurmurHash3
MurmurHash3 for SA:MP

## Natives
```pawn
native MurmurHash(const key[], len, seed);
```

## Example

### Example #1 - Not random hash
Let's make a test hash. Create variable with your key string.
```pawn
new key[] = "This is my test string"; 
```
And now we'll print a hash in the console.
```pawn
printf("Hash: %d",MurmurHash(key, sizeof(key), 0));
```
I got `Hash: 733688637`

### Example #2 - Random hash
Let's make a test random hash. Create variable with your key string.
```pawn
new key[] = "This is my test string";
```
Create variable with random number.
```pawn
new number = random(9999);
```
And now we'll print a hash in the console.
```pawn
printf("Random hash: %d",MurmurHash(key,sizeof(key),number));
```

## Installation
1. Download MurmurHash from [Releases](https://github.com/ShapeDev/MurmurHash3/releases) page.
2. Extract `MurmurHash3.inc` to `./pawno/include` folder.
3. In your mode include `MurmurHash3.inc`
4. Extract `MurmurHash3.so` or `MurmurHash3.dll` to `./plugins` folder.
5. In server.cfg on line `plugins` add `MurmurHash3.dll` or `MurmurHash3.so`.
