/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:47:11 by albartol          #+#    #+#             */
/*   Updated: 2024/04/18 18:45:20 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	set_error(const char *path)
{
	t_stat	path_info;

	if ((path[0] == '.' && path[1] == '/') || path[0] == '/')
	{
		if (stat(path, &path_info) == -1)
		{
			ft_putstr_fd(path, STDERR);
			ft_putstr_fd(": No such file or directory\n", STDERR);
			return (NOT_FILE_DIR_EXIT);
		}
		if (S_ISDIR(path_info.st_mode))
		{
			ft_putstr_fd(path, STDERR);
			ft_putstr_fd(": Is a directory\n", STDERR);
			return (IS_DIR_EXIT);
		}
		else if (!(S_IXUSR & path_info.st_mode))
		{
			ft_putstr_fd(path, STDERR);
			ft_putstr_fd(": Permission denied\n", STDERR);
			return (PERM_DENIED_EXIT);
		}
	}
	ft_putstr_fd(path, STDERR);
	ft_putstr_fd(": command not found\n", STDERR);
	return (NOT_COMMAND_EXIT);
}

static void	child_execve(t_shell *data, char *path, char **argv, char **envp)
{
	int		exit_code;

	// if (execve(path, argv, envp) == -1)
	// 	perror("execve");
	execve(path, argv, envp);
	free_program(data);
	free(envp);
	ft_free_array(argv);
	exit_code = set_error(path);
	free(path);
	exit(exit_code);
}

static void	new_child_exec(t_shell *data, char *path, char **argv, char **envp)

{
	pid_t	id;
	int		wstatus;

	id = fork();
	if (id == -1)
		return (perror("fork"));
	if (id == 0)
	{
		if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		{
			perror("signal");
			free_program(data);
			free(envp);
			free(path);
			ft_free_array(argv);
			exit(EXIT_FAILURE);
		}
		child_execve(data, path, argv, envp);
	}
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("signal");
	waitpid(id, &wstatus, 0);
	if (WIFEXITED(wstatus))
		data->exit_code = WEXITSTATUS(wstatus);
}

static void	execute(t_shell *data, char *path, char **argv)
{
	char	**envp;

	envp = get_env(data);
	if (!envp)
		perror("malloc");
	if (data->child)
		child_execve(data, path, argv, envp);
	else
		new_child_exec(data, path, argv, envp);
	free(envp);
}

void	ft_exec_bin(char **argv, t_shell *data)
{
	char	*bin_path;
	char	*path;

	path = ft_get_env_value("PATH", data->env);
	bin_path = ft_check_bin(argv[0], path);
	if (!bin_path)
	{
		bin_path = ft_strdup(argv[0]);
		if (!bin_path)
		{
			perror("malloc");
			return ;
		}
		if (!*bin_path)
		{
			free(bin_path);
			return ;
		}
	}
	execute(data, bin_path, argv);
	free(bin_path);
}
