# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <functional>
# include <ctime>

class MyCompare
{
	public:
		MyCompare(std::vector<int>& temp, std::vector<int>& origin)
			: mTemp(temp)
			, mOrigin(origin)
		{
		}
		bool operator()(const int& a, const int& b)
		{
			return (mOrigin[mTemp[a]] < mOrigin[mTemp[b]]);
		}
	private:
		std::vector<int>& mTemp;
		std::vector<int>& mOrigin;
};

// bool compare(int a, int b, const std::vector<int>& temp, const std::vector<int>& origin)
// {
// 	return (origin[temp[a]] < origin[temp[b]]);
// }

void sortVector(int size, std::vector<int>& origin, std::vector<int>& temp)
{
	if (size < 2)
	{	
		// for (int i = 0; i < temp.size(); ++i)
		// 	std::cout << temp[i] << ' ';
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
	// std::cout << "size : " << size << '\n';
	// std::cout << "temp before recursive : ";
	// for (int i = 0; i < temp.size(); ++i)
	// 	std::cout << temp[i] << ' ';
	// std::cout << '\n';
	sortVector(size / 2, origin, temp);
	// 3. do binary search with saveed pair index by referencing real value of origin vector
	// 3-1. insert first unsorted element to temp's begin();
	temp.insert(temp.begin(), pairIndex[temp[0]]);
	// 3-2. make vector for binary insert element (not sorted)
	std::vector<int> unsorted;
	for (int i = 1; i < size / 2; ++i)
		unsorted.push_back(pairIndex[temp[i]]);
	//3-2 get start index and binary search size with jacobsthal number
	int n = unsorted.size();
	int prevStart = -1;
	int i = 1;
	int curr = 2; // initial element of sequence
	while (prevStart < n - 1)
	{
		int j = std::min(prevStart + curr, n - 1);
		while (j > prevStart)
		{
			std::vector<int>::iterator low;
			std::vector<int>::iterator start = temp.begin();
			std::vector<int>::iterator end = start + std::min((1 << (i + 1)) - 1, n - 1);
			MyCompare com(temp, origin);
			low = std::lower_bound(start, end, unsorted[j], com);
			temp.insert(low, unsorted[j]);
			--j;
		}
		prevStart = std::min(prevStart + curr, n - 1);
		curr = ((1 << (i + 1)) - curr);
		++i;
	}
	// if remain exist binary search as 'size' amount and insert
	if (remain != -1)
	{
		std::vector<int>::iterator low;
		std::vector<int>::iterator start = temp.begin();
		std::vector<int>::iterator end = start + size;
		MyCompare com(temp, origin);
		low = std::lower_bound(start, end, remain, com);
		temp.insert(low, remain);
	}

}
std::vector<int>	mergeInsertionSortInVector(std::vector<int>& input)
{
	//make index vector
	std::vector<int> temp;
	std::vector<int> ret;
	for (int i = 0; i < input.size(); ++i)
		temp.push_back(i);
	//do merge insert sort
	sortVector(input.size(), input, temp);

	for (int i = 0; i < input.size(); ++i)
	{
		ret.push_back(input[temp[i]]);
	}	
	return ret;
}

int main(int argc, char ** argv)
{
	(void) argc;
	std::vector<int> input;
	std::vector<int> ret;
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

	ret = mergeInsertionSortInVector(input);
	std::cout << "output : ";
	for (int i = 0; i < ret.size(); ++i)
		std::cout << ret[i] << ' ';
	std::cout << '\n';
	return (0);
}