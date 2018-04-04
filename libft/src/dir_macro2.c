/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_macro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 20:46:18 by kbensado          #+#    #+#             */
/*   Updated: 2017/08/14 21:42:01 by kbensado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include "../inc/libft_malloc.h"

char				*trunc_path_file(char *path)
{
	size_t			i;
	size_t			len;
	char			*res;

	res = NULL;
	len = ft_strlen(path);
	i = len - 1;
	while (path[i] == '/')
		i--;
	while (path[i] != '/')
		i--;
	res = ft_strsub(path, 0, i);
	ft_printf("trunc_path_file return = %s\n", res);
	return (res);
}

char				*real_pwd_file(char *path, char *res, char *tpwd)
{
	char			*old_pwd;

	old_pwd = getcwd(ft_strnew(MAXPATHLEN), MAXPATHLEN);
	if (dir_exist(path, NULL) == true)
	{
		chdir(path);
		res = getcwd(ft_strnew(MAXPATHLEN), MAXPATHLEN);
		chdir(old_pwd);
		ft_memdel((void *)&old_pwd);
		return (res);
	}
	tpwd = trunc_path_file(path);
	if (dir_exist(tpwd, NULL) == true)
	{
		chdir(tpwd);
		res = getcwd(ft_strnew(MAXPATHLEN), MAXPATHLEN);
		chdir(old_pwd);
		ft_memdel((void *)&old_pwd);
		ft_memdel((void *)&tpwd);
		return (res);
	}
	ft_memdel((void *)&tpwd);
	ft_memdel((void *)&old_pwd);
	return (res);
}
