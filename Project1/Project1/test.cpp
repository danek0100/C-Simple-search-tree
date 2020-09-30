#include "header.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 255




int main(int argc, char* argv[])
{
	FILE* fr = fopen(argv[1], "rb");
	if (!fr)
		return;
	fseek(fr, 0L, SEEK_END);
	long length = ftell(fr);
	fseek(fr, 0, SEEK_SET);

	unsigned char* res;
	res = (unsigned char*)malloc(sizeof(unsigned char) * (length + 1));
	for (int i = 0; i < length; i++)
	{
		res[i] = fgetc(fr);
	}
	res[length] = '\0';
	fclose(fr);

	char* cstr = strtok(res, " ,.-\n\r\t");
	unsigned int max_word_len = 0;
	unsigned int nword = 0;
	while (cstr != 0)
	{
		nword++;
		cstr = strtok(NULL, " ,.-\n\r\t");
	}

	fr = fopen(argv[1], "rb");
	if (!fr)
		return;
	fseek(fr, 0L, SEEK_END);
	length = ftell(fr);
	fseek(fr, 0, SEEK_SET);

	free(res);
	res = (unsigned char*)malloc(sizeof(unsigned char) * (length + 1));
	for (int i = 0; i < length; i++)
	{
		res[i] = fgetc(fr);
	}
	res[length] = '\0';
	fclose(fr);


	int* array = (int*)calloc(nword, sizeof(int));

	cstr = strtok(res, " ,.-\n\r\t");

	int i = 0;
	while (cstr != 0)
	{
		int len = strlen(cstr);
		int s = 1;
		for (int j = 0; j < len - 1; j++)
			s *= 10;
		for (int j = 0; j < len; j++)
		{
			array[i] += (cstr[j] - '0') * s;
			s /= 10;
		}
		i++;
		cstr = strtok(NULL, " ,.-\n\r\t");
	}

	TREE* tree = 0;

	for (int i = 0; i < nword; i++)
		tree = add(tree, array[i]);

	in(tree);

	printf("\nInput find: ");
	int f = geti();
	if (findone(tree, f))
		printf("\nYEEEES!\n");
	else
		printf("\nOHHH NOOOO!\n");
}
