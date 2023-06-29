/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_produce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:44:45 by hyunghki          #+#    #+#             */
/*   Updated: 2023/06/23 18:41:17 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*mk_token(t_lst *target, t_lst *ev, int is_single)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->fd[1] = 1;
	if (ft_split(token, target->data, " \t><", 0) != 0)
		return (ft_node_free(token, F_DATA_TOKEN));
	if (token->argv == NULL && token->redirection == NULL && !is_single)
	{
		ft_error(F_ERROR_SYNTAX);
		return (ft_node_free(token, F_DATA_TOKEN));
	}
	if (ft_expansion(token->argv, 0, ev) != 0)
		return (ft_node_free(token, F_DATA_TOKEN));
	if (ft_expansion(token->redirection, 1, ev) != 0)
		return (ft_node_free(token, F_DATA_TOKEN));
	return (token);
}

t_lst	*mk_token_lst(char *line, t_lst *ev)
{
	t_lst	*line_lst;
	t_lst	*tmp;
	t_lst	*target;
	t_token	*token;

	line_lst = NULL;
	target = NULL;
	if (*line == '|')
		return (ft_lst_free(NULL, NULL, F_DATA_CHAR, F_ERROR_SYNTAX));
	if (ft_split(&line_lst, line, "|", F_PIPE) != 0)
		return (ft_lst_free(line_lst, NULL, F_DATA_CHAR, NULL));
	tmp = line_lst;
	while (tmp != NULL)
	{
		token = mk_token(tmp, ev, (line_lst->nxt == NULL));
		if (token == NULL || lst_push(&target, mk_lst(token, 0)) != 0)
		{
			ft_node_free(token, F_DATA_TOKEN);
			ft_lst_free(line_lst, NULL, F_DATA_CHAR, NULL);
			return (ft_lst_free(target, NULL, F_DATA_TOKEN, NULL));
		}
		tmp = tmp->nxt;
	}
	ft_lst_free(line_lst, NULL, F_DATA_CHAR, NULL);
	return (target);
}

t_lst	*mk_file_lst(char *s, int dir_type)
{
	t_lst	*target;
	t_file	*f;

	f = ft_calloc(sizeof(t_file));
	if (f == NULL)
		return (NULL);
	f->file_name = mk_str_lst(s);
	if (f->file_name == NULL)
		return (ft_node_free(f, F_DATA_FILE));
	if ((dir_type & F_HEREDOC) != 0)
		dir_type &= ~F_INPUT;
	if ((dir_type & F_APPEND) != 0)
		dir_type &= ~F_OUTPUT;
	f->mode = dir_type;
	target = mk_lst(f, 0);
	if (target == NULL)
		return (ft_node_free(f, F_DATA_FILE));
	return (target);
}

t_lst	*mk_str_lst(char *s)
{
	t_lst	*target;
	char	*data;

	target = NULL;
	while (*s)
	{
		data = ft_substr(s, 1);
		if (data == NULL || lst_push(&target, mk_lst(data, 0)) != 0)
		{
			free(data);
			return (ft_lst_free(target, NULL, F_DATA_STRING, NULL));
		}
		s++;
	}
	return (target);
}

t_lst	*mk_hash_lst(char *s)
{
	t_lst	*target_lst;
	t_hash	*target;
	int		i;

	i = 0;
	target = ft_calloc(sizeof(t_hash));
	if (target == NULL)
		return (NULL);
	while (ft_word_chk(s[i], "=", F_CHK) != 0)
		i++;
	target->key = ft_substr(s, i);
	if (target->key == NULL)
		return (ft_node_free(target, F_DATA_HASH));
	s += (i + 1);
	if (*s != '\0')
	{
		target->value = mk_str_lst(s);
		if (target->value == NULL)
			return (ft_node_free(target, F_DATA_HASH));
	}
	target_lst = mk_lst(target, 0);
	if (target_lst == NULL)
		return (ft_node_free(target, F_DATA_HASH));
	return (target_lst);
}
