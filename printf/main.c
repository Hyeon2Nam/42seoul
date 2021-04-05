#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int ft_printf(const char *str, ...);

int main()
{
    int a = 5;
    int b = 3;
    // char c = 'a';
    // int d = 2147483647;
    // int e = -2147483648;
    int f = 8;
    // int g = 25;
    // int h = 1234;
    // int i = 8;
    // int j = -12;
    // int k = 123456789;
    // int l = 0;
    // int m = -12345678;
    // char *n = "abcdefghijklmnop";
    // char *o = "-a";
    // char *p = "-12";
    // char *q = "0";
    // char *r = "%%";
    // char *s = "-2147483648";
    // char *t = "0x12345678";
    // char *u = "-0";

    printf("1. %*.*d\n", a, b, f);
    ft_printf("2. %*.*d\n", a, b, f);
}

//gcc -Wall -Wextra -Werror main.c put_*c ft_printf.c -L../libft -lft