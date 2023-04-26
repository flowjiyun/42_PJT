#include <iostream>
#include <vector>
#include <algorithm>


class MyCompare
{
	public:
		MyCompare(std::vector<int>& origin)
			: mOrigin(origin)
		{
		}
		bool operator()(const int& a, const int& b)
		{
			std::cout << "a : " << a << '\n';
			std::cout << "b : " << b << '\n';
			return (mOrigin[a] < mOrigin[b]);
		}
	private:
		std::vector<int>& mOrigin;
};

// class MyCompare
// {
// 	public:
// 		MyCompare() {};
// 		bool operator()(const int& a, const int& b)
// 		{
// 			std::cout << "a : " << a << '\n';
// 			std::cout << "b : " << b << '\n';
// 			return (a < b);
// 		}
// };

// int main(void)
// {
// 	std::vector<int> temp = {5, 6, 7, 10};

// 	int remain = 11;
// 	std::vector<int>::iterator low;
// 	std::vector<int>::iterator start = temp.begin();
// 	std::vector<int>::iterator end = start + (temp.size());
// 	MyCompare com = MyCompare();
// 	low = std::lower_bound(start, end, remain, com);
// 	std::cout << low - temp.begin() << '\n';
// 	temp.insert(low, remain);

// 	for (int i = 0; i < temp.size(); ++i)
// 	{
// 		std::cout << temp[i] << ' ';
// 	}
	
// 	return 0;
// }

int main(void)
{
	std::vector<int> temp = {0, 1, 2, 3, 4};
	std::vector<int> origin = {5, 6, 7, 10, 9};

	int remain = 4;
	std::vector<int>::iterator low;
	std::vector<int>::iterator start = temp.begin();
	std::vector<int>::iterator end = start + (origin.size() - 1);
	MyCompare com(origin);
	low = std::lower_bound(start, end, remain, com);
	temp.insert(low, remain);

	for (int i = 0; i < origin.size(); ++i)
	{
		std::cout << origin[temp[i]] << ' ';
	}
	
	return 0;
}