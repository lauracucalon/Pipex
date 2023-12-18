/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacucalo <lacucalo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:03:10 by lacucalo          #+#    #+#             */
/*   Updated: 2023/12/18 19:13:10 by lacucalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char **env)
{
    t_pipex pipex;
    pid_t pid;
    
    if(argc != 5)  //En caso de n de argumentos incorrecto
    {
        perror("Error n of arguments");
        return 1;
    }
    if(env == NULL || *env == NULL)  //En caso de no haber variables de entorno
    {
        perror("Error no env");
        return 1;
    }

    pipe(pipex.fd);
    pid = fork();
    // if(pipex.fd == -1)
    // {
    //     perror("Error pip(ing)");
    //     return 1;
    // }
    if(pid == -1)
    {
        perror("Error fork(ing)");
        return 1;
    }
    if (pid == 0)
    {
        close(pipex.fd[0]);
        dup2(pipex.fd[1], 1);
        // execlp(argv[1], argv[1], NULL);
        execve(pipex.fd[1], pipex.cmd2, NULL);
        close(pipex.fd[1]);
        
    }
    else
    {
        close(pipex.fd[1]);
        dup2(pipex.fd[0], 0);
        waitpid(pid, NULL, 0);
        // execlp(argv[2], argv[2], NULL);
        execve(pipex.fd[0], pipex.cmd1, NULL);
        close(pipex.fd[0]);
    }
    return (0);
}

void ft_go(char *cmd, char **env) //CN EXEGG
{
    t_pipex pipex;
    
    get_paths(&pipex, env); //CN
}

// Va comprobando los 5 caracteres uno detrás de otro (PATH=), cuando los
// encuentra devuelve 0, si no los encuentra devuelve 1
int	findPATH(char *str) //ISPATH
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T'
		&& str[3] == 'H' && str[4] == '=')
		return (0);
	return (1);
}

// Extraer las rutas del sistema de la variable de entorno PATH y almacenarlas
// en la estructura t_pipex
void get_paths(t_pipex *pipex, char **env) //CN
{
    int i;
	
	i = 0;
	// Bucle que va buscando PATH con findPATH, va sumando 1 a env
	// para pasar a la siguiente variable de entorno
    while (*env)
	{
		if (findPATH(*env) == 0)
			break;
		env++;
	}
	// Dividir la cadena de PATH en un array de cadenas de caracteres
	// utilizando como delimitador el caracter ':'
	pipex->path = ft_split(*env + 5, ':'); //He de sumarle 5?
	printf("%s", pipex->path[0]);
	printf("%s", pipex->path[1]);
	// Añade '/' al final de cada ruta
	while (pipex->path[i])
	{
		pipex->path[i] = ft_strjoin(pipex->path[i], "/");
		i++;
	}
}