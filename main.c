#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int a;
    int b;

    a = ft_printf("char: %c\n", 'A');
    b = printf("char: %c\n", 'A');

    ft_printf("string: %s\n", "Hello");
    printf("string: %s\n", "Hello");

    ft_printf("pointer: %p\n", (void *)main);
    printf("pointer: %p\n", (void *)main);

    ft_printf("decimal: %d\n", INT_MIN);
    printf("decimal: %d\n", INT_MIN);

    ft_printf("integer: %i\n", 42);
    printf("integer: %i\n", 42);

    ft_printf("unsigned: %u\n", UINT_MAX);
    printf("unsigned: %u\n", UINT_MAX);

    ft_printf("hex lower: %x\n", 255);
    printf("hex lower: %x\n", 255);

    ft_printf("hex upper: %X\n", 255);
    printf("hex upper: %X\n", 255);

    ft_printf("percent: %%\n");
    printf("percent: %%\n");

    printf("ft_printf count: %d\n", a);
    printf("printf count: %d\n", b);
    return (0);
}