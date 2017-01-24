#define _XOR_CRYPT_KEY 0x80
#define _CESAR_CRYPT_KEY 0x05
#define DllExport extern "C" __declspec( dllexport )

DllExport void Encrypt(char* szText);
DllExport void Decrypt(char* szText);