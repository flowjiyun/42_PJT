#include <iostream>
#include <vector>
#include <algorithm>


// int main(void)
// {
// 	std::vector<int> a = {1, 3, 54, 2};

// 	std::vector<int>::iterator low;
// 	low = std::lower_bound(a.begin(), a.begin() + 3, 2);
// 	std::cout << low - a.begin() << std::endl;
// 	a.insert(low, 2);
// 	for (auto i : a)
// 		std::cout << i << '\n';
// }

// int main(void)
// {
// 	std::vector<int> a;
// 	for (int i = 0; i < 10; ++i)
// 		a.push_back(i);
// 	int n = a.size();
// 	int prevStart = -1;
// 	int i = 1;
// 	int curr = 2;
// 	while (prevStart < n - 1)
// 	{
// 		int j = std::min(prevStart + curr, n - 1);
// 		while (j  > prevStart)
// 		{
// 			std::cout << j << ' ';
// 			--j;
// 		}
// 		prevStart = std::min(prevStart + curr, n - 1);
// 		curr = ((1 << (i + 1)) - curr);
// 		++i;
// 	}	
// }

void sortVector(int size, std::vector<int>& origin, std::vector<int>& temp)
{
	if (size < 2)
	{	
		for (int i = 0; i < temp.size(); ++i)
			std::cout << temp[i] << ' ';
		return;
	}
	int remain = -1;
	std::vector<int> pairIndex;
	pairIndex.resize(origin.size(), -1);
	// 1. check pair & swap
	// 2. make pair index vector for radomaccess
	for (int i = 0; i < size / 2; ++i)
	{
		if (origin[temp[i]] < origin[temp[i + (size / 2)]])
		{
			std::swap(temp[i], temp[i + (size / 2)]);
			pairIndex[temp[i + (size / 2)]] = temp[i];
		}
		else
			pairIndex[temp[i]] = temp[i + (size / 2)];
	}
	if (size & 1)
		remain = temp[size - 1];
	std::cout << "size : " << size << '\n';
	std::cout << "temp before recursive : ";
	for (int i = 0; i < temp.size(); ++i)
		std::cout << temp[i] << ' ';
	std::cout << '\n';
	sortVector(size / 2, origin, temp);
	// // 3. do binary search with saveed pair index by referencing real value of origin vector
	// // 3-1 make vector for binary insert element (not sorted)
	// std::vector<int> unsorted;
	// unsorted.reserve(size / 2);
	// for (int i = 0; i < size / 2; ++i)
	// 	unsorted.push_back(pairIndex[temp[i]]);
	// //3-2 get start index and binary search size with 	
}
void	mergeInsertionSortInVector(std::vector<int>& input)
{
	//make index vector
	std::vector<int> temp;
	for (int i = 0; i < input.size(); ++i)
		temp.push_back(i);
	//do merge insert sort
	sortVector(input.size(), input, temp);
}

int main(int argc, char ** argv)
{
	(void) argc;
	std::vector<int> input;
	int i = 1;
	while(argv[i])
	{
		input.push_back(atoi(argv[i]));
		++i;
	}
	std::cout << "input : ";
	for (int i = 0; i < input.size(); ++i)
		std::cout << input[i] << ' ';
	std::cout << '\n';

	mergeInsertionSortInVector(input);
	return (0);
}