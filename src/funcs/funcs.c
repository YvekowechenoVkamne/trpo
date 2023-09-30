#include <ctype.h>
#include <funcs/funcs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float string_into_digit(char* c)
{
    double a = atof(c);
    float b = (float)a;
    return b;
}

char* write_in_array(void)
{
    FILE* in = fopen("dictionary.txt", "r");
    char** str = (char**)malloc(sizeof(char*));
    int n = 0;
    for (int x = 0; x < 4; x++) {
        str[n] = (char*)malloc(sizeof(char) * 256);
        fgets(str[n], 256, in);
        n++;
        str = (char**)realloc(str, sizeof(char*) * (n + 1));
    }
    fclose(in);
    return *str;
}

list* list_createnode(char* key, float value, int mnts, int gig)
{
    list* p;

    p = malloc(sizeof(*p));
    if (p != NULL) {
        p->key = key;
        p->value = value;
        p->minutes = mnts;
        p->gig = gig;
        p->next = NULL;
    }
    return p;
}

list* list_addfront(list* node, char* key, float value, int mnts, int gig)
{
    list* newnode;

    newnode = list_createnode(key, value, mnts, gig);
    if (newnode != NULL) {
        newnode->next = node;
        return newnode;
    }
    return node;
}

list* list_lookup(list* node, char* key)
{
    for (; node != NULL; node = node->next) {
        if (strcmp(key, node->key) == 0)
            return node;
    }
    return NULL;
}

void list_print(list* p)
{
    puts("We offer You: ");
    printf("%s\n%.2f$\n%d minutes\n%d gigabytes\n",
           p->key,
           p->value,
           p->minutes,
           p->gig);
}

list* store_in_list(list* node, char** str, int n)
{
    float digit;
    int mnts;
    int gig;

    for (int i = 0; i < n; i += 4) {
        digit = string_into_digit(str[i + 1]);
        mnts = atoi(str[i + 2]);
        gig = atoi(str[i + 3]);
        node = list_addfront(node, str[i], digit, mnts, gig);
    }
    free(str);
    return node;
}

list* list_lookup_offer(
        list* node,
        float curr_price,
        int curr_minutes,
        int curr_gb,
        float payment,
        int option)
{
    for (; node != NULL; node = node->next) {
        if ((curr_minutes < node->minutes && curr_price < node->value)
            || (curr_gb < node->gig
                && (option == 3 || option == 2 || option == 4))) {
            return node;
        } else if (
                curr_minutes > node->minutes && curr_price > node->value
                && payment < node->value) {
            return node;
        }
    }
    return node;
}

int str_check(char* str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (strlen(str) > 1 && str[0] != '.' && str[0] != '0') {
            if (isdigit(str[i])) {
                continue;
            }
            if (isalpha(str[i])) {
                printf("Incorrect data.\n*%c*\n", str[i]);
                return -1;
            }
            if (str[i] == '.' || str[i] == ',' || str[i] == '-' || str[i] == '?'
                || str[i] == '!' || str[i] == '+' || str[i] == '=') {
                printf("Incorrect data.\n*%c*\n", str[i]);
                return -1;
            }
        } else {
            printf("Incorrect data.\n*%c*\n", str[i]);
            return -1;
        }
    }
    return 0;
}

int check_for_q1(char* str)
{
    int cnt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            cnt++;
        }
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (strlen(str) > 1 && str[0] != '.' && str[0] != '0' && cnt > 0
            && cnt < 2) {
            if (isdigit(str[i]) && str[0] != '.') {
                continue;
            }
            if (isalpha(str[i])) {
                printf("Incorrect data.\n*%c*\n", str[i]);
                return -1;
            }
            if (str[i] == ',' || str[i] == '-' || str[i] == '!' || str[i] == '?'
                || str[i] == '+' || str[i] == '=') {
                printf("Incorrect data.\n*%c*\n", str[i]);
                return -1;
            }
        } else {
            printf("Incorrect data.*\n*Please enter accurate price.\n");
            return -1;
        }
    }
    return 0;
}

void feedback(void)
{
    puts("Thank You for using our app!\nWe will appreciate You if You leave a "
         "comment about our service.\n");
    char* str = malloc(100 * sizeof(char));
    printf("Comment: ");
    fgets(str, 100, stdin);
    system("clear");
    puts("Thank You for your feedback.\n");
}

