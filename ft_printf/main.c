#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    ft_printf("\"%1.x\"\n", 0xee);
    printf("\"%1.x\"\n", 0xee);

    return (0);
}