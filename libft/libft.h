/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauferna <rauferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:50:51 by rauferna          #+#    #+#             */
/*   Updated: 2023/09/29 12:50:57 by rauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/**
 * @brief Convert the initial portion of the string pointed str to an int .
 * 
 * @param str 
 * @return int 
 */
int				ft_atoi(const char *str);

/**
 * @brief This function allocates memory with malloc,
 * but the bytes value are zero.
 * 
 * @param count /length of the space
 * @param size /size of bytes
 * @return void* 
 */
void			*ft_calloc(size_t count, size_t size);

/**
 * @brief Returns 1 if c is equvalent to an alfabetical word 
 * example: in Decimal ASCII 97 is a, or return 0 if is not alphabetical.
 * 
 * @param c 
 * @return int 
 */
int				ft_isalpha(int c);

/**
 * @brief Returns 1 if c is a al, or return o if is not a digit.
 * 
 * @param c 
 * @return int 
 */
int				ft_isdigit(char c);

/**
 * @brief Returns 1 if c is equvalent to an alfabetical word or a number 
 * example: in Decimal ASCII 97 is a, or return 0 if is not alphabetical 
 * or a number.
 * 
 * @param c 
 * @return char 
 */
char			ft_isalnum(char c);

/**
 * @brief Return 1 if i is an ASCII number, or return 0 if is not.
 * 
 * @param i 
 * @return int 
 */
int				ft_isascii(int i);

/**
 * @brief Returns 1 if is an printable ASCII, and 0 if is not.
 * 
 * @param i 
 * @return int 
 */
int				ft_isprint(int i);

/**
 * @brief Returns the lenght of the string c.
 * 
 * @param c 
 * @return int 
 */
int				ft_strlen(const char *s);

/**
 * @brief writes len bytes of value c to the string b.
 * 
 * @param dest 
 * @param c 
 * @param n 
 * @return void* 
 */
void			*ft_memset(void *dest, int c, size_t n);

/**
 * @brief writes n zeroed bytes to the string s
 * if n == 0 does nothing.
 * 
 * @param str 
 * @param n 
 */
void			ft_bzero(void *str, size_t n);

/**
 * @brief The memcpy() function copies n bytes from memory area src 
 * to memory area dst.
 * If dst and src overlap, behavior is undefined.
 * 
 * @param dest 
 * @param src 
 * @param n 
 * @return void* 
 */
void			*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief copies len bytes from string src to string dst.  The two strings
 * may overlap; the copy is always done in a non-destructive manner.
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
void			*ft_memmove(void *dst, const void *src, size_t n);

/**
 * @brief Copy and concatenate strings with the same input
 * parameters and output result.
 * Copies up to dstsize - 1 characters from the string src to dst,
 * NUL-terminating the result if dstsize is not 0.
 * 
 * @param dest 
 * @param src 
 * @param n 
 * @return size_t /the total length of the
 * string they tried to create.
 */
size_t			ft_strlcpy(char *dest, const char *src, size_t n);

/**
 * @brief Copy and concatenate strings with the same input
 * parameters and output result.
 * appends string src to the end of dst.  It will append at most
 * dstsize - strlen(dst) - 1 characters.
 * 
 * @param dest 
 * @param src 
 * @param n 
 * @return size_t /the total length of the
 * string they tried to create.
 */
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief converts a lower-case letter to the corresponding upper-case letter
 * 
 * @param c 
 * @return int 
 */
int				ft_toupper(int c);

/**
 * @brief converts an upper-case letter to the corresponding lower-case letter
 * 
 * @param c 
 * @return int 
 */
int				ft_tolower(int c);

/**
 * @brief locates the first occurrence of c (converted to a char) in the
 * string pointed to by s.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char			*ft_strchr(const char *s, int c);

/**
 * @brief allocates sufficient memory for a copy of the string s1, does the
 * copy, and returns a pointer to it.  The pointer may subsequently be used 
 * as an argument to the function free
 * 
 * @param s1 
 * @return char* 
 */
char			*ft_strdup(const char *s1);

