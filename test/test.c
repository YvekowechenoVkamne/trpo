#include <../testparty/ctest/ctest.h>
#include <funcs/funcs.h>
#include <stdlib.h>

CTEST(string_into_digit, test1)
{
    char* ch = "123321";
    float exp_digit = 123321;
    float get_digit = string_into_digit(ch);
    ASSERT_EQUAL(exp_digit, get_digit);
}

CTEST(list_createnode, correctly_list_createnode)
{
    char* key = "Test";
    float value = 1.22;
    int minutes = 1;
    int gig = 2;
    struct Listnode* exp_node;
    exp_node = malloc(sizeof(*exp_node));
    exp_node->key = key;
    exp_node->value = value;
    exp_node->minutes = minutes;
    exp_node->gig = gig;
    struct Listnode* get_node = list_createnode(key, value, minutes, gig);
    ASSERT_STR(exp_node->key, get_node->key);
    ASSERT_EQUAL(exp_node->value, get_node->value);
    ASSERT_EQUAL(exp_node->minutes, get_node->minutes);
    ASSERT_EQUAL(exp_node->gig, get_node->gig);
}

CTEST(list_addfront, correctly_list_addfront)
{
    struct Listnode* exp_node;
    exp_node = malloc(sizeof(*exp_node));
    char* key = "Test";
    float value = 1.22;
    int minutes = 1;
    int gig = 2;
    exp_node->key = key;
    exp_node->value = value;
    exp_node->minutes = minutes;
    exp_node->gig = gig;
    struct Listnode* get_node;
    get_node = malloc(sizeof(*get_node));
    get_node = list_addfront(get_node, key, value, minutes, gig);
    ASSERT_STR(exp_node->key, get_node->key);
    ASSERT_EQUAL(exp_node->value, get_node->value);
    ASSERT_EQUAL(exp_node->minutes, get_node->minutes);
    ASSERT_EQUAL(exp_node->gig, get_node->gig);
}

CTEST(store_in_list, correctly_store_in_list)
{
    struct Listnode* exp_node;
    exp_node = malloc(sizeof(*exp_node));
    char* key = "Test";
    float value = 1.22;
    int minutes = 1;
    int gig = 2;
    exp_node->key = key;
    exp_node->value = value;
    exp_node->minutes = minutes;
    exp_node->gig = gig;
    int n = 4;
    char** dict;
    dict = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i <= n; i++) {
        dict[i] = (char*)malloc(200 * sizeof(char));
    }
    dict[0] = "Test";
    dict[1] = "1.22";
    dict[2] = "1";
    dict[3] = "2";
    struct Listnode* get_node;
    get_node = malloc(sizeof(*get_node));
    get_node = store_in_list(get_node, dict, n);
    ASSERT_STR(exp_node->key, get_node->key);
    ASSERT_EQUAL(exp_node->value, get_node->value);
    ASSERT_EQUAL(exp_node->minutes, get_node->minutes);
    ASSERT_EQUAL(exp_node->gig, get_node->gig);
}

CTEST(list_lookup, correctly_list_lookup)
{
    struct Listnode* exp_node;
    exp_node = malloc(sizeof(*exp_node));
    char* key = "Test";
    exp_node->key = key;
    struct Listnode* get_node;
    get_node = malloc(sizeof(*get_node));
    get_node = list_lookup(exp_node, "Test");
    ASSERT_STR(exp_node->key, get_node->key);
}

CTEST(str_check, correctly_str_check)
{
    char* str = "12";
    int exp_ret = 0;
    int get_ret = str_check(str);
    ASSERT_EQUAL(exp_ret, get_ret);
}

CTEST(check_for_q1, correctly_check_for_q1)
{
    char* str = "1.22";
    int exp_ret = 0;
    int get_ret = check_for_q1(str);
    ASSERT_EQUAL(exp_ret, get_ret);
}
