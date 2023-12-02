#include "pipex.h"

/*
void	free_dp(char **str)
{
	ez;
}

void	free_cmds(t_cmd *cmds)
{
	t_cmd	*iter;

	iter = cmds;
	while (cmds != NULL)
	{
		cmds = iter;
		if (cmds->cmd && cmds->cmd != NULL)
			free(cmds->cmd);
		if (cmds->wch && cmds->wch != NULL)
			free(cmds->wch);
		if (cmds->path && cmds->path != NULL)
			free(cmds->path);
		if (cmds->input && cmds->input != NULL)
			free(cmds->input);
		free_dp(cmds->flag);
		free_dp(cmds->arr);
		iter = iter->next;
		free(cmds);
	}
}

void	free_all(t_all *all)
{
	if (all->file1 && all->file1 != NULL)
		free(all->file1);
    if (all->file2 && all->file2 != NULL)
		free(all->file2);
	free_cmds(all->cmds);
	free(all);
}
*/

/*
typedef struct s_cmd {
	char	*cmd;
	char	*wch;
	char	*path; //path to cmd
	char	*input; //path to input file
	char	**flag;
	//char	**arr;
	struct s_cmd	*next;
}	t_cmd;

char	*arr[] = {path, input, flags, NULL};

typedef struct s_all {
	char	*file1;
	t_cmd	*cmds;
	char	*file2;
	int		pipe_nmb; //nº argv - 3
	int		flag; //0 para overwite, 1 para append
}	t_all;
*/