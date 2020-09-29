#include "header.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>


int geti()
{
	char ci = 0;
	int n;

	while ((ci != "\n") || (ci != " "))
	{
		scanf("%d", &n);
		ci = getchar();
		if ((ci == 10) || (ci == 32))
		{
			break;
		}
	}
	return n;
}



//Добавление в дерево
TREE* add(TREE* root, int a)
{
	if (!root)
	{
		TREE* pnew = (TREE*)malloc(sizeof(TREE));
		pnew->key = a;
		pnew->left = NULL;
		pnew->right = NULL;
		root = pnew;
	}
	else if (a > root->key)
		root->right = add(root->right, a);
	else
		root->left = add(root->left, a);
	return root;
}

//Обход дерева
void in(TREE* root)
{
	if (root)
	{
		in(root->left);
		printf("%d\n", root->key);
		in(root->right);
	}
}

unsigned int Max_len(unsigned int prv_max, char* str)
{
	unsigned int len = strlen(str);
	if (prv_max > len)
		return prv_max;
	else
		return len;
}