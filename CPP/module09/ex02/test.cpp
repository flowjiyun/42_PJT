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

int main(void)
{
	std::vector<int> a;
	for (int i = 0; i < 10; ++i)
		a.push_back(i);
	int n = a.size();
	int prevStart = -1;
	int i = 1;
	int curr = 2;
	while (prevStart < n - 1)
	{
		int j = std::min(prevStart + curr, n - 1);
		while (j  > prevStart)
		{
			std::cout << j << ' ';
			--j;
		}
		prevStart = std::min(prevStart + curr, n - 1);
		curr = ((1 << (i + 1)) - curr);
		++i;
	}	
}