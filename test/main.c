#define CTEST_MAIN
/*
#include <ctest.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
*/

#include <stdio.h>

int main(int argc, const char* argv[])
{
    argc++;
    while (*++argv)
        puts(*argv);
    return 0;
}
