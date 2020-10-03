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

	

	int kom = 0;

	printf("\nWhat do you want to do?\nAdd new element - 1\nFind one el - 2\nSearch in the interval (stupid) - 3\nWalk away - 4\nPrint the tree - 5\nSearch in the interval (smart) - 6");
	printf("\n");
	while (kom != 4)
	{
		printf("\nWhat?! ");
		printf("\n");
		kom = geti();
		if (kom == 1)
		{
			printf("\nEnter a new element: ");
			int new = geti();
			printf("\n");
			tree = add(tree, new);
			printf("\nSuccessfully!\n");
		}

		if (kom == 2)
		{
			printf("\nInput one el for find : ");
			int f = geti();
			if (findone(tree, f))
				printf("\nYEEEES! Key = %d FINDDDD!!!!!!!\n", findonekey(tree, f));
			else
				printf("\nOHHH NOOOO!\n");
		}

		if (kom == 3)
		{
			printf("\nInput first border for find : ");
			int f = geti();
			printf("\nInput second border for find : ");
			int ff = geti();
			findintervals(tree, f, ff);
			printf("\n");
		}

		if (kom == 4)
		{
			free(tree);
			free(array);
			free(res);
			return 0;
		}

		if (kom == 5)
		{
			printf("\nOur tree of life!\n"); 
			in(tree);
			printf("\n");
		}

		if (kom == 6)
		{
			printf("\nInput first border for find : ");
			int f = geti();
			printf("\nInput second border for find : ");
			int ff = geti();
			findintervalsm(tree, f, ff);
			printf("\n");
		}
	}
	
}
