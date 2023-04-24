/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:04:26 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/04/24 15:23:26 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool isValidToken(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false);
}

static bool isValidInput(std::string operation)
{
	for (int i = 0 ; i < static_cast<int>(operation.length()); ++i)
	{
		if (isspace(operation[i]))
			continue;
		if (!isValidToken(operation[i]) && !isdigit(operation[i]))
			return (false);
	}
	return (true);
}

static long doOperation(int left, int right, char token)
{
	long ret;

	switch (token)
	{
	case '+':
		ret = left + right;
		if (ret < std::numeric_limits<int>::min() || ret > std::numeric_limits<int>::max())
			throw -1;
		break;
	case '-':
		ret = left - right;
		if (ret < std::numeric_limits<int>::min() || ret > std::numeric_limits<int>::max())
			throw -1;
		break;	
	case '*':
		ret = left * right;
		if (ret < std::numeric_limits<int>::min() || ret > std::numeric_limits<int>::max())
			throw -1;
		break;
	case '/':
		ret = left / right;
		if (ret < std::numeric_limits<int>::min() || ret > std::numeric_limits<int>::max())
			throw -1;
		break;
	}
	return (ret);
}

int	doRpn(std::string operation)
{
	int ret;
	std::stack<int> data;
	if (!isValidInput(operation))
		throw -1;
	for (int i = 0 ; i < static_cast<int>(operation.length()); ++i)
	{
		if (isspace(operation[i]))
			continue;	
		if (!data.empty())
		{
			if (isValidToken(operation[i]))
			{
				int right = data.top();
				data.pop();
				int left = data.top();
				data.pop();
				if (operation[i] == '/' && right == 0)
					throw -1;
				ret = static_cast<int>(doOperation(left, right, operation[i]));
				data.push(ret);
			}
			else
				data.push(operation[i] - '0');
		}
		else
		{
			if (isValidToken(operation[i]))
				throw -1;
			else
				data.push(operation[i] - '0');
		}
	}
	if (data.size() == 1)
		std::cout << data.top() << '\n';
	else
		throw -1;
	return (ret);	
}