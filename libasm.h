/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:12:38 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 13:03:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char * s2);
int		ft_write(int fd, const void *buf, int count);
int		ft_read(int fd, void *buf, int count);
char	*ft_strdup(char *str);
  
