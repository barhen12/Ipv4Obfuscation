# IPv4 Shellcode Generator

This tool converts shellcode into an array of IPv4 addresses for obfuscation or encoding purposes.

## How It Works

- Splits the shellcode into 4-byte chunks.
- Converts each chunk into an IPv4 address (e.g., `0xfc, 0xe8, 0x82, 0x00` → `252.232.130.0`).
- Outputs the result as a C-style array of IPv4 strings.

## Example

Input shellcode:
```c
unsigned char buf[] = {
  0xfc, 0xe8, 0x82, 0x00, 0x00, 0x00, 0x60, 0x89, 0xe5, 0x31, 0xc0, 0x64, 0x8b, 0x50
};

Output:
[i] size 14:
char * Ipv4Array[3] = { 
	"252.232.130.0", "0.0.96.137", "229.49.192.100"
};
