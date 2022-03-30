/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:34:58 by ghoyuelo          #+#    #+#             */
/*   Updated: 2022/01/11 13:35:47 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_char(char c)
{
    return (write(1, &c, 1));
}
int ft_str(char *c)
{
    int count;
    if (!c)
        return (write(1, "(null)", 6));
    count = 0;
    while (c[count])
        write(1, &c[count++], 1);
    return (count);
}
int ft_x(unsigned int nbr)
{
    int static  count;
    char        *base;
    base = "0123456789abcdef";
    count = 0;
    if (nbr > 15)
        ft_x(nbr / 16);
    count += ft_char(base[nbr % 16]);
    return (count);
}
int ft_nbr(int nbr)
{
    int count;
    count = 0;
    if (nbr == -2147483648)
        return (ft_str("-2147483648"));
    if (nbr < 0)
    {
        nbr *= -1;
        count = ft_char('-');
    }
    if (nbr > 9)
        count += ft_nbr(nbr / 10);
    count += ft_char(nbr % 10 + 48);
    return (count);
}
int def_arg(char format, va_list arg)
{
    int count;
    count = 0;
    if (format == 'x')
        count = ft_x(va_arg(arg, unsigned int));
    if (format == 's')
        count = ft_str(va_arg(arg, char *));
    if (format == 'd')
        count = ft_nbr(va_arg(arg, int));
    return (count);
}
int ft_printf(const char  *s, ...)
{
    va_list arg;
    int     count;
    int     i;
    va_start(arg, s);
    count = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] != '%')
        {
            ft_char(s[i]);
            i++;
            count++;
        }
        else
        {
            count += def_arg(s[i + 1], arg);
            i = i + 2;
        }
    }
    va_end(arg);
    return (count);
}
/*#include <stdio.h>
int main ()
{
    int a, b, c, d, e, f;
    a = ft_printf("Hello %s\n","toto");
    b = printf("Hello %s\n","toto");
    printf ("Printf real %d\n", b);
    printf ("Printf Fake %d\n", a);
    c = printf("Magic %s is %d\n", "number", 42);
    d = ft_printf("Magic %s is %d\n", "number", 42);
    printf ("Printf real %d\n", c);
    printf ("Printf fake %d\n", d);
    e = printf("Hexadecimal for %d is %x\n", 42, 42);
    f = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    printf ("Printf Real %d\n", e);
    printf ("Printf Fake %d\n", f);
return (0);
}
*/
#include <stdio.h>
#include <limits.h>
int main()
{
    int len = 0, len1 = 0;
    ft_printf("\n---SRING CASE---\n");
    len = printf("Printf: Estas son varias cadenas: %s, %s, %s, %s, %s.\n", "", "c", "4", "cadena ", NULL);
    len1 = ft_printf("Ft_printf: Estas son varias cadenas: %s, %s, %s, %s, %s.\n", "", "c", "4", "cadena ", NULL);
    printf("Printf = %d\tFt_printf = %d\n", len, len1 - 3);
    ft_printf("\n---LOWERHEX CASE---\n");
    len = printf("Printf: Estos son varios numeros en hexadecimal txiki: %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
    len1 = ft_printf("Ft_printf: Estos son varios numeros en hexadecimal txiki: %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
    len += printf("Printf: Estos son varios numeros en hexadecimal txiki: %x, %x, %x, %x, %x, %x, %x.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
    len1 += ft_printf("Ft_printf: Estos son varios numeros en hexadecimal txiki: %x, %x, %x, %x, %x, %x, %x.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
    printf("Printf = %d\tFt_printf = %d\n", len, len1 - 6);
    ft_printf("\n---DECIMAL CASE---\n");
    len = printf("Printf: Estos son varios numeros decimales: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
    len1 = ft_printf("Ft_printf: Estos son varios numeros decimales: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d.\n", 0, -1, 1, 15, 16, 17, 99, 100, 101, -15, -16, -17, -99, -100, -101);
    len += printf("Printf: Estos son varios numeros decimales: %d, %d, %d, %d, %d, %d, %d.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
    len1 += ft_printf("Ft_printf: Estos son varios numeros decimales: %d, %d, %d, %d, %d, %d, %d.\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
    printf("Printf = %d\tFt_printf = %d\n", len, len1 - 6);
}
