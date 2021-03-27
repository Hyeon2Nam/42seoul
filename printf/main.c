#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int ft_printf(const char *str, ...);

#define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)

int main()
{
    int a = 2;
    int b = 0;
    char c = 'a';
    int d = 2147483647;
    int e = -2147483648;
    int f = 42;
    int g = 25;
    int h = 4200;
    int i = 8;
    int j = -12;
    int k = 123456789;
    int l = 0;
    int m = -12345678;
    char *n = "abcdefghijklmnop";
    char *o = "-a";
    char *p = "-12";
    char *q = "0";
    char *r = "%%";
    char *s = "-2147483648";
    char *t = "0x12345678";
    char *u = "-0";

    printf("1. %.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
    ft_printf("2. %.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);

}

//gcc main.c put_*c ft_printf.c -L../libft -lft