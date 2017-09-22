/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:34:03 by iprokofy          #+#    #+#             */
/*   Updated: 2017/09/18 11:34:05 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>

void	test_putchar(char *c)
{
	write(1, c, 1);
}

void	test_putchar2(unsigned int i, char *c)
{
	write(1, c, 1);
	printf("%u\n", i);
}

char	test_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	test_toupper2(unsigned int i, char c)
{
	printf("%u\n", i);
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
}

void	ft_lstdelone_test(void *ap, size_t s)
{
	free(ap);
	ap = NULL;
	s++;
}

void	ft_iterprint(t_list *node)
{
	printf("%s\n", node->content);
}

t_list	*list_to_app(t_list *elem)
{
	char	*str;

	if (elem)
	{
		str = elem->content;
		while (*str)
		{
			*str = ft_toupper(*str);
			str++;
		}
	}
	return (elem);
}

int		main()
{
	printf("<<<<<<<<<<<<>>>>>>>>>>>>\n");
	printf("<<<<<<<< PART_1 >>>>>>>>\n");
	printf("<<<<<<<<<<<<>>>>>>>>>>>>\n\n");

	printf("----- ft_memset -----\n");
	char c1[] = "this is string";
	char c2[] = "this is string";
	printf("expected: %s\treturned: %s\n", 
		memset(c1, 55, 5), ft_memset(c2, 55, 5));
	char c12[] = "string";
	char c22[] = "string";
	printf("expected: %s\t\treturned: %s\n", 
		memset(c12, 555, 5), ft_memset(c22, 555, 5));
	char c13[] = "";
	char c23[] = "";
	printf("expected: %s\t\t\treturned: %s\n", 
		memset(c13, 555, 0), ft_memset(c23, 555, 0));
	char c14[] = "this is string";
	char c24[] = "this is string";
	printf("expected: %s\treturned: %s\n", 
		memset(c14, 77, 14), ft_memset(c24, 77, 14));
	char c15[] = "this is string";
	char c25[] = "this is string";
	printf("expected: %s\treturned: %s\n", 
		memset(c15, 77, 0), ft_memset(c25, 77, 0));
	char	b1[10];
	char	b2[10];
	printf("expected: %s\treturned: %s\n", 
		memset(b1, 'A', 5), ft_memset(b2, 'A', 5));

	printf("----- ft_bzero -----\n");
	char bz1[] = "this";
	char bz2[] = "this";
	bzero(bz1, 5);
	ft_bzero(bz2, 5);
	printf("%c\n", bz1[3]);
	printf("%c\n", bz1[3]);

	printf("----- ft_memcpy -----\n");
	char mc1[] = "thissssssssss";
	char mc2[] = "1234567";
	//printf("%s\n", memcpy(mc1, mc2, 2));
	printf("%s\n", ft_memcpy(mc1, mc2, 7));

	printf("----- ft_memccpy -----\n");
	char mcc1[] = "thissssssssss";
	char mcc2[] = "1234567";
	char mcc12[] = "thissssssssss";
	char mcc22[] = "1234567";
	printf("%s %s\n", memccpy(mcc1, mcc2, '5', 8), mcc1);
	printf("%s %s\n", ft_memccpy(mcc12, mcc22, '5', 8), mcc12);

	printf("----- ft_memmove -----\n");
	char mm1[] = "this is string";
	char mm12[] = "this is string";
	printf("%s\n", memmove(mm1, mm1 + 10, 2));
	printf("%s\n", ft_memmove(mm12, mm12 + 10, 2));

	printf("----- ft_memchr -----\n");
	char mch1[20] = "this is string";
	char mch12[20] = "this is string";
	mch1[19] = 'a';
	mch12[19] = 'a';
	printf("%s\n", memchr(mch1, 'i', 20));
	printf("%s\n", ft_memchr(mch12, 'i', 20));

	printf("----- ft_memcmp -----\n");
	char mcp1[20] = ".........";
	char mcp2[20] = ".........";
	printf("%d\n", memcmp(mcp1, mcp2, 10));
	printf("%d\n", ft_memcmp(mcp1, mcp2, 10));

	printf("----- ft_strlen -----\n");
	printf("%lu\n", strlen("this"));
	printf("%lu\n", ft_strlen("this"));

	printf("----- ft_strdup -----\n");
	char	*dup = "fghjkl";
	printf("%s\n", ft_strdup(dup));
	printf("%s\n", strdup(dup));

	printf("----- ft_strcpy -----\n");
	char src1[] = "1234";
	char dest1[] = "qwerty";
	char src2[] = "1234";
	char dest2[] = "qwerty";
	printf("%s\n", strcpy(dest1, src1));
	printf("%s\n", ft_strcpy(dest2, src2));

	printf("----- ft_strncpy -----\n");
	char src12[] = "this is";
	char dest12[20];
	char src22[] = "this is";
	char dest22[20];
	//memset(dest12, 'B', sizeof(dest12));
	//memset(dest22, 'B', sizeof(dest22));
	printf("%s\n", strncpy(dest12, src12, 5));
	printf("%s\n", ft_strncpy(dest22, src22, 5));

	printf("----- ft_strcat -----\n");
	printf("%s\n", strcat(dest12, src12));
	printf("%s\n", ft_strcat(dest22, src22));

	printf("----- ft_strncat -----\n");
	char src13[] = "1234567891234567891234";
	char dest13[20] = "";
	char src23[] = "1234567891234567891234";
	char dest23[20] = "";
	printf("%s\n", strncat(dest13, src13, 19));
	printf("%s\n", ft_strncat(dest23, src23, 19));

	printf("----- ft_strlcat -----\n");
	char src14[5] = "yz";
	char dest14[5] = "abc";
	char src24[5] = "yz";
	char dest24[5] = "abc";
	printf("%lu %s\n", strlcat(dest14, src14, 2), dest14);
	printf("%lu %s\n", ft_strlcat(dest24, src24, 2), dest24);

	printf("----- ft_strchr -----\n");
	printf("%s\n", strchr(mch1, 'i'));
	printf("%s\n", ft_strchr(mch12, 'i'));

	printf("----- ft_strrchr -----\n");
	printf("%s\n", strrchr(mch1, 's'));
	printf("%s\n", ft_strrchr(mch12, 's'));

	printf("----- ft_strstr -----\n");
	char s1[] = "abcabcadabcaddabd";
	char s2[] = "cad";
	printf("%s\n", strstr(s1, s2));
	printf("%s\n", ft_strstr(s1, s2));

	printf("----- ft_strnstr -----\n");
	printf("%s\n", strnstr(s1, s2, 88));
	printf("%s\n", ft_strnstr(s1, s2, 88));

	printf("----- ft_strcmp -----\n");
	printf("%d\n", strcmp(s1, s2));
	printf("%d\n", ft_strcmp(s1, s2));

	printf("----- ft_strncmp -----\n");
	printf("%d\n", strncmp(s1, s2, 5));
	printf("%d\n", ft_strncmp(s1, s2, 5));

	printf("----- ft_atoi -----\n");
	printf("%d\n", atoi("-99999999999999999999999999"));
	printf("%d\n", ft_atoi("-99999999999999999999999999"));

	printf("----- ft_isalpha -----\n");
	printf("%d\n", isalpha('Z'));
	printf("%d\n", ft_isalpha('Z'));

	printf("----- ft_isdigit -----\n");
	printf("%d\n", isdigit('1'));
	printf("%d\n", ft_isdigit('1'));

	printf("----- ft_isalnum -----\n");
	printf("%d\n", isalnum('9'));
	printf("%d\n", ft_isalnum('9'));

	printf("----- ft_isascii -----\n");
	printf("%d\n", isascii(-1));
	printf("%d\n", ft_isascii(-1));

	printf("----- ft_isprint -----\n");
	printf("%d\n", isprint('~'));
	printf("%d\n", ft_isprint('~'));

	printf("----- ft_toupper -----\n");
	printf("%d\n", toupper('z'));
	printf("%d\n", ft_toupper('z'));

	printf("----- ft_tolower -----\n");
	printf("%d\n", tolower('c'));
	printf("%d\n", ft_tolower('c'));

	printf("<<<<<<<<<<<<>>>>>>>>>>>>\n");
	printf("<<<<<<<< PART_2 >>>>>>>>\n");
	printf("<<<<<<<<<<<<>>>>>>>>>>>>\n\n");

	printf("----- ft_memalloc -----\n");
	char *a = (char *)ft_memalloc(5);
	printf("%c\n", a[1]);

	printf("----- ft_memdel -----\n");
	ft_memdel((void **)&a);
	printf("%s\n", a);

	printf("----- ft_strnew -----\n");
	char *b = ft_memalloc(5);
	b[0] = 'a';
	printf("%s\n", b);

	printf("----- ft_strdel -----\n");
	ft_strdel(&b);
	printf("%s\n", b);

	printf("----- ft_strclr -----\n");
	char c[] = "abc";
	ft_strclr(c);
	printf("%s\n", c);

	printf("----- ft_striter -----\n");
	char *d = "abc\0";
	ft_striter(d, &test_putchar);
	printf("\n");

	printf("----- ft_striteri -----\n");
	ft_striteri(d, &test_putchar2);

	printf("----- ft_strmap -----\n");
	char *map = ft_strmap("abc", &test_toupper);
	printf("%s\n", map);

	printf("----- ft_strmapi -----\n");
	char *mapi = ft_strmapi("abc", &test_toupper2);
	printf("%s\n", mapi);

	printf("----- ft_strequ -----\n");
	char *equ1 = "asd";
	char *equ2 = "asds";
	printf("%d %s %s\n", ft_strequ(equ1, equ2), equ1, equ2);

	printf("----- ft_strnequ -----\n");
	printf("%d %s %s\n", ft_strnequ(equ1, equ2, 3), equ1, equ2);

	printf("----- ft_strsub -----\n");
	printf("%s\n", ft_strsub(equ1, 0, 1));

	printf("----- ft_strjoin -----\n");
	printf("%s\n", ft_strjoin("qwe", "12"));

	printf("----- ft_strtrim -----\n");
	char *tr = "  d  d\t ";
	printf("<%s>\n<%s>\n", tr, ft_strtrim(tr));

	printf("----- ft_strsplit -----\n");
	char **arr;
	char *sp = "split  ||this|for|me|||||!|";
    arr = ft_strsplit(sp, '|');
    int i = 0;
    while(arr[i])
    {
        printf("%s\n", arr[i]);
        free(arr[i]);
        i++;
    }

    printf("----- ft_itoa -----\n");
	printf("%s\n", ft_itoa(-3075682));

	printf("----- ft_putchar -----\n");
	ft_putchar('r');
	printf("\n");

	printf("----- ft_putstr -----\n");
	ft_putstr("new line with printf");
	printf("\n");

	printf("----- ft_putendl -----\n");
	ft_putendl("no new line with printf");

	printf("----- ft_putnbr -----\n");
	ft_putnbr(12340000);
	printf("\n");

	printf("----- ft_putchar_fd -----\n");
	int fd = open("test", O_RDWR);
	ft_putchar_fd(L'ø', fd);
	close(fd);
	printf("\n");

	printf("----- ft_putstr_fd -----\n");
	ft_putstr_fd("new line with printf", 1);
	printf("\n");

	printf("----- ft_putendl_fd -----\n");
	ft_putendl_fd("no new line with printf", 1);

	printf("----- ft_putnbr_fd -----\n");
	ft_putnbr_fd(2147483647, 1);
	printf("\n\n");

	printf("<<<<<<<<<<<<>>>>>>>>>>>>\n");
	printf("<<<<<<<< PART_3 >>>>>>>>\n");
	printf("<<<<<<<<<<<<>>>>>>>>>>>>\n\n");

	printf("----- ft_lstnew -----\n");
	char *data = "hello";
	t_list	*list = ft_lstnew(data, ft_strlen(data) + 1);
	print_list(list);

	printf("----- ft_lstdelone -----\n");
	ft_lstdelone(&list, &ft_lstdelone_test);
	if (!list)
		printf("null list\n");
	else
		printf("error!!!\n");

	printf("----- ft_lstdel -----\n");
	t_list	*list2 = ft_lstnew(data, ft_strlen(data) + 1);
	list2->next = ft_lstnew("world", ft_strlen("world") + 1);
	print_list(list2);
	ft_lstdel(&list2, &ft_lstdelone_test);
	if (!list)
		printf("null list\n");
	else
		printf("error!!!\n");

	printf("----- ft_lstadd -----\n");
	t_list	*list3 = ft_lstnew(data, ft_strlen(data) + 1);
	t_list	*list4 = ft_lstnew("everybody", ft_strlen("everybody") + 1);
	t_list	*list5 = ft_lstnew("so", ft_strlen("so") + 1);
	ft_lstadd(&list3, list4);
	ft_lstadd(&list3, list5);
	print_list(list3);

	printf("----- ft_lstiter -----\n");
	ft_lstiter(list3, &ft_iterprint);

	printf("----- ft_lstmap -----\n");
	t_list *list6 = ft_lstmap(list3, &list_to_app);
	print_list(list6);
}

