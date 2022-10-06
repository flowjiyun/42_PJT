#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 100
#define FD_MAX 256

unsigned int	ft_strlen(const char *str)
{
	unsigned int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char			*temp;
	unsigned int	i;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!temp)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		temp[i] = str[i];
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*temp;
	unsigned int	i;
	unsigned int	j;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		temp[i] = s1[i];
	j = -1;
	while (s2[++j])
		temp[i + j] = s2[j];
	temp[i + j] = '\0';
	free(s1);
	return (temp);
}

int	is_newline(const char *backup)
{
	int	i;

	i = 0;
	if (!backup)
		return (-1);
	while (backup[i] != '\0')
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_memcopy(void *dest, const void *src, size_t size)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	unsigned int	i;

	new_dest = (unsigned char *)dest;
	new_src = (unsigned char *)src;
	i = -1;
	while (++i < size)
		new_dest[i] = new_src[i];
}

char	*read_file(int fd, char **backup, char *buf)
{
	ssize_t	byte;

	while (is_newline(*backup) == -1)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{	
			if (*backup)
				free(*backup);
			free(buf);
			return (NULL);
		}
		if (byte == 0)
			break ;
		buf[byte] = '\0';
		if (!(*backup))
			*backup = ft_strdup(buf);
		else
			*backup = ft_strjoin(*backup, buf);
		if (!(*backup))
			return (NULL);
	}
	free(buf);
	return (*backup);
}

char	*get_line(char **backup)
{
	char			*temp;
	unsigned int	len;

	if ((*backup)[0] == '\0')
		return (NULL);
	len = 0;
	while ((*backup)[len] && (*backup)[len] != '\n')
		len++;
	if ((*backup)[len] == '\n')
	{
		temp = (char *)malloc(sizeof(char) * (len + 2));
		if (!temp)
			return (NULL);
		ft_memcopy(temp, *backup, len + 1);
		++len;
	}
	else
	{
		temp = (char *)malloc(sizeof(char) * (len + 1));
		if (!temp)
			return (NULL);
		ft_memcopy(temp, *backup, len);
	}
	temp[len] = '\0';
	return (temp);
}

char	*update_backup(char **backup)
{
	char			*temp;
	unsigned int	index;
	unsigned int	i;

	index = is_newline(*backup) + 1;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(*backup) + 1));
	if (!temp)
	{
		free(*backup);
		return (NULL);
	}
	if (index >= 1)
	{
		i = -1;
		while (index <= ft_strlen(*backup))
			temp[++i] = (*backup)[index++];
	}	
	else
		temp[0] = '\0';
	free(*backup);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	char		*line;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE == 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	backup = read_file(fd, &backup, buf);
	if (!backup)
		return (NULL);
	line = get_line(&backup);
	if (!line)
	{
		free(backup);
		return (NULL);
	}
	backup = update_backup(&backup);
	if (!backup)
		return (NULL);
	return (line);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			break ;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(int argc, char **argv)
{
	int	fd;
	char *c;

	fd = open("heredoc", O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (argc != 2)
		exit(1);
	while (1)
	{
		write(1, "heredoc> ", 9);
		c = get_next_line(0);
		printf("%d\n", ft_strlen(argv[1]));

		if (ft_strncmp(c, argv[1], ft_strlen(argv[1])) == 0)
			break ;
		write(fd, c, ft_strlen(c));
	}
	close(fd);
	return (0);
}
