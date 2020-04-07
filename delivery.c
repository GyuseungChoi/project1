#include "delivery.h"

Delivery* brands[MAX_BRANDS];
int _count = 0;

int d_is_available(){
	int i;
	for(i=0; i<MAX_BRANDS; i++){
		if(brands[i]==NULL) {
#ifdef DEBUG
			printf("[DEBUG] brands[%d] is available! \n", i);
#endif
			return 1;
		}
	}
	return 0; 
}

int d_first_available(){
	int i;
	for(i=0; i<MAX_BRANDS; i++){
		if(brands[i]==NULL) return i;
	}
	return -1;
}

int d_count(){
	return _count;
}

void d_create(char* br, char* ca, char* pn, int pr, char* ev){
	int index = d_first_available();
	brands[index] = (Delivery*)malloc(sizeof(Delivery));
	Delivery* p = brands[index];
	strcpy(p->brand, br);
	strcpy(p->category, ca);
	strcpy(p->phone_number, pn);
	p->price = pr;
	strcpy(p->evaluation, ev);
	_count++;
}

Delivery* d_search_by_brand(char* br){
	int i;
	for(i=0; i<_count; i++){
		if(brands[i]!=NULL && strcmp(brands[i]->brand, br)==0){	
#ifdef DEBUG
			printf("[DEBUG] %s is recorded in brand[%d]\n", br, i);
#endif
			return brands[i];
		}
	}
	return NULL;
}

void d_update(Delivery* p, char* ca, char* pn, int pr, char* ev){
	strcpy(p->category, ca);
	strcpy(p->phone_number, pn);
	p->price = pr;
	strcpy(p->evaluation, ev);
}

void d_delete(Delivery* p){
	int i, index;
	for(i=0; i<_count; i++)
		if(brands[i]==p){
			index=i;
			break;
		}
	free(p);
	brands[index] = NULL;
	_count--;
}

char* d_to_string(Delivery* p){
	static char str[80];
	sprintf(str, "[%s] %s / %s / %d / %s", p->category, p->brand, p->phone_number, p->price, p->evaluation);
	return str;
}

void d_get_all(Delivery* a[]){
	int i, c=0;
	for(i=0; i<MAX_BRANDS; i++){
		if(brands[i]!=NULL){
			a[c]=brands[i];
			c++;
		}
	}
}

void d_get_all2(Delivery* a[]){
	int i;
	for(i=0; i<MAX_BRANDS; i++){
		a[i]=brands[i];

	}
}

char* d_get_brand(Delivery* p){
	return p->brand;
}

char* d_get_category(Delivery* p){
	return p->category;
}

char* d_get_phone_number(Delivery* p){
	return p->phone_number;
}

int d_get_price(Delivery* p){
	return p->price;
}

char* d_get_evaluation(Delivery* p){
	return p->evaluation;
}

int d_get_all_by_category(Delivery* a[], char* n){
	int i, c=0;
	for(i=0; i<_count; i++){
		if(brands[i]!=NULL && strstr(brands[i]->category, n)){
			a[c]=brands[i];
			c++;
#ifdef DEBUG
			printf("[DEBUG] Loaded %s\n", brands[i]->brand);
#endif
		}
	}
	return c;
}

int d_get_all_by_price_range(Delivery* a[], int pr1, int pr2){
	int i, c=0;
	for(i=0; i<_count; i++){
		if(brands[i]!=NULL && brands[i]->price >= pr1 && brands[i]->price <= pr2){
			a[c]=brands[i];
			c++;
#ifdef DEBUG
			printf("[DEBUG] Loaded %s\n", brands[i]->brand);
#endif
		}
	}
	return c;
}

int d_get_all_by_evaluation(Delivery* a[], char* n){
	int i, c=0;
	for(i=0; i<_count; i++){
		if(brands[i]!=NULL && strstr(brands[i]->evaluation, n)) {
			a[c]=brands[i];
			c++;
#ifdef DEBUG
			printf("[DEBUG] Loaded %s\n", brands[i]->brand);
#endif
		}
	}
	return c;
}

void d_init(){
	int i;
	for(i=0; i<MAX_BRANDS; i++){
		if(brands[i]!=NULL){
			free(brands[i]);
		}
		brands[i] = NULL;
	}
	_count = 0;
}	

char* d_to_string_save(Delivery* p){
	static char str[80];
	sprintf(str, "%s %s %s %d %s", p->brand, p->category, p->phone_number, p->price, p->evaluation);
#ifdef DEBUG
	printf("[DEBUG] %s is saved\n", p->brand);
#endif
	return str;
}

