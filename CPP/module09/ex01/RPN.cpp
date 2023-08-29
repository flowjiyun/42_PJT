/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:04:26 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/08/29 14:31:03 by jiyunpar         ###   ########.fr       */
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

static float doOperation(float left, float right, char token)
{
	double ret;

	switch (token)
	{
	case '+':
		ret = left + right;
		break;
	case '-':
		ret = left - right;
		break;	
	case '*':
		ret = left * right;
		break;
	case '/':
		ret = left / right;
		break;
	}
  if ((ret > 0 && ret < std::numeric_limits<float>::min()) || ret > std::numeric_limits<float>::max() || ret < -std::numeric_limits<float>::max() || (ret > -std::numeric_limits<float>::min() && ret < 0)) {
    throw -1;
  }
	return (static_cast<float>(ret));
}

int	doRpn(std::string operation)
{
	float ret;
	std::stack<float> data;
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
				float right = data.top();
				data.pop();
				float left = data.top();
				data.pop();
				if (operation[i] == '/' && right == 0)
					throw -1;
				ret = doOperation(left, right, operation[i]);
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