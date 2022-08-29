#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Vending_Machine.h"

void print_product_list(Product* p)
{
	printf("=========\n");
	printf("name, price, nums, views\n");
	for (int i = 0; i < 100; i++) {
		printf("%d. %s, %d, %d, %d\n", i + 1, p[i].name, p[i].price, p[i].nums, p[i].views);
	}
}

void print_search_menu()
{
	printf(">>");
}

void do_search(Product* p)
{
	char input[40];
	scanf("%s", input);
	run_search(p, input);
}

void run_search(Product* p, char* ser_input)
{
	for (int i = 0; i < 100; i++) {
		if (strcmp(p[i].name, ser_input) == 0) {
			p[i].views++;
			printf("name, price, nums, views\n");
			printf("%d. %s, %d, %d, %d\n", i + 1, p[i].name, p[i].price, p[i].nums, p[i].views);
			break;
		}
		else if (i == 99) {
		}
	}
}

void print_delete_menu()
{
	printf("1. Delete One (Some)\n");
	printf("2. Delete One (All)\n");
	printf("3. Delete All (All)\n");
	printf(">>");
}

void do_delete(Product* p)
{
	int num; char del_input[40];
	scanf("%d", &num);
	if (num == 1 || num == 2) {
		printf("Enter delete product name: ");
		scanf("%s", &del_input);
	}
	run_delete(p, num, del_input);
}

void run_delete(Product* p, int num, char del_input[40])
{

	if (num == 1) {
		int i = 0;
		int n;
		printf("How many?: ");
		scanf("%d", &n);
		for (i; i < 100; i++) {
			if ((strcmp(p[i].name, del_input) == 0)) {
				p[i].nums -= n;
				break;
			}
			else if (i == 99) {
				break;
			}
		}
		printf("name, price, nums, views\n");
		printf("%d. %s, %d, %d, %d\n", i + 1, p[i].name, p[i].price, p[i].nums, p[i].views);
	}

	else if (num == 2) {
		int i = 0;
		for (i; i < 100; i++) {
			if ((strcmp(p[i].name, del_input) == 0)) {
				strcpy(p[i].name, "empty");
				p[i].price = 0;
				p[i].nums = 0;
				p[i].views = 0;
				break;
			}
			else if (i == 99) {
				break;
			}
		}
		printf("name, price, nums, views\n");
		printf("%d. %s, %d, %d, %d\n", i + 1, p[i].name, p[i].price, p[i].nums, p[i].views);
	}

	else if (num == 3) {
		for (int i = 0; i < 100; i++) {
			strcpy(p[i].name, "empty");
			p[i].price = 0;
			p[i].nums = 0;
			p[i].views = 0;
		}
		print_product_list(p);
	}
}

void print_insert_menu()
{
	printf("1. Insert Already Exist\n");
	printf("2. Insert New\n");
	printf(">>");
}

void do_insert(Product* p)
{
	int num;
	scanf("%d", &num);
	run_insert(&p[0], num);
}

void run_insert(Product* p, int num)
{
	if (num == 1) {
		char ins_input[40];
		int n;
		printf("Enter insert product name: ");
		scanf("%s", ins_input);
		printf("How many do you want to insert: ");
		scanf("%d", &n);
		for (int i = 0; i < 100; i++) {
			if ((strcmp(p[i].name, ins_input) == 0)) {
				p[i].nums = p[i].nums + n;
				printf("name, price, nums, views\n");
				printf("%d. %s, %d, %d, %d\n", i + 1, p[i].name, p[i].price, p[i].nums, p[i].views);
				break;
			}
			else if (i == 99) {
				printf("There is no product you want to insert");
				break;
			}
		}
	}

	else if (num == 2) {
		char ins_input[40];
		int price;
		int nums;

		printf("Enter new insert product name: ");
		scanf("%s", ins_input);

		printf("Enter product price: ");
		scanf("%d", &price);

		printf("Enter number of product: ");
		scanf("%d", &nums);

		for (int i = 0; i < 100; i++) {
			if ((strcmp(p[i].name, "empty") == 0)) {
				strcpy(p[i].name, ins_input);
				p[i].price = price;
				p[i].nums = nums;
				p[i].views = 0;
				printf("%d. %s, %d, %d, %d\n", i + 1, p[i].name, p[i].price, p[i].nums, p[i].views);
				break;
			}
		}
	}
}

void run_initialization(Product* p, FILE* fp, int m)
{
	for (int i = 0; i < m; i++)
	{
		strcpy(p[i].name, "empty");
		p[i].price = 0;
		p[i].nums = 0;
		p[i].views = 0;
		fprintf(fp, "%s\n", p[i].name);
		fprintf(fp, "%d\n", p[i].price);
		fprintf(fp, "%d\n", p[i].nums);
		fprintf(fp, "%d\n", p[i].views);
	}
}