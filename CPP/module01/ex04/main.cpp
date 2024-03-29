/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:24:27 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/03/10 15:33:46 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	std::string str1;
	std::string str2;
	std::string fileName;
	std::string fileNameReplaced;
	std::fstream file;
	std::fstream fileReplaced;

	if (argc != 4)
	{
		std::cout << "Input Error : file string1 string2!" <<std::endl;
		return (1);
	}
	fileName = argv[1];
	str1 = argv[2];
	str2 = argv[3];
	file.open(fileName.c_str(), std::ios_base::in);
	if (!file.is_open())
	{
		std::cout << "can't open file" << std::endl;
		return (1);
	}
	fileNameReplaced = fileName + ".replace";
	fileReplaced.open(fileNameReplaced.c_str(), std::ios_base::out | std::ios_base::trunc);
	if (!fileReplaced.is_open())
	{
		std::cout << "can't open file" << std::endl;
		return (1);
	}
	while (!file.eof())
	{
		std::string val;
		getline(file, val);
		if (!file.fail())
		{
			size_t pos = 0;
			while ((pos = val.find(str1, pos)) != std::string::npos)
			{
				val.erase(pos, str1.size());
				val.insert(pos, str2);
				pos += str2.size();
			}
			if (!file.eof())
				fileReplaced << val << '\n';
			else
				fileReplaced << val;
		}
		else
		{
			std::cout << "getline fail" << std::endl;
			break;
		}
	}
	file.close();
	fileReplaced.close();
	return (0);
}
