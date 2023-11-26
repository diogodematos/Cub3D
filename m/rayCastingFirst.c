/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCastingFirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:52:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/24 12:38:29 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_camera_and_dir(t_main *main, int x)
{
	main->raycast->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	main->raycast->raydir_x = main->raycast->dir_x
		+ main->raycast->plane_x * main->raycast->camera_x;
	main->raycast->raydir_y = main->raycast->dir_y
		+ main->raycast->plane_y * main->raycast->camera_x;
}

/*
	Coordenadas da celula atual do mapa em que o raio se encontra.
	Obtidas convertendo a posicao atual do jogador para INT.

	A necessidade dessa conversao das atuais coordenadas do jogar
que podem ser float, para numeros inteiros, e devido ao facto de estarmos
a trabalhar com um mapa sendo uma grelha 2D. Cada celula do mapa tem coordenadas
(0,0) (0,1) etc

	Entao para determinar em que celula do mapa o raio esta, e necessario
arredondar as coordenadas do jogador ao INT mais proximo.

	Exemplo:

		Se o jogador esta na posicao (2.3, 3.7) significa que ele
	esta na celula (2, 4). map_x = 2 e map_y = 4.
*/

void	ft_cell_coordinate(t_main *main)
{
	main->raycast->map_x = (int)main->raycast->pos_x;
	main->raycast->map_y = (int)main->raycast->pos_y;
}

/*
		deltadist_x representa a distancia que o raio precisa percorrer para atingir
	a proxima aresta X. Se raydir_x for igual a 0 significa que o raio e paralelo
	ao eixo dos X, entao deltadist_x e definido com um valor grande
	para evitar divisao por zero.

		Caso contrario e calculador para o inverso da direcao X.
	E calculador com recurso a funcao de valor absoluto pois
	estamos a falar de distancias, entao nao faz sentido ter um numero negativo.
*/

void	ft_lenght_to_next_edge(t_main *main)
{
	if (main->raycast->raydir_x == 0)
		main->raycast->deltadist_x = 1e30;
	else
		main->raycast->deltadist_x = fabs(1 / main->raycast->raydir_x);
	if (main->raycast->raydir_y == 0)
		main->raycast->deltadist_y = 1e30;
	else
		main->raycast->deltadist_y = fabs(1 / main->raycast->raydir_y);
}

/*
		Step_x e Step_y sao calculados com base na direcao do raio X e do raio Y.
		step_x ira indicar se o raio esta a ir na direcao esquerda do mapa
		(-1) ou direita (1).
		sidedist_x representa a distancia do raio a primeira aresta a
		esquerda ou direita.
		step_y ira indicar se o raio esta a ir para cima (-1) ou para baixo (1).
		sidedist_y representa a distancia do raio a primeira aresta acima ou abaixo.
*/

void	ft_step_initial_sidedist(t_main *main)
{
	if (main->raycast->raydir_x < 0)
	{
		main->raycast->step_x = -1;
		main->raycast->sidedist_x = (main->raycast->pos_x
				- main->raycast->map_x) * main->raycast->deltadist_x;
	}
	else
	{
		main->raycast->step_x = 1;
		main->raycast->sidedist_x = (main->raycast->map_x
				+ 1.0 - main->raycast->pos_x) * main->raycast->deltadist_x;
	}
	if (main->raycast->raydir_y < 0)
	{
		main->raycast->step_y = -1;
		main->raycast->sidedist_y = (main->raycast->pos_y
				- main->raycast->map_y) * main->raycast->deltadist_y;
	}
	else
	{
		main->raycast->step_y = 1;
		main->raycast->sidedist_y = (main->raycast->map_y
				+ 1.0 - main->raycast->pos_y) * main->raycast->deltadist_y;
	}
}

void	ray_first_steps(t_main *main, int x)
{
	ft_camera_and_dir(main, x);
	ft_cell_coordinate(main);
	ft_lenght_to_next_edge(main);
	ft_step_initial_sidedist(main);
}
