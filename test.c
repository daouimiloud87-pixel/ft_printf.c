#include <stdarg.h>
#include <stdio.h>

int ft_sum_manual(int count,...)
{
    int i = 0;
    va_list p;
    va_start(p,count);
    char *pi;
    while(i < count)
    {
        va_arg()
        if(p->gp_offset<48)
        {
        pi = p->reg_save_area + p ->gp_offset;
        printf("%d\n",*(int *)pi );
        p->gp_offset =40;
        }
      
        i++;
    }
    va_end(p);
    return(1);

}

int main(void)
{
    ft_sum_manual(8, 42, 9,9,4,4,4,455,445);
    return 0;
}