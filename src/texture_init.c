/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 06:50:09 by jchenaud          #+#    #+#             */
/*   Updated: 2017/06/06 06:21:41 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static char	*ft_strjoin_free1(char *s1, char *s2)
{
	unsigned int	u_i;
	unsigned int	u_j;
	unsigned int	u_size;
	char			*dest;

	u_i = -1;
	u_j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	u_size = ft_strlen(s1) + ft_strlen(s2);
	dest = (char*)malloc(sizeof(*dest) * (u_size + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[++u_i] != '\0')
		dest[u_i] = s1[u_i];
	while (s2[++u_j] != '\0')
		dest[u_i + u_j] = s2[u_j];
	dest[u_i + u_j] = '\0';
	free(s1);
	return (dest);
}

static char	*ft_strjoin_free2(char *s1, char *s2)
{
	unsigned int	u_i;
	unsigned int	u_j;
	unsigned int	u_size;
	char			*dest;

	u_i = -1;
	u_j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	u_size = ft_strlen(s1) + ft_strlen(s2);
	dest = (char*)malloc(sizeof(*dest) * (u_size + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[++u_i] != '\0')
		dest[u_i] = s1[u_i];
	while (s2[++u_j] != '\0')
		dest[u_i + u_j] = s2[u_j];
	dest[u_i + u_j] = '\0';
	free(s2);
	return (dest);
}

static void	animate_text_ini(t_graf *graf)
{
	int		x;
	int		y;
	int		i;
	char	*path;

	i = 1;
	if (!(graf->anim = (t_image**)malloc(sizeof(t_image) * NB_TX_FRAME)))
		exit(0);
	while (i <= NB_TX_FRAME)
	{
		path = ft_strjoin_free2("texture/animate/img", ft_itoa(i));
		path = ft_strjoin_free1(path, ".xpm");
		graf->anim[i - 1] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, path, &x, &y);
		i++;
		free(path);
	}
}

void		ft_texture_maker(t_graf *graf)
{
	int x;
	int y;

	if (graf->texture_init == 0)
	{
		if (!(graf->text = (t_image**)malloc(sizeof(t_image) * NB_TEXTURE)))
			exit(0);
		graf->text[0] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/brick64.xpm", &x, &y);
		graf->text[1] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/metal_tiles.xpm", &x, &y);
		graf->text[2] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/Warning.xpm", &x, &y);
		graf->text[3] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/carbon.xpm", &x, &y);
		graf->text[4] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/mossy.xpm", &x, &y);
		graf->text[5] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/lock.xpm", &x, &y);
		graf->text[6] = (t_image*)mlx_xpm_file_to_image(
				graf->mlx, "texture/door_1.xpm", &x, &y);
		graf->texture_init = 1;
		animate_text_ini(graf);
	}
}
