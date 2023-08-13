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

typedef struct s_colors
{
    int blue;
    int green;
    int red;
}   t_colors;

typedef struct s_indice
{
    int      NO_indice;
    int         WE_indice;
    int         SO_indice;
    int         EA_indice;
    char        *NO_stock;
    char        *WE_stock;
    char        *SO_stock;
    char        *EA_stock;
    t_colors    *ciel;
    int         ciel_indice;
    int         floor_indice;
    t_colors    *floor;
    int         begin_line;
    int         player_indice;
    char        player;

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
int     ft_putchar(char c);
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
void    check_direction_nature(char *str, t_cub *cub);
void    colors_storage(t_cub *cub);
void    colors_stock(t_cub *cub);
char	**ft_split(char *s, char c);
void    red_floor_split(char *str, t_cub *cub);
void    green_floor_split(char *str, t_cub *cub);
void    blue_floor_split(char *str, t_cub *cub);
void    red_ciel_split(char *str, t_cub *cub);
void    green_ciel_split(char *str, t_cub *cub);
void    blue_ciel_split(char *str, t_cub *cub);
void    double_free(char **str);
int     double_lenght(char **str);
int     number_finder(char *str);
int     comma_finder(char *str);
void    maps_working(t_cub *cub);
void    first_one(t_cub *cub);
void    last_one(t_cub *cub);
void    first_wall(t_cub *cub);
void    last_wall(t_cub *cub);
void    first_line_detecte(t_cub *cub, int i);
int     ciel_detecte(t_cub *cub, int i, int j);
void    RGB_call_function(t_cub *cub, int i, int n);
void    colors_check(t_cub *cub);
void    player_param(t_cub *cub);
#endif