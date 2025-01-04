/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:20:44 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/22 20:25:22 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <string.h>

# define K_A 97
# define K_B 98
# define K_C 99
# define K_D 100
# define K_E 101
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_M 109
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_S 115
# define K_T 116
# define K_U 117
# define K_V 118
# define K_W 119
# define K_X 120
# define K_Y 121
# define K_Z 122
# define K_AR_L 65361
# define K_AR_R 65363
# define K_AR_U 65362
# define K_AR_D 65364
# define K_NP_DIV 65455
# define K_NP_MUL 65450
# define K_NP_MIN 65453
# define K_NP_PLU 65451
# define K_SP 32
# define K_ESC 65307
# define M_CLK_L 1
# define M_CLK_R 3
# define M_CLK_M 2
# define M_SCR_U 4
# define M_SCR_D 5

enum e_event//Events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_vector//Vector struct
{
	int			x;
	int			y;
}	t_vector;

typedef struct s_anim//Anim struct
{
	int		frame_nb;
	int		current_frame;
	char	**frames;
}	t_anim;

void		clamp(int *nb, int min, int max);
t_vector	vec2(int x, int y);
t_vector	add_vec2(t_vector vec1, t_vector vec2);
t_vector	sub_vec2(t_vector vec1, t_vector vec2);
t_vector	vec2_make_end(t_vector start, t_vector end);
t_vector	vec2_make_start(t_vector start, t_vector end);
t_vector	mul_vec2(t_vector vec1, t_vector vec2);
int			compare_vec2(t_vector vec1, t_vector vec2);
void		clamp_vec2(t_vector *vec, t_vector min, t_vector max);
int			biggest_nb(int a, int b, int c, int d);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif