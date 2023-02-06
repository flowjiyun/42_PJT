#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; j < (int)strlen(argv[i]); ++j)
		{
			std::cout << (char)toupper(argv[i][j]);
		}
	}
	std::cout << '\n';
	return (0);
}
