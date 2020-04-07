#include "delivery.h"

void create_record();
void read_record();
void update_record();
void delete_record();
void list_record();
void search_category();
void search_price_range();
void search_evaluation();
void load_file();
void save_file();
void debug_records();
int main(){
	d_init();
	int menu;
	while(1){
		printf("\nMenu : 1.Create 2.Read 3.Update 4.Delete 5.list 6.Search(category) 7.Search(evaluation) 8.Search(price_range) 9.Load 10.Save 0.Quit> ");
		scanf("%d", &menu);
#ifdef DEBUG
		printf("[DEBUG]menu is %d", menu);
#endif
		printf("\n");
		switch(menu){
			case 1:
				create_record();
				break;
			case 2:
				read_record();
				break;
			case 3:
				update_record();
				break;
			case 4:
				delete_record();
				break;
			case 5:
				list_record();
				break;
			case 6:
				search_category();
				break;
			case 7:
				search_evaluation();
				break;
			case 8:
				search_price_range();
				break;
			case 9:
				load_file();
				break;
			case 10:
				save_file();
				break;
			case 11:
				debug_records();
				break;
			case 0:	
			default:
				return 0;
		}
	}
	return 0; 
}
void create_record(){
	if(!d_is_available()) {
		printf("There is no space!\n");
		return;
	}
	char brand[20], category[20], phone_number[20], evaluation[20];
	int price;
	printf("Enter a new brand's info.\n");
	printf("Brand> ");
	scanf("%s", brand);
	if(d_search_by_brand(brand)) {
		printf("Duplicated brand!\n");
		return;
	}
	printf("Category > ");
	scanf("%s", category);
	printf("Phone number > ");
	scanf("%s", phone_number);
	printf("Price > ");
	scanf("%d", &price);
	printf("Evaluation > ");
	scanf("%s", evaluation);
	d_create(brand, category, phone_number, price, evaluation);
	printf("1 brand is created!");
	printf("\n");
}

void read_record(){
	char brand[20];
	printf("Enter a brand > ");
	scanf("%s", brand);

	Delivery* p = d_search_by_brand(brand);
	if(p) {
		printf("Brand info.\n");
		printf("Brand : %s\n", d_get_brand(p));
		printf("Category : %s\n", d_get_category(p));
		printf("Phone number : %s\n", d_get_phone_number(p));
		printf("Price : %d\n", d_get_price(p));
		printf("Evaluation : %s\n", d_get_evaluation(p));
	}
	else {
		printf("No such member!\n");
	}
}

void update_record(){
	char brand[20], category[20], phone_number[20], evaluation[20];
	int price;
	printf("Enter a brand > ");
	scanf("%s", brand);

	Delivery* p = d_search_by_brand(brand);
	if(p){
		printf("Enter a updated info.\n");
		printf("Category > ");
		scanf("%s", category);
		printf("Phone number > ");
		scanf("%s", phone_number);
		printf("Price > ");
		scanf("%d", &price);
		printf("Evaluation > ");
		scanf("%s", evaluation);

		d_update(p, category, phone_number, price, evaluation);
#ifdef DEBUG
		printf("[DEBUG] %s is updated", brand);
#endif
	}
	else {
		printf("No such brand!\n");
	}
}

void delete_record(){
	char brand[20];
	printf("Enter a brand > ");
	scanf("%s", brand);

	Delivery* p = d_search_by_brand(brand);
	if(p){
		d_delete(p);
		printf("The record is deleted!\n");
	}
	else {
		printf("No such member!\n");
	}
}

void list_record(){
	printf("All records.\n");
	int size = d_count();
	Delivery* records[MAX_BRANDS];
	d_get_all(records);
	for(int i=0; i<size; i++){
		Delivery* p = records[i];
#ifdef DEBUG
		printf("[DEBUG] %s is printed\n", records[i]->brand);
#endif
		printf("%d. %s\n", i+1, d_to_string(p));
	}
}

void search_category(){
	char category[20];
	printf("Enter a category> ");
	scanf("%s", category);

	Delivery* records[MAX_BRANDS];
	int size = d_get_all_by_category(records, category);
	printf("%d records found.\n", size);
	for(int i=0; i<size; i++){
		Delivery* p = records[i];
		printf("%d. %s\n", i+1, d_to_string(p));
	}
}

void search_price_range(){
	int pr1, pr2;
	printf("Enter a price range to start> ");
	scanf("%d", &pr1);
	printf("Enter a price range to end> ");
	scanf("%d", &pr2);
	Delivery* records[MAX_BRANDS];
	int size = d_get_all_by_price_range(records, pr1, pr2);
	printf("%d records found.\n", size);
	for(int i=0; i<size; i++){
		Delivery* p = records[i];
		printf("%d %s\n", i+1, d_to_string(p));
	}
}

void search_evaluation(){
	char evaluation[20];
	printf("Enter a evaluation> ");
	scanf("%s", evaluation);

	Delivery* records[MAX_BRANDS];
	int size = d_get_all_by_evaluation(records, evaluation);
	printf("%d records found.\n", size);
	for(int i=0; i<size; i++){
		Delivery* p = records[i];
		printf("%d. %s\n", i+1, d_to_string(p));
	}
}

void load_file(){
	printf("All data will be deleted and new records will be reloaded.\n");
	printf("1.Yes 0.No > ");
	int yesno;
	scanf("%d", &yesno);
	if (yesno == 0) return;
	d_init();

	FILE* f = fopen("brands.txt", "r");
	char brand[20], category[20], phone_number[20], evaluation[20];
	int price;
	while(!feof(f)){
		if(!d_is_available()){
			printf("[Load] There is no space!\n");
			break;
		}
		int n = fscanf(f,"%s %s %s %d %s", brand, category, phone_number, &price, evaluation);
		if (n<5) break;
		if(d_search_by_brand(brand)){
			printf("[Load] Duplicated name(%s)! loading.\n", brand);
			continue;
		}
		d_create(brand, category, phone_number, price, evaluation);
#ifdef DEBUG
		printf("[DEBUG] Loaded %s\n", brand);
#endif
	}
	printf("%d records are read from file!\n", d_count());
	fclose(f);
}

void save_file(){
	FILE* f = fopen("brands.txt", "w");
	printf("All records.\n");
	int size = d_count();
	Delivery* records[MAX_BRANDS];
	d_get_all(records);
	for(int i=0; i<size; i++){
		Delivery* p = records[i];
		fprintf(f,"%s\n", d_to_string_save(p));
	}
	fclose(f);
}

void debug_records(){
	Delivery* records[MAX_BRANDS]={0};
	d_get_all2(records);
	for(int i=0; i<MAX_BRANDS; i++){
		printf("%d - %p\n", i , records[i]);
	}
}
