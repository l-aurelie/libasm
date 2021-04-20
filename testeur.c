/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:08:56 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 13:24:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libasm.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>

//============STRLEN===========
void	test_strlen()
{
	char *test_len[] = {"un test simple", "", "It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like).", NULL};
	int i = 0;

	printf("============STRLEN===========\n");
	while (test_len[i])
	{
		printf("______\ntest %d\n%ld\n", i + 1, strlen(test_len[i]));
		printf("ft = %d\n", ft_strlen(test_len[i]));
		i++;
	}
}

//============STRCPY===========
void	test_strcpy()
{
	char *test_cpy[] = {"un test simple", "", "It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like).", NULL};
	char dest_ft[1000];
	char dest[1000];
	int i = 0;

	printf("============STRCPY===========\n");
	while (test_cpy[i])
	{
		bzero(dest_ft, 1000);
		bzero(dest, 1000);
		printf("______\ntest %d\n|%s|\n", i + 1, strcpy(dest, test_cpy[i]));
		printf("ft = |%s|\n", ft_strcpy(dest_ft, test_cpy[i]));
		i++;
	}
}

//============STRCMP===========
void	test_strcmp()
{
	char *s1[] = {"un test simple", "", "abcd", "coucou", NULL};
	char *s2[] = {"un test simple", "", "abcz", "zcoucou", NULL};

	int i = 0;

	printf("============STRCMP===========\n");
	while (s1[i] && s2[i])
	{
		printf("______\ntest %d\n%d\n", i + 1, strcmp(s1[i], s2[i]));
		printf("ft = %d\n", ft_strcmp(s1[i], s2[i]));
		i++;
	}
	printf("%d\n", strcmp("\xff", "\xff\xff"));
	printf("%d\n", ft_strcmp("\xff","\xff\xff"));
}

//============WRITE============
void	test_write()
{
	printf("============WRITE============\n");
	char *str = "test de la fonction write";
	int count;
	int i;
	int fd[3];
	int fd_ft[3];
	
	i = 0;
	count = strlen(str);
	fd[0] = 1; 
	fd[1] = open("okfile", O_RDWR | O_CREAT);
	fd[2] = open("error", O_RDONLY | O_CREAT);
	fd_ft[0] = 1; 
	fd_ft[1] = open("okfile_ft", O_RDWR | O_CREAT);
	fd_ft[2] = open("error_ft", O_RDONLY | O_CREAT);
	while (i < 3)
	{
		if (fd[i] == -1 || fd_ft[i] == -1)
		{
			printf("OPEN failed\n");
			return ;
		}
		errno = 0;
		printf("\n______\ntest %d\nret= %ld, ", i + 1, write(fd[i], str, count));
		printf("errno = %d\n", errno);
		errno = 0;
		printf("\nret_ft= %d, ", ft_write(fd_ft[i], str, count));
		printf("errno_ft= %d\n", errno);
		i++;
	}


}
//============READ=============
void	test_read()
{
	printf("============READ============\n");
	int count;
	char buffer[1024];
	int i;
	int fd[2];
	int test;
	int test_ft;
	
	count = 12;
	fd[0] = open("read_error", O_WRONLY | O_CREAT, 0664);
	if (fd[0] == -1)
	{
		printf("OPEN failed\n");
		return ;
	}
	fd[1] = 0;
	test = open("test_read", O_RDONLY);
	if (test == -1)
	{
		printf("OPEN failed\n");
		return ;
	}
	test_ft = open("test_read_ft", O_RDONLY);
	if (test_ft == -1)
	{
		printf("OPEN failed\n");
		return ;
	}
	i = 0;
	while (i < 2)
	{
		bzero(buffer, 1024);
		errno = 0;
		printf("\n______\ntest %d\nret= %ld, ", i + 1, read(fd[i], buffer, count));
		printf("errno = %d, ", errno);
		printf("buffer = %s\n", buffer);
		errno = 0;
		bzero(buffer, 1024);
		printf("fd = %d\n", fd[i]);
		printf("\nret_ft= %d, ", ft_read(fd[i], buffer, count));
		printf("errno_ft= %d, ", errno);
		printf("buffer = %s\n", buffer);
		i++;
	}
	bzero(buffer, 1024);
	errno = 0;
	printf("\n______\ntest 3\nret= %ld, ", read(test, buffer, count));
	printf("errno = %d, ", errno);
	printf("buffer = %s\n", buffer);
	errno = 0;
	bzero(buffer, 1024);
	printf("\nret_ft= %d, ", ft_read(test_ft, buffer, count));
	printf("errno_ft= %d, ", errno);
	printf("buffer = %s\n", buffer);
}

//============STRDUP===========
void	test_strdup()
{
	char *test_dup[] = {"un test simple", "", "It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like).", NULL};
	char dest_ft[1000];
	char dest[1000];
	int i = 0;

	printf("============STRDUP===========\n");
	while (test_dup[i])
	{
		bzero(dest_ft, 1000);
		bzero(dest, 1000);
		printf("______\ntest %d\n|%s|\n", i + 1, strdup(test_dup[i]));
		printf("ft = |%s|\n", ft_strdup(test_dup[i]));
		i++;
	}
}

int		main()
{
	test_strlen();
	test_strcpy();
	test_strcmp();
	test_write();
	test_read();
	test_strdup();
	return (0);
}
