/*
** my.h for 57 in /home/arthur/delivery/MUL/wireframe/lib/my
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Nov 21 22:05:36 2016 Arthur Knoepflin
** Last update Tue Dec 27 16:35:33 2016 Arthur Knoepflin
*/

#ifndef MY_H_
# define MY_H_

/*
** Lib
*/

void		my_putchar(char c);
int		my_isneg(int nb);
int		my_put_nbr(int nb);
int		my_putnbr_base(int, char *);
int		my_swap(int *a, int *b);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		my_getnbr_base(char *, char *);
void		my_sort_int_tab(int *tab, int size);
int		my_power_rec(int nb);
int		my_square_root(int nb);
int		my_is_prime(int nombre);
int		my_find_prime_sup(int nb);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_revstr(char *str);
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strup(char *);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		*my_strcapitalize(char *str);
int		my_str_isalpha(char *str);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		my_showmem(char *str, int size);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char *src, int nb);
char		**my_str_to_wordtab(char *);
char		*my_strdup(char *src);

#endif /* !MY_H_ */
