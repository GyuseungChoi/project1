#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BRANDS 50

typedef struct st_delivery{
	char brand[20];
	char category[20];
	char main_menu[20];
	char phone_number[20];
	int price;
	char evaluation[20];
} Delivery;

int d_is_available();
int d_first_available();
int d_count();
void d_create(char* br, char* ca, char* pn, char* ma, int  pr, char* ev);
Delivery* d_search_by_brand(char* br);
void d_update(Delivery* p, char* ca, char* pn, char* ma, int pr, char* ev );
void d_delete(Delivery* p);
void d_get_all(Delivery* a[]);
void d_get_all2(Delivery* a[]);
char* d_to_string(Delivery* p);
char* d_get_brand(Delivery* p);
char* d_get_category(Delivery* p);
char* d_get_main_menu(Delivery* p);
char* d_get_phone_number(Delivery* p);
int d_get_price(Delivery* p);
char* d_get_evaluation(Delivery* p);
int d_get_all_by_category(Delivery* a[], char* br);
int d_get_all_by_price_range(Delivery* a[], int pr1, int pr2);
int d_get_all_by_evaluation(Delivery* a[], char* br);
void d_init();
char* d_to_string_save(Delivery* p);
void d_make_report_category(FILE*f, char* ca);
void d_make_report_price(FILE* f, int pr1, int pr2);
void d_make_report_evauation(FILE* f, char* n);
void d_sort_price();
