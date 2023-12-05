/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacucalo <lacucalo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:03:10 by lacucalo          #+#    #+#             */
/*   Updated: 2023/12/05 16:55:36 by lacucalo         ###   ########.fr       */
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
        return;
    }
    if(env == NULL || *env == NULL)  //En caso de no haber variables de entorno
    {
        perror("Error no env");
        return;
    }
    pipe(pipex.fd);
    pid = fork();
    if(pipex.fd == -1)
    {
        perror("Error pip(ing)");
        return;
    }
    if(pid == -1)
    {
        perror("Error fork(ing)");
        return;
    }
    if (pid == 0)
    {
        close(pipex.fd[0]);
        dup2(pipex.fd[1], 1);
        close(pipex.fd[1]);
        execlp(argv[1], argv[1], NULL);
    }
    else
    {
        close(pipex.fd[1]);
        dup2(pipex.fd[0], 0);
        close(pipex.fd[0]);
        waitpid(pid, NULL, 0);
        execlp(argv[2], argv[2], NULL);
    }
    return (0);
}