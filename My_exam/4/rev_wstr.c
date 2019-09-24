/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:21:39 by tjuzen            #+#    #+#             */
/*   Updated: 2019/05/07 14:21:40 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int        main(int argc, char *argv[])
{
    int        i;
    int        j;
    int        num;
    char    words[256][4096];
    
    if (argc == 2)
    {
        i = 0;
        j = 0;
        num = 0;
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] == ' ')
            {
                num += 1;
                i += 1;
                j = 0;
            }
            words[num][j] = argv[1][i];
            i += 1;
            j += 1;
        }
        j = 0;
        while (num >= 0)
        {
            if (words[num][j] == '\0')
            {
                if (num > 0)
                    write(1, " ", 1);
                if (num == 0 && words[num][j] == '\0')
                    break ;
                num -= 1;
                j = 0;
            }
            write(1, &words[num][j], 1);
            j += 1;
        }
    }
    write(1, "\n", 1);
    return (0);
}