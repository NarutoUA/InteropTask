#include "main.h"

void Encrypt(char* szText)
{
	size_t len = strlen(szText);
	for (size_t i = 0; i < len; ++i)
	{
		szText[i] ^= _XOR_CRYPT_KEY;
		szText[i] += _CESAR_CRYPT_KEY;
	}
}

void Decrypt(char* szText)
{
	size_t len = strlen(szText);
	for (size_t i = 0; i < len; ++i)
	{
		szText[i] -= _CESAR_CRYPT_KEY;
		szText[i] ^= _XOR_CRYPT_KEY;
	}
}