/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei < brolivei@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:53:30 by brolivei          #+#    #+#             */
/*   Updated: 2023/11/16 11:28:11 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
			Calculo da coordenada onde o raio atinge a parede.

		Se o lado atingido pelo raio for 0(lado horizontal), entao a coordenada
	wall_x sera calculada usando a posicao Y inicial do raio e distancia
	perpendicular a parede, multiplicada pela direcao do raio no eixo Y.
		Se o lado for 1(lado vertical), entao a coordenada wall_x e calculada
	usando a posicao X inicial do raio e a distancia perpendicular a parede
	multiplicada pela direcao do raio no eixo X.

		Apos isso, wall_x e normalizada subtraindo a parte inteira da coordenada Wall_x
	usando a funcao floor, para garantir que esteja no intervalo [0, 1];
*/

void	get_wall_x(t_main *main)
{
	if (main->raycast->side == 0)
		main->raycast->wall_x = main->raycast->pos_y
			+ main->raycast->perpwalldist * main->raycast->raydir_y;
	if (main->raycast->side == 1)
		main->raycast->wall_x = main->raycast->pos_x
			+ main->raycast->perpwalldist * main->raycast->raydir_x;
	main->raycast->wall_x -= floor(main->raycast->wall_x);
}

/*
			Projecao da textura

		tex_x e a coordenada da textura que sera usada para colorir o pixel
	em questao.
		Multiplicando wall_x pela largura da textura dar-nos-a essa coordenada
	na textura.
		A subtracao em "main->raycast->tex_x = texWidth - main->raycast->tex_x - 1"
	e feita para corrigir possiveis inversoes ou distorcoes na textura.

		tex_step e o tamanho do passo que deve ser dado ao percorrer a textura
	verticalmente por pixel na parede. Isso e calculado dividindo a largura da
	textura pelo numero de pixels na altura da parede.

		tex_pos e a posicao inicial na textura ao longo do eixo vertical. Isso
	e calculado com baso na posicao inicial de desenho da parede para garantir que
	a textura seja alinhada corretamente com a altura da parede na tela.
*/

void	ft_tex_projection_x(t_main *main)
{
	main->raycast->tex_x = (int)(main->raycast->wall_x * (double)TEX_WIDTH);
	main->raycast->tex_x = TEX_WIDTH - main->raycast->tex_x - 1;
	main->raycast->tex_step = 1.0 * TEX_WIDTH / main->raycast->line_height;
	main->raycast->tex_pos = (main->raycast->drawstart - SCREEN_HEIGHT / 2
			+ main->raycast->line_height / 2) * main->raycast->tex_step;
}

/*
		Tex_y e a coordenada Y na textura que corresponde a posicao vertical
	do pixel na parede.

		tex_pos representa a posicao vertical atual na textura, e (texHeight - 1)
	e usado como uma mascara para garantir que o valor de tex_y esteja dentro dos
	limites da altura da textura.

		O operador & e usado para aplicar essa mascara.

		tex_pos e convertido para inteiro.

		O resultado desta operacao e a coordenada Y na textura correspondente a
	posicao vertical do pixel na parede.

		tex_pos e o avanco vertical na textura para o proximo pixel na parede.
*/

void	ft_tex_projection_y(t_main *main)
{
	main->raycast->tex_y = (int)main->raycast->tex_pos & (TEX_HEIGHT - 1);
	main->raycast->tex_pos += main->raycast->tex_step;
}
