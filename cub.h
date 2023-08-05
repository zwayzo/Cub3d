#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

# define HEX "0123456789abcdef"
# define HEX_MAJ "0123456789ABCDEF"

typedef struct s_indice
{
    int     NO_indice;
    int     WE_indice;
    int     SO_indice;
    int     EA_indice;
    char    *NO_stock;
    char    *WE_stock;
    char    *SO_stock;
    char    *EA_stock;
}   t_incice;

typedef struct s_param
{
    int lines_numbers;
    char    *name;
    char    **maps;
}   t_param;

typedef struct s_cub
{
    t_incice *indices;
    t_param *params;

}   t_cub;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s1);
void	part1(int *i, char *s1, char *ptr);
int	ft_putchar(char c);
void    ft_directions_init(t_cub *cub);
void    directions_details(t_cub *cub);
void    west_ver(char *str, t_cub *cub);
void    south_ver(char *str, t_cub *cub);
void    east_ver(char *str, t_cub *cub);
void    nord_ver(char *str, t_cub *cub);
void    west_var_exist(char *str, t_cub *cub);
void    south_var_exist(char *str, t_cub *cub);
void    nord_var_exist(char *str, t_cub *cub);
void    east_var_exist(char *str, t_cub *cub);
void    east_store(char *str, t_cub *cub);
void    south_store(char *str, t_cub *cub);
void    nord_store(char *str, t_cub *cub);
void    west_store(char *str, t_cub *cub);
int     w_len(char *str);
void     check_direction_nature(char *str, t_cub *cub);

#endif