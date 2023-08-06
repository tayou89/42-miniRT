#include "parsing.h"

static char	*get_buf_readsize(char *buf, char *backup, int *read_size, int fd)
{
	if (ft_strchr(backup, '\n') != NULL)
		return (NULL);
	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (buf == 0)
		return (0);
	*read_size = read(fd, buf, BUFFER_SIZE);
	if (*read_size == -1)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	buf[*read_size] = '\0';
	return (buf);
}

static char	*get_backup(char *buf, char *backup, int read_size, int fd)
{
	char	*temp;

	while (read_size > 0)
	{
		if (backup == NULL)
			backup = ft_strdup(buf);
		else
		{
			temp = backup;
			backup = ft_strjoin(temp, buf);
			free(temp);
		}
		if (ft_strchr(backup, '\n') != NULL)
			break ;
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(backup);
			backup = NULL;
			return (NULL);
		}
		buf[read_size] = '\0';
	}
	return (backup);
}

static char	*get_line(char *line, char *backup)
{
	int		newline_point;
	int		size;
	int		i;

	if (ft_strchr(backup, '\n') != NULL)
	{
		i = 0;
		while (backup[i] != '\n')
			i++;
		newline_point = i;
		size = newline_point + 1;
		line = ft_substr(backup, 0, size);
	}
	else
		line = ft_strdup(backup);
	return (line);
}

static char	*renewal_backup(char *backup)
{
	char	*temp;
	int		newline_point;
	int		start;
	int		size;
	int		i;

	if (ft_strchr(backup, '\n') != NULL)
	{
		i = 0;
		while (backup[i] != '\n')
			i++;
		newline_point = i;
		start = newline_point + 1;
		size = ft_strlen(&backup[start]);
		temp = backup;
		backup = ft_substr(temp, start, size);
		free(temp);
	}
	else
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	char		*line;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = NULL;
	line = NULL;
	read_size = 0;
	buf = get_buf_readsize(buf, backup, &read_size, fd);
	if (read_size == -1 && backup != NULL)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = get_backup(buf, backup, read_size, fd);
	free(buf);
	buf = NULL;
	if (backup == NULL)
		return (NULL);
	line = get_line(line, backup);
	backup = renewal_backup(backup);
	return (line);
}