/**
 * @brief locates the last occurrence of c (converted to a char) in the
 * string pointed to by s.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char			*ft_strrchr(const char *s, int c);

/**
 * @brief lexicographically compare the null-terminated strings s1 and s2
 * but no more than n characters
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return int 
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief locates the first occurrence of c (converted to an unsigned char)
 * in string s
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void			*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long
 * 
 * @param str1 
 * @param str2 
 * @param n 
 * @return int 
 */
int				ft_memcmp(const void *str1, const void *str2, size_t n);

/**
 * @brief locates the first occurrence of the null-terminated 
 * string needle in the string
 * haystack, where not more than len characters are searched.
 * Characters that appear after a `\0' character are not searched.
 * Since the strnstr() function 
 * is a FreeBSD specific API,
 * it should only be used when portability is not a concern.
 * 
 * @param haystack 
 * @param needle 
 * @param len 
 * @return char* 
 */
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

/**
 * @brief Allocates with malloc and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char			*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates with malloc and returns a new string,
 * which is the result of the concatenation of ’s1’ and ’s2’.
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char			*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates with malloc and returns a copy of ’s1’ with the characters
 * specified in ’set’ removed from the beginning and the end of the string
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char			*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates with malloc and returns an array of strings
 * obtained by splitting ’s’ using the character ’c’ as a delimiter.
 * The array must end with a NULL pointer.
 * 
 * @param s 
 * @param c 
 * @return char** 
 */
char			**ft_split(char const *s, char c);

/**
 * @brief Allocates (with malloc(3)) and returns a string representing
 * the integer received as an argument. Negative numbers must be handled.
 * 
 * @param n 
 * @return char* 
 */
char			*ft_itoa(int n);

/**
 * @brief Applies the function ’f’ to each character of the string ’s’, 
 * and passing its index as first argument to create a new string with malloc
 * resulting from successive applications of ’f’.
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function ’f’ on each character of the string passed 
 * as argument, passing its index as first argument.
 * Each character is passed by address to ’f’ to be modified if necessary.
 * 
 * @param s 
 * @param f 
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Outputs the character ’c’ to the given file descriptor.
 * 
 * @param c 
 * @param fd 
 */
void			ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 * 
 * @param s 
 * @param fd 
 */
void			ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor followed
 * by a newline.
 * 
 * @param s 
 * @param fd 
 */
void			ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 * 
 * @param n 
 * @param fd 
 */
void			ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Allocates with malloc and returns a new node.
* The member variable ’content’ is initialized with the value
* of the parameter ’content’. The variable ’next’ 
* is initialized to NULL.
 * 
 * @param n 
 * @param fd 
 */
t_list			*ft_lstnew(void *content);

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 * 
 * @param n 
 * @param fd 
 */
void			ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of nodes in a list.
 * 
 * @param n 
 * @param fd 
 */
int				ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of the list.
 * 
 * @param n 
 * @param fd 
 */
t_list			*ft_lstlast(t_list *lst);

/**
 * @brief Adds the node ’new’ at the end of the list.
 * 
 * @param n 
 * @param fd 
 */
void			ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter a node and frees the memory 
* of the node’s content using the function ’del’ given as
* a parameter and free the node. The memory of ’next’
* must not be freed.
 * 
 * @param n 
 * @param fd 
 */
void			ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given node and every successor
 * of that node, using the function ’del’ and free(3).
 * Finally, the pointer to the list must be set to NULL.
 * 
 * @param n 
 * @param fd 
 */
void			ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function
 *’f’ on the content of each node.
 * 
 * @param n 
 * @param fd 
 */
void			ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ on the content
 * of each node. Creates a new list resulting of the successive applications
 * of the function ’f’.The ’del’ function is used to
 * delete the content of a node if needed.
 * 
 * @param n 
 * @param fd 
 */
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

/// @brief main function of ft_printf it has typeformat that is a function 
// wich select the type of format, and go to another specific function 
// depending what is one position more of the %
/// @param s 
/// @param  
/// @return lenght
int				ft_printf(char const *s, ...);

/// @brief receive a fd of an file and read the first line, and if you execute
/// again read the second line... until the file is read.
/// it manages multiples fds
/// @param fd 
/// @return 
char			*get_next_line(int fd);
#endif