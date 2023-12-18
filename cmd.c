/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacucalo <lacucalo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:18:07 by lacucalo          #+#    #+#             */
/*   Updated: 2023/12/18 19:02:39 by lacucalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// void ft_go(char *cmd, char **env) //CN EXEGG
// {
//     t_pipex pipex;
    
//     get_paths(&pipex, env); //CN
// }

// // Va comprobando los 5 caracteres uno detrás de otro (PATH=), cuando los
// // encuentra devuelve 0, si no los encuentra devuelve 1
// int	findPATH(char *str) //ISPATH
// {
// 	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T'
// 		&& str[3] == 'H' && str[4] == '=')
// 		return (0);
// 	return (1);
// }

// // Extraer las rutas del sistema de la variable de entorno PATH y almacenarlas
// // en la estructura t_pipex
// void get_paths(t_pipex *pipex, char **env) //CN
// {
//     int i;
	
// 	i = 0;
// 	// Bucle que va buscando PATH con findPATH, va sumando 1 a env
// 	// para pasar a la siguiente variable de entorno
//     while (*env)
// 	{
// 		if (findPATH(*env) == 0)
// 			break;
// 		env++;
// 	}
// 	// Dividir la cadena de PATH en un array de cadenas de caracteres
// 	// utilizando como delimitador el caracter ':'
// 	pipex->path = ft_split(*env + 5, ':'); //He de sumarle 5?
// 	printf("%s", pipex->path[0]);
// 	printf("%s", pipex->path[1]);
// 	// Añade '/' al final de cada ruta
// 	while (pipex->path[i])
// 	{
// 		pipex->path[i] = ft_strjoin(pipex->path[i], "/");
// 		i++;
// 	}
// }