float question_1(void)
{
    puts("What is the price of your current rate?\nPlease enter accurate price "
         "for us to offer a better new rate for You.\n");
    char* curr_price = malloc(10 * sizeof(char));
    float digit;
    printf("Input data: ");
    fgets(curr_price, 10, stdin);
    while (check_for_q1(curr_price) == -1) {
        printf("Input data: ");
        fgets(curr_price, 10, stdin);
        system("clear");
    }
    digit = string_into_digit(curr_price);
    free(curr_price);
    return digit;
}

int question_2(void)
{
    puts("How many minutes do You spend on calls?");
    char* curr_minutes = malloc(10 * sizeof(char));
    int digit;
    printf("Input data: ");
    fgets(curr_minutes, 10, stdin);
    while (str_check(curr_minutes) == -1) {
        printf("Input data: ");
        fgets(curr_minutes, 10, stdin);
        system("clear");
    }
    digit = atoi(curr_minutes);
    free(curr_minutes);
    return digit;
}

int question_3(void)
{
    puts("How many gigabytes of traffik do You usually spend?\n");
    char* curr_gb = malloc(10 * sizeof(char));
    int digit;
    printf("Input data: ");
    fgets(curr_gb, 10, stdin);
    while (str_check(curr_gb) == -1) {
        printf("Input data: ");
        fgets(curr_gb, 10, stdin);
        system("clear");
    }
    digit = atoi(curr_gb);
    free(curr_gb);
    return digit;
}

float question_4(void)
{
    puts("How much do You want to pay for service?\n");
    char* pay = malloc(10 * sizeof(char));
    int digit;
    printf("Input data: ");
    fgets(pay, 10, stdin);
    while (str_check(pay) == -1) {
        printf("Input data: ");
        fgets(pay, 10, stdin);
        system("clear");
    }
    digit = atoi(pay);
    float dot = (float)digit;
    free(pay);
    return dot;
}

int question_5(void)
{
    puts("For what do You usually use your phone?\nChoose one of the options "
         "below:\n");
    puts("1: Calls and SMS.\n2: Social media.\n3: Moblie games, browser "
         "etc.\n4: All options.\n");

    char* p = malloc(10 * sizeof(char));
    while (1) {
        printf("Input data: ");
        fgets(p, 10, stdin);
        if (strlen(p) == 2) {
            if (p[0] == '1' || p[0] == '2' || p[0] == '3' || p[0] == '4') {
                return p[0] - '0';
            }
            if (isalpha(p[0])) {
                printf("No such option.\n");
                continue;
            } else {
                printf("No such option.\n");
            }
        } else {
            printf("No such option.\n");
        }
    }
    return -1;
}

void main_offer(void)
{
    list* node = malloc(sizeof(*node));

    // store in array
    FILE* in = fopen("source.txt", "r");
    if (in == NULL) {
        printf("Error.\n");
        return;
    }
    char** str = (char**)malloc(sizeof(char*));
    int n = 0;
    for (int x = 0; x < 28; x++) {
        str[n] = (char*)malloc(sizeof(char) * 256);
        fgets(str[n], 256, in);
        n++;
        str = (char**)realloc(str, sizeof(char*) * (n + 1));
    }
    fclose(in);

    node = store_in_list(node, str, n);
    // printf("%s\n\n", node->key);

    char* restart = malloc(10 * sizeof(char));

    while (1) {
        float curr_price = question_1();
        int curr_minutes = question_2();
        int curr_gb = question_3();
        float payment = question_4();
        int option = question_5();
        list* new_offer = list_lookup_offer(
                node, curr_price, curr_minutes, curr_gb, payment, option);
        list_print(new_offer);
        puts("\nIf You don't like your new rate You can use app one more "
             "time!\nDo You want to use it one more time?\n");
        printf("Yes: 1.\nNo: Any key.\n");
        fgets(restart, 10, stdin);

        if (strlen(restart) == 2) {
            if (restart[0] == '1') {
                continue;
            }
            if (isalpha(restart[0] || strlen(restart) > 2)) {
                free(restart);
                break;
            } else {
                free(restart);
                break;
            }
        } else {
            break;
        }
    }
    feedback();
    free(node);
}
