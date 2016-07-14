// e-mail: unconditional_conditions@flare-on.com

#include <cstdio>

typedef unsigned int uint;

void decrypt(uint* data, uint* key){
	uint v0 = data[0],
		v1 = data[1];
	
	uint delta = 0xC6EF3720;
	
	for (uint i = 0; i < 32; i++) {
		v1 -= (key[3] + (v0 >> 5)) ^ (delta + v0) ^ (key[2] + (v0 << 4));
		v0 -= (key[1] + (v1 >> 5)) ^ (delta + v1) ^ (key[0] + (v1 << 4));
		delta += 0x61C88647;
	}
	
	data[0] = v0;
	data[1] = v1;
}

int main(){
	uint key[] = { '3210', '7654', 'BA98', 'FEDC' };
	
	uint data[] = {
		0xFADC7F56,
		0xC49927AA,
		0x92FC7C6C,
		0x1A476161,
		0xFD63B919,
		0x20B6F20C,
		0xFD5C2DC0,
		0x965471D9,
		0xFFF7434F,
		0x315D4CBB
	};

	uint length = 40;
	length /= 8;
	
	for (uint i = 0; i < length; i++) {
		decrypt(&data[i * 2], key);
	}
	
	for (uint i = 0; i < 40; i++) {
		printf("%c", ((char*) data)[i]);
	}
	
	return 0;
}