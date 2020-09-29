#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>


typedef struct tree
{
	int key;
	struct tree* left;
	struct tree* right;
}TREE; 


int geti();


#endif
