# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <functional>
# include <ctime>

class MyCompare
{
	public:
		MyCompare(std::vector<int>& origin)
			: mOrigin(origin)
		{
		}
		bool operator()(const int& a, const int& b)
		{
			return (mOrigin[a] < mOrigin[b]);
		}
	private:
		std::vector<int>& mOrigin;
};

void sortVector(int size, std::vector<int>& origin, std::vector<int>& temp)
{
	if (size < 2)
		return;
	int remain = -1;
	int mid = size / 2;
	std::vector<int> pairIndex;
	pairIndex.resize(origin.size(), -1);
	for (int i = 0; i < mid; ++i)
	{
		if (origin[temp[i]] < origin[temp[i + mid]])
			std::swap(temp[i], temp[i + mid]);
		pairIndex[temp[i]] = temp[i + mid];
	}
	if (size & 1)
		remain = temp[size - 1];
	sortVector(size / 2, origin, temp);
	std::vector<int> unsorted;
	for (int i = 0; i < mid; ++i)
		unsorted.push_back(pairIndex[temp[i]]);
	temp.insert(temp.begin(), *unsorted.begin());
	unsorted.erase(unsorted.begin());
	int n = unsorted.size();
	int sortedCnt = (size / 2) + 1;
	int prevStart = -1;
	int i = 1;
	int curr = 2;
	while (prevStart < n - 1)
	{
		int j = std::min(prevStart + curr, n - 1);
		while (j > prevStart)
		{
			std::vector<int>::iterator low;
			std::vector<int>::iterator start = temp.begin();
			std::vector<int>::iterator end = start + std::min((1 << (i + 1)) - 1, sortedCnt);
			MyCompare com(origin);
			low = std::lower_bound(start, end, unsorted[j], com);
			temp.insert(low, unsorted[j]);
			++sortedCnt;
			--j;
		}
		prevStart = std::min(prevStart + curr, n - 1);
		curr = ((1 << (i + 1)) - curr);
		++i;
	}
	if (remain != -1)
	{
		std::vector<int>::iterator low;
		std::vector<int>::iterator start = temp.begin();
		std::vector<int>::iterator end = start + (size - 1);
		MyCompare com(origin);
		low = std::lower_bound(start, end, remain, com);
		temp.insert(low, remain);
	}
}

std::vector<int>	mergeInsertionSortInVector(std::vector<int>& input)
{
	std::vector<int> temp;
	std::vector<int> ret;
	for (size_t i = 0; i < input.size(); ++i)
		temp.push_back(i);
	sortVector(input.size(), input, temp);

	for (size_t i = 0; i < input.size(); ++i)
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
	for (size_t i = 0; i < input.size(); ++i)
		std::cout << input[i] << ' ';
	std::cout << '\n';

	ret = mergeInsertionSortInVector(input);
	std::cout << "output : ";
	for (size_t i = 0; i < ret.size(); ++i)
		std::cout << ret[i] << ' ';
	std::cout << '\n';
	// sort check
	sort(input.begin(), input.end());
	for (size_t i = 0; i < input.size(); ++i)
	{
		if (input[i] != ret[i])
		{
			std::cout << "fail!" << '\n';
			break;
		}
	}
	std::cout << "ok" << '\n';
	return (0);
}