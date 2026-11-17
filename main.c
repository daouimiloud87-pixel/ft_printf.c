#include <stdio.h>
#include "ft_printf.h"



int	main(void)
{
	char a = 5;
	ft_printf("%d\n %u\n %s\n %x\n %X\n %%\n %c\n %i\n %p\n",122,-12,"hello",100,100,'A',12,&a);
	printf("sssss\n");
		printf("%d\n %u\n %s\n %x\n %X\n %%\n %c\n %i\n %p\n",122,-12,"hello",100,100,'A',12,&a);

}