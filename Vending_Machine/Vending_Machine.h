typedef struct product
{
    char name[10];
    unsigned int price;
    unsigned int nums;
    unsigned int views;
}Product;

//print_menu_func
void print_product_list(Product* p);
void print_search_menu();
void print_insert_menu();
void print_delete_menu();
//void print_modify_menu();

//do_menu_func
void do_search(Product* p);
void do_insert(Product* p);
void do_delete(Product* p);
//void do_modify();

//run_func
void run_search(Product* p, char* ser_input);
void run_insert(Product* p, int num);
void run_delete(Product* p, int num, char del_input[40]);
void run_initialization(Product* p, FILE* fp, int m);
//void run_modify();