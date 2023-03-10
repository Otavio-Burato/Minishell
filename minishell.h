/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msander <msander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:01:33 by oburato           #+#    #+#             */
/*   Updated: 2023/03/04 23:10:08 by msander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"

# include <signal.h>

# include <readline/history.h>
# include <readline/readline.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

# include <sys/types.h>

/**
 * @brief Data storage all variable we need
 */
typedef struct s_data
{
	pid_t	pid;
	char	**argv;
	char	**envp;
	char	**commands;
	char	*cmd;
	char	*pwd_prompt;
}			t_data;

extern t_data				g_data;

// prompt part
/**
 * @brief	this function is resposible by read line by line in terminal
 * and make a previos sixtax check
 */
void	ft_read_line(char **env);

/**
 * @brief a simple function to sanitize string from prompt
 *
 * @param line
 * @return int return 1 to OK and 0 to NOK
 */
char	*ft_sanitize_line(char *line);
// end prompt

/**
 * @brief function to execute comand
 *
 * @param cmd, env
 * @return void
 */
int		exec_argv(char *argv, char **env);

/**
 * @brief function to find specific line in ENV
 *
 * @param env, target
 * @return char *, the line
 */
char	*find_in_env(char **env, char *target);

/**
 * @brief Builtins
*/
void	ft_pwd(void);
void	ft_echo(char *cmd);
void	ft_cd(char *args);

typedef struct sigaction	t_sigaction;

/**
 * @brief the int signal is the ^C signal and it is captured
 * and manipulated in this function
 * @param signal  2
 */
void	ft_handle_sigint(int signal);

/**
 * @brief
 */
void	ft_load_signal(void);
//end signals

//init free

/**
 * @brief
 */
void	ft_destruct_global_variable(void);
//end free

#endif
