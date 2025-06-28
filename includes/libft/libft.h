/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:44:30 by llupache          #+#    #+#             */
/*   Updated: 2025/06/27 18:14:21 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_isalpha(int str);
int					ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str);
void				*ft_bzero(void *str, size_t n);
void				*ft_calloc(size_t nitems, size_t size);
int					ft_isalnum(int str);
int					ft_isascii(int c);
int					ft_isdigit(int d);
int					ft_isprint(int c);
void				*ft_memchr(const void *str, int search_str, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *dest_str, const void *src_str, size_t n);
void				*ft_memmove(void *dest_str, const void *src_str, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(const char *str, char c);
char				*ft_strchr(const char *str, int search_str);
char				*ft_strdup(const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, const char *s2);
unsigned int		ft_strlcat(char *dest, const char *src, unsigned int size);
unsigned int		ft_strlcpy(char *dest, const char *src, unsigned int size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strrchr(const char *str, int search_str);
char				*ft_strtrim(char const *s1, char const *set);
int					ft_tolower(int c);
int					ft_toupper(int c);
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_printf(const char *str, ...);
void				print_chr(const char c);
int					print_str(char *str, int count);
int					print_void(unsigned long long ptr, int count);
int					ft_putnbr(int nb, int count);
int					ft_put_uns_nbr(unsigned int nb, int count);
int					ft_put_hex_up(unsigned int nb, int count);
int					ft_put_hex_low(unsigned int nb, int count);

#endif
