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
#include <Wincrypt.h>
#include <stdio.h>
#define MY_ENCODING_TYPE  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)
#include "base64.h"
#include "rc4.h"

bool CryptoInit(HCRYPTPROV *hCryptProv)
{
	if (!CryptAcquireContextW(hCryptProv, NULL, NULL, PROV_RSA_FULL, 0))
	{
		if (GetLastError() == NTE_BAD_KEYSET)
		{
			if (!CryptAcquireContextW(hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_NEWKEYSET))
			{
				printf("Error: %d\n", GetLastError());
				return false;
			}
		}
		else
		{
			printf("Error: %d\n", GetLastError());
			return false;
		}
	}

	return true;
}

void CryptoUninit(HCRYPTPROV hCryptProv)
{
	if (hCryptProv)	if (!CryptReleaseContext(hCryptProv, 0)) printf("Error: %d\n", GetLastError());
}
