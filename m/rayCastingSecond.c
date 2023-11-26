/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCastingSecond.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:07:30 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/21 11:51:37 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Realizando o algoritmo DDA(Digital Differential Analyzer)
para determinar qual parade foi atingida pelo raio.

	main->raycast->hit = 0; - Inicializa a variavel hit a zero, indicando que
o raio nao atingiu a parede.

	Entramos num loop que continuara enquanto nenhum raio atingir uma parede.

	Dentro do loop verificamos qual raio atingira uma aresta primeiro, se aresta
de X ou de Y.
	Isso e feito comparando as distancias ja calculadas de sidedist_x(distancia
ate a proxima aresta no eixo X) com sidedist_y(distancia ate a proxima aresta no
eixo Y). Se sidedist_x for menor, o raio avanca no eixo X, caso contrario, no Y.

	A posicao do mapa (map_x e map_y) e atualizada de acordo com a direcao do
raio(stepX e step_y).

	side e atualizado para percebermos qual lado foi atingido, se X ou se Y.

	Por fim, e verificado se a posicao atual no mapa e uma parede e se sim,
o loop e encerrado.
*/

void	ft_dda_perform(t_main *main, char **worldMap)
{
	main->raycast->hit = 0;
	while (main->raycast->hit == 0)
	{
		if (main->raycast->sidedist_x < main->raycast->sidedist_y)
		{
			main->raycast->sidedist_x += main->raycast->deltadist_x;
			main->raycast->map_x += main->raycast->step_x;
			main->raycast->side = 0;
		}
		else
		{
			main->raycast->sidedist_y += main->raycast->deltadist_y;
			main->raycast->map_y += main->raycast->step_y;
			main->raycast->side = 1;
		}
		if (worldMap[main->raycast->map_x][main->raycast->map_y] == '1')
		{
			main->raycast->hit = 1;
		}
	}
}

/*
			Calculo da distancia perpendicular da parade ao plano da camara e
		calculo da altura da linha que ira ser desenhada na tela.
*/

void	ft_projection_distance(t_main *main)
{
	if (main->raycast->side == 0)
		main->raycast->perpwalldist = (main->raycast->sidedist_x
				- main->raycast->deltadist_x);
	else
		main->raycast->perpwalldist = (main->raycast->sidedist_y
				- main->raycast->deltadist_y);
	if (main->raycast->perpwalldist != 0)
		main->raycast->line_height = (int)(SCREEN_HEIGHT
				/ main->raycast->perpwalldist);
	else
		main->raycast->line_height = (int)SCREEN_HEIGHT;
}

/*
		Determinacao dos pixeis mais altos e mais baixo que serao preenchidos
	na faixa vertical.

		drawstart e calculado subtraindo metade da line_height do meio da tela
	(SCREEN_HEIGHT / 2).
	Isso servira para posicionar a linha de inicio da parede corretamente na tela.
		E verificado se o resultado e menor que zero. Se for, e ajustado para zera
	para garantir que nao haja valores negativos.

		drawend e calculado somando metade da line_height ao meio da tela
	(sreenHeight / 2).
	Isso determina a linha de fim da parede.
		E verificado se o calculo ultrapassa a linha maxima de altura.
	Se sim, e ajustada para o valor maximo da altura.
*/

void	ft_pixel_calculation(t_main *main)
{
	main->raycast->drawstart = -main->raycast->line_height
		/ 2 + SCREEN_HEIGHT / 2;
	if (main->raycast->drawstart < 0)
		main->raycast->drawstart = 0;
	main->raycast->drawend = (main->raycast->line_height / 2)
		+ SCREEN_HEIGHT / 2;
	if (main->raycast->drawend >= SCREEN_HEIGHT)
		main->raycast->drawend = SCREEN_HEIGHT - 1;
}

void	ft_side_of_pixel(t_main *main)
{
	if (main->raycast->side == 1)
	{
		if (main->raycast->raydir_y < 0)
			main->tex = main->n_tex;
		else
			main->tex = main->s_tex;
	}
	else
	{
		if (main->raycast->raydir_x < 0)
			main->tex = main->w_tex;
		else
			main->tex = main->e_tex;
	}
}

void	ray_seconds_steps(t_main *main)
{
	ft_dda_perform(main, main->world_map);
	ft_projection_distance(main);
	ft_pixel_calculation(main);
	ft_side_of_pixel(main);
}
