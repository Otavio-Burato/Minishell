/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:01:33 by oburato           #+#    #+#             */
/*   Updated: 2023/02/22 20:44:50 by oburato          ###   ########.fr       */
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

# include <sys/types.h>

/**
 * @brief Data storage all variable we need
 */
typedef struct s_data
{
	char	**argv;
	char	**envp;
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
int		ft_sanitize_line(char *line);
// end prompt

/**
 * @brief functionj to find comand path in ENV or redirect to builtins
 *
 * @param line
 * @return int return 1 to OK and 0 to NOK
 */
int		find_cmd(char *cmd, char **env);

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
