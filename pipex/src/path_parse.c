/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:53:55 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/30 16:21:56 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_list.h"

static unsigned int	count_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != 0)
	{
		while (s[i] != 0 && s[i] == c)
			i++;
		if (s[i] != 0 && s[i] != c)
			cnt++;
		while (s[i] != 0 && s[i] != c)
			i++;
	}
	return (cnt);
}

static unsigned int	get_word_len(char const *s, char c)
{
	unsigned int	len;

	len = 0;
	while (s[len] != 0 && s[len] != c)
		len++;
	return (len);
}

static char	*make_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	word_len;
	char			*word;

	i = 0;
	word_len = get_word_len(s, c);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (0);
	while (i < word_len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static char	**do_free(char **list)
{
	unsigned int	i;

	i = 0;
	while (list[i])
	{
		free(list[i++]);
	}
	free(list);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**list;
	unsigned int	word_cnt;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	word_cnt = count_word(s, c);
	list = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!list)
		return (0);
	while (i < word_cnt)
	{
		while (s[j] != 0 && s[j] == c)
			j++;
		list[i] = make_word(&s[j], c);
		if (!list[i])
			return (do_free(list));
		while (s[j] != 0 && s[j] != c)
			j++;
		i++;
	}
	list[i] = 0;
	return (list);
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

// void	get_path_list(t_list_info *list_info, char **list)

int	main(int argc, char **argv, char **envp)
{
	int			i;
	char		*path;
	char		*pwd;
	char		**arr_path;
	char		**arr_pwd;
	// t_list_info	path_list;

	i = 0;
	(void)argc;
	(void)argv;
	while (envp[i])
	{	
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			path = envp[i];
		if (ft_strncmp("PWD", envp[i], 3) == 0)
			pwd = envp[i];
		i++;
	}
	path += 5;
	arr_path = ft_split(path, ':');
	pwd += 4;
	arr_pwd = ft_split(pwd, ':');	
	for (int i = 0; arr_path[i]; i++)
		printf("%s\n", arr_path[i]);
	for (int i = 0; arr_pwd[i]; i++)
		printf("%s\n", arr_pwd[i]);
	return (0);
}
