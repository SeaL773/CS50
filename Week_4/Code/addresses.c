#include "cs50.h"
#include <stdio.h>

/* int main(void)
{
    int n = 50;
    // & Provides the address of something stored in memory.
    // * Instructs the compiler to go to a location in memory.
    // printf("%i\n", n);
    printf("%p\n", &n);
} */

/* int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);
} */

/* int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
} */

/* int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
} */

/* int main(void)
{
    char *s = "HI!";
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
} */

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}