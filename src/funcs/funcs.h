#pragma once

typedef struct Listnode {
    char* key;
    float value;
    int minutes;
    int gig;
    struct Listnode* next;
} list;

float string_into_digit(char* c);

char* write_in_array(void);

list* list_createnode(char* key, float value, int mnts, int gig);

list* list_addfront(list* node, char* key, float value, int mnts, int gig);

list* list_lookup(list* node, char* key);

void list_print(list* node);

list* store_in_list(list* node, char** str, int n);

list* list_lookup_offer(
        list* node,
        float curr_price,
        int curr_minutes,
        int curr_gb,
        float payment,
        int option);

int str_check(char* str);

int check_for_q1(char* str);

void feedback(void);

float question_1(void);

int question_2(void);

int question_3(void);

float question_4(void);

int question_5(void);

int check(int restart);

void main_offer();