#include "21sh.h"

void	insert_char_in_line(char *offset, char ch)
{
	char *before_ins;

	before_ins = ft_memalloc(g_input->pos + 1);
	before_ins = ft_strncpy(before_ins, g_input->line, g_input->pos);
	before_ins[g_input->pos] = ch;
	before_ins[g_input->pos + 1] = '\0';
	free(g_input->line);
	g_input->line = ft_strnew(0);
	g_input->line = ft_strjoin(before_ins, offset);
	free(before_ins);
}

void	delete_char_in_line(void)
{
	char *offset;
	char *before_del;

	offset = get_offset();
	before_del = ft_memalloc(g_input->pos);
	before_del = ft_strncpy(before_del, g_input->line, g_input->pos - 1);
	free(g_input->line);
	g_input->line = ft_strjoin(before_del, offset);
	free(before_del);
	free(offset);
}
