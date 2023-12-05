/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacucalo <lacucalo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:06:08 by lacucalo          #+#    #+#             */
/*   Updated: 2023/12/05 17:00:27 by lacucalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

typedef struct s_pipex
{
    int fd[2]; //tamaño de 2, posiciones 0 y 1, (0 lectura, 1 escritura)?
    //int pid;
    //char *path[2];
    //char **cmd1;
    //char **cmd2;    
}   t_pipex;

int main(int argc, char *argv[], char **env);

#endif