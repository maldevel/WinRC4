/*
WinRC4 - RC4 Encryption with CryptoAPI and C
Copyright (C) 2016  @maldevel

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Windows.h>
#include <stdio.h>
#include "common.h"
#include "rc4.h"

int main(int argc, char **argv)
{
	/*char *encoded = 0;
	unsigned long encodedLen = 0, decodedLen = 0;
	char *decoded = 0;
	WCHAR *encodedW = 0;*/
	HCRYPTPROV hCryptProv = 0;

	if (argc != 2)
	{
		printf("usage: WinRC4.exe <string to encrypt>\n");
		return EXIT_FAILURE;
	}

	printf("\nText: %s\n", argv[1]);

	if (!CryptoInit(&hCryptProv))
	{
		printf("Hash 512 generation failed\n");
		return EXIT_FAILURE;
	}

	CryptoUninit(hCryptProv);

	/*if (Base64EncodeA(&encoded, &encodedLen, argv[1], strlen(argv[1])))
	{
		printf("Base64 encoded: %s\n", encoded);
		if (Base64DecodeA(&decoded, &decodedLen, encoded, encodedLen))
		{
			printf("Base64 decoded: %s\n", decoded);
			SAFE_FREE(encoded);
			SAFE_FREE(decoded);
		}
	}

	if (Base64EncodeW(&encodedW, &encodedLen, "tester", 6))
	{
		wprintf(L"Base64 encoded: %s\n", encodedW);
		if (Base64DecodeW(&decoded, &decodedLen, encodedW, encodedLen))
		{
			printf("Base64 decoded: %s\n", decoded);
			SAFE_FREE(encodedW);
			SAFE_FREE(decoded);
		}
	}*/

	return EXIT_SUCCESS;
}
