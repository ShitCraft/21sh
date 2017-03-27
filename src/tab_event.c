#include "21sh.h"

void	tab_event(void)
{
	if (!g_input->tab_count)
	{
		g_input->tab_count++;
		return ;
	}
	if (ft_strchr(g_input->line, '/'))
		dir_complection();
	else if (ft_strlen(g_input->line))
		display_all_files(get_abs_path("."));
	g_input->tab_count++;
}

char	*get_abs_path(char *path)
{
	char *abs_path;
	char buf[2048];
	char *tmp;

	getcwd(buf, sizeof(buf));
	abs_path = ft_strdup(buf);
	tmp = ft_strjoin(abs_path, path);
	free(abs_path);
	abs_path = tmp;
	return (abs_path);
}

void	display_all_files(char *path)
{
	DIR *dir_stream;
	struct dirent *file;
	
	while (
	dir_stream = opendir(path);
	
}
