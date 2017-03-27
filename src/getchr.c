#include "21sh.h"

extern int g_ttyfd;
extern struct termios g_orig;

char	handle_buf(char *buf)
{
	char	ch;

	ch = 0;
	if (!ft_strcmp(buf, K_UP))
		kup_event();
	else if (!ft_strcmp(buf, K_D))
		kd_event();
	else if (!ft_strcmp(buf, K_R))
		kr_event();
	else if (!ft_strcmp(buf, K_L))
		kl_event();
	else if (!ft_strcmp(buf, K_CR))
		kcr_event();
	else if (!ft_strcmp(buf, K_CL))
		kcl_event();
	else if (!ft_strcmp(buf, K_CU))
		kcu_event();
	else if (!ft_strcmp(buf, K_CD))
		kcd_event();
	else if (buf[0] == 127)
		bs_event();
	else if (buf[0] == 32)
		sp_event();
	else if (!ft_strcmp(buf, K_HO))
		khome_event();
	else if (!ft_strcmp(buf, K_EN))
		kend_event();
	else if (buf[0] == 4)
		ch = kctrd_event();
//	else if (buf[0] = 9)
//		tab_event();
	else if (buf[0] >= 33 && buf[0] <= 126)
		output_event(buf[0]);
	else if (buf[0] == 10)
	{
		ch = 10;
		write(1, &ch, 1);
	}
	else if (buf[0] == 9)
		ft_putstr("1");
	else if (buf[0] == 12)
	{
		cl_event();
		print_curr_dir(environ);
	}
	return (ch);
}

char	get_chr(void)
{
	char	buf[16];
	int		res;
	char	ch;

	bzero(buf, sizeof(buf));
	res = read(g_ttyfd, buf, sizeof(buf));
	while (!res)
		res = read(g_ttyfd, buf, sizeof(buf));
	ch = handle_buf(buf);
	return (ch);
}

void	handle_input(void)
{
	struct termios	raw;
	char			res;

	g_ttyfd = 0;
	if (!isatty(g_ttyfd))
		exit(0);
	tcgetattr(g_ttyfd, &g_orig);
	raw = g_orig;
	raw.c_cflag = (CS8);
	raw.c_lflag &= ~(ECHO | ICANON);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 0;
	tcsetattr(g_ttyfd, TCSANOW, &raw);
	res = 0;
	while (res != '\n')
		res = get_chr();
	if (tcsetattr(g_ttyfd, TCSAFLUSH, &g_orig) < 0)
		ft_putendl_fd("cannot restore settings!", 2);
}

int		get_entry(void)
{
	if (!tgetent(0, getenv("TERM")))
			return (0);
	return (1);
}
