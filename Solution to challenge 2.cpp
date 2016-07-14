#include "stdafx.h"
#include <iostream>

int main() {
	char encrypted_key[] = "\xFF\xAF\xAA\xAD\xEB\xAE\xAA\xEC\xA4\xBA\xAF\xAE\xAA\x8A\xC0\xA7\xB0\xBC\x9A\xBA\xA5\xA5\xBA\xAF\xB8\x9D\xB8\xF9\xAE\x9D\xAB\xB4\xBC\xB6\xB3\x90\x9A\xA8";
	char* k = &encrypted_key[sizeof(encrypted_key) - 2];

	short accumulator = 0;
	int i = 37;
	while (i--) {
		int pad = _rotl(1, accumulator & 3);
		char proper_key = ((*k - pad - 1) ^ 0xC7) & 0xFF;

		printf("%c", proper_key);

		accumulator += *k;
		k--;
	}

	printf("\n");

	return 0;
}