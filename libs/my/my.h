/*
** EPITECH PROJECT, 2022
** .h for include lib
** File description:
** up
*/

#ifndef _MY_H_
    #define _MY_H_
    #include <stddef.h>
    #define _SIZETAB(X) (sizeof(X) / sizeof(X[0]))
int my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char const *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strcatn(char *dest, char const *src, int check);
int my_show_word_array(char const **tab);
char *my_strdup(char const *src);
char *my_strdup_free(char *src);
char *my_strcatn(char *dest, char const *src, int check);
char **my_str_to_word_array(char const *str, char *separators);
char *concat_params(int ac, char **av);
int is_alphanum(char c);
int count_word(char const *str);
int boucle2(char *str, char const *to_find, int i);
char my_getop(char *str);
int is_alpha(char c);
int my_nbletter(char *str);
void my_puterror(char *error);
int my_puttab(char **tab);
int my_arrsize(char const **arr);
char *my_putnbrm(long int nbr);
char *my_putnbrm_2d(long int nbr);
void free_tab(char **tab);
int my_str_isalphanum(char const *str);
int is_separator(char const *separators, char letter);
int my_str_in_str(char const *str, char const *find);
void *my_calloc(size_t size);
char *my_array_to_str(char const **array);
char *my_strndup(char const *src, size_t n);
char *my_strndup_free(char *src, size_t n);
char my_get_first_char(char const *str, char const *skip_char);
size_t my_strlen_skip_char(char const *str, char const *skip_char);
char *my_clean_string(char *str, char const *delete_char, int free_str);
size_t my_count_char(char const *str, char c);
char *my_array_to_str_separator(char const **array, char const *separator);
char my_get_last_char(char const *str, char const *skip_char);
char **my_delline(char **array, int key);
char **my_appendline_index(char **array, char *line, int index);
char *my_strcat_free(char *dest, char *src, char free_dest, char free_src);
char **my_appendline(char **array, char *line);
int is_in_array(char const **array, char const *str);
char **my_appendline_index(char **array, char *line, int index);
#endif /* _MY_H_ */
