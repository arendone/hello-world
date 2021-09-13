/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:41:08 by marvin            #+#    #+#             */
/*   Updated: 2021/09/13 11:41:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *s1);

int len_int(int n)
{
    int len;
    int d;

    len = 1;
    d = 10;

    if (n == -2147483648)
        len = 11;
    else
    {
        if (n < 0)
        {
            n = n * (-1);
            len++;
        }
        while (d <= n)
        {
            len++;
            if(d == 1000000000)
                break;
            d = d * 10;
        }
    }
    return (len);
}

char    *ft_itoa(int n)
{
    char *str;
    int     i;
    int     len;

    i = 0;
    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    else
    {
        len = len_int(n) ;
        str = (char *)malloc(len + 1);
        if (str == NULL)
            return (NULL);
        if (n < 0)
        {
            str[i] = '-';
            i++;
            n = n * (-1);
        }
        str[len] = '\0';
        while (--len >= i)
        {
            str [len] = '0' + (n % 10);
            n = (n - (n % 10)) / 10;
        }
        return (str);
    }
}

int main(void)
{
    char str[12];

    printf("%s \n", itoa(-0, str, 10));
    printf("%s \n", ft_itoa(-12345));
    printf("%s \n", ft_itoa(-0));
    printf("%s \n", ft_itoa(-2147483648));
    printf("%s \n", ft_itoa(-2147483640));
    printf("%s \n", ft_itoa(2147483647));
}