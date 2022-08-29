#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "Vending_Machine.h"

int main()
{
	FILE* fp_read;
	FILE* fp_write;
	fp_read = fopen("Product.txt", "rt");
	if (fp_read == NULL) {
		printf("ERROR");
		return -1;
	}

	int m;
	printf("How many storage you need?\n");
	scanf("%d", &m);
	Product* p = (Product*)malloc(sizeof(Product) * m);

	int menu;
	for (int i = 0; i < m; i++)
	{
		fscanf(fp_read, "%s\n", p[i].name);
		fscanf(fp_read, "%d\n", &p[i].price);
		fscanf(fp_read, "%d\n", &p[i].nums);
		fscanf(fp_read, "%d\n", &p[i].views);

		/*
		print
		fprintf(fp, "%s\n", p[i].name);
		fprintf(fp, "%d\n", p[i].price);
		fprintf(fp, "%d\n", p[i].nums);
		fprintf(fp, "%d\n", p[i].views);
		*/
	}
	fclose(fp_read);
	fp_write = fopen("Product.txt", "w+");
	if (fp_write == NULL) {
		printf("ERROR");
		return -1;
	}

	printf("0. Show List\n");
	printf("1. Search\n");
	printf("2. Insert\n");
	printf("3. Delete\n");
	printf("4. Initialize\n");
	printf("5. Exit\n");
	printf(">> ");

	scanf("%d", &menu);

	switch (menu)
	{
	case 0: // Product List
		print_product_list(p);
		for (int i = 0; i < m; i++)
		{
			fprintf(fp_write, "%s\n", p[i].name);
			fprintf(fp_write, "%d\n", p[i].price);
			fprintf(fp_write, "%d\n", p[i].nums);
			fprintf(fp_write, "%d\n", p[i].views);
		}
		break;
	case 1: // Search
		print_search_menu();
		do_search(p);
		for (int i = 0; i < m; i++)
		{
			fprintf(fp_write, "%s\n", p[i].name);
			fprintf(fp_write, "%d\n", p[i].price);
			fprintf(fp_write, "%d\n", p[i].nums);
			fprintf(fp_write, "%d\n", p[i].views);
		}
		break;
	case 2: // Insert
		print_insert_menu();
		do_insert(p);
		for (int i = 0; i < m; i++)
		{
			fprintf(fp_write, "%s\n", p[i].name);
			fprintf(fp_write, "%d\n", p[i].price);
			fprintf(fp_write, "%d\n", p[i].nums);
			fprintf(fp_write, "%d\n", p[i].views);
		}
		break;
	case 3: // Delete
		print_delete_menu();
		do_delete(p);
		for (int i = 0; i < m; i++)
		{
			fprintf(fp_write, "%s\n", p[i].name);
			fprintf(fp_write, "%d\n", p[i].price);
			fprintf(fp_write, "%d\n", p[i].nums);
			fprintf(fp_write, "%d\n", p[i].views);
		}
		break;
	case 4: //Initialization
		run_initialization(p, fp_write, m);
		break;
	default:
		break;
	}

	fclose(fp_read);
	fclose(fp_write);
	free(p);

	return 0;
}