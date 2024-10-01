#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char	**set_up(char *cmd)
{
	char	**comands;

	comands = malloc(10 * sizeof(char *));
	comands[0] = ft_str_join("/usr/local/sbin", cmd);
	comands[1] = ft_str_join("/usr/local/bin", cmd);
	comands[2] = ft_str_join(" /usr/sbin", cmd);
	comands[3] = ft_str_join("/usr/bin", cmd);
	comands[4] = ft_str_join("/sbin", cmd);
	comands[5] = ft_str_join("/bin", cmd);
	comands[6] = ft_str_join("/usr/games", cmd);
	comands[7] = ft_str_join("/usr/local/games", cmd);
	comands[8] = ft_str_join("/snap/bin", cmd);
	comands[10] = ft_str_join("/nfs/homes/lpittigl/.dotnet/tools", cmd);
	return (comands);
}

char	*stack_string(char **comand, int i, int len)
{
	char	s[len + 1];
	int		j;

	j = 0;
	while(comand[i][j])
	{
		s[j] = comand[i][j];
		j++;
	}
	destroy_matrix(comand);
	return (s);
}

void	child_process(int *pipe_fd, char **argv, char **envp)
{
	char	**comand;
	char	**args;
	int		i;
	int		infile;

	i = 0;
	close(pipe_fd[0]);
	infile = open(argv[1], O_RDONLY);
    if (infile == -1) {
        perror("Error opening input file");
        exit(-1);
    }
    dup2(infile, STDIN_FILENO);
    close(infile);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[1]); 
	comand = set_up(argv[2]);
	if (access(argv[1], F_OK | R_OK))
		perror("Error opening file:");
	while(i < 10 && access(comand[i], X_OK))
		i++;
	dup2(pipe_fd[1], STDOUT_FILENO);
	execve(stack_string(comand, i, ft_strlen(comand[i])), argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	__pid_t	pid;
	int		pipe_fd[2];

	if (argc != 5)
		printf("Error\nInput must be ./pipex file1 cmd1 cmd2 file2\n");
	if(pipe(pipe_fd) == -1)
	{
		perror("Error\npipe:");
		return (-1);
	}
	pid = fork();

	if (pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		handle_error("Error\nFailed fork");
	}
	if (pid == 0)
		child_process(pipe_fd, argv, envp);
	else
	{

	}
	
}