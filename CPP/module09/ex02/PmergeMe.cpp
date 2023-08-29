/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:06:24 by jiyunpar          #+#    #+#             */
/*   Updated: 2023/08/29 15:36:21 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

MyCompareVector::MyCompareVector(std::vector<int>& origin)
	: mOrigin(origin)
{
}

MyCompareVector::MyCompareVector(const MyCompareVector& other)
	: mOrigin(other.mOrigin)
{
}

MyCompareVector::~MyCompareVector()
{
}

bool MyCompareVector::operator()(const int& a, const int& b)
{
	return (mOrigin[a] < mOrigin[b]);
}

MyCompareDeque::MyCompareDeque(std::deque<int>& origin)
	: mOrigin(origin)
{
}

MyCompareDeque::MyCompareDeque(const MyCompareDeque& other)
	: mOrigin(other.mOrigin)
{
}

MyCompareDeque::~MyCompareDeque()
{
}

bool MyCompareDeque::operator()(const int& a, const int& b)
{
	return (mOrigin[a] < mOrigin[b]);
}

static void sortVector(int size, std::vector<int>& origin, std::vector<int>& temp)
{
	if (size < 2)
		return;
	int remain = -1;
	int mid = size / 2;
	std::vector<int> pairIndex(origin.size(), -1);
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
  // 정렬 후보군 중 정렬 시작 값의 위치
	int prevStart = 0;
  // jacob 계산 시작 인덱스
	int i = 1;
  // 정렬 후보군 중 현 step에서 정렬 할 갯수
  // 2 2 6 10
	int curr = 2;
	while (prevStart < n)
	{
    //정렬 후보군 중 정렬될 마지막 값의 위치
		int j = std::min(prevStart + curr - 1, n - 1);
    // 마지막 값부터 넣어야 최적화 (최소 비교 가능)
		while (j >= prevStart)
		{
			std::vector<int>::iterator low;
			std::vector<int>::iterator start = temp.begin();
			std::vector<int>::iterator end = start + std::min((1 << (i + 1)) - 1, sortedCnt);
			MyCompareVector com(origin);
			low = std::lower_bound(start, end, unsorted[j], com);
			temp.insert(low, unsorted[j]);
			++sortedCnt;
			--j;
		}
		prevStart = std::min(prevStart + curr, n);
		curr = ((1 << (i + 1)) - curr);
		++i;
	}
	if (remain != -1)
	{
		std::vector<int>::iterator low;
		std::vector<int>::iterator start = temp.begin();
		std::vector<int>::iterator end = start + (size - 1);
		MyCompareVector com(origin);
		low = std::lower_bound(start, end, remain, com);
		temp.insert(low, remain);
	}
}

static void sortDeque(int size, std::deque<int>& origin, std::deque<int>& temp)
{
	if (size < 2)
		return;
	int remain = -1;
	int mid = size / 2;
	std::deque<int> pairIndex(origin.size(), -1);
	for (int i = 0; i < mid; ++i)
	{
		if (origin[temp[i]] < origin[temp[i + mid]])
			std::swap(temp[i], temp[i + mid]);
		pairIndex[temp[i]] = temp[i + mid];
	}
	if (size & 1)
		remain = temp[size - 1];
	sortDeque(size / 2, origin, temp);

	std::deque<int> unsorted;
	for (int i = 0; i < mid; ++i)
		unsorted.push_back(pairIndex[temp[i]]);
	temp.insert(temp.begin(), *unsorted.begin());
	unsorted.erase(unsorted.begin());

	int n = unsorted.size();
	int sortedCnt = (size / 2) + 1;
  // 정렬 후보군 중 정렬 시작 값의 위치
	int prevStart = 0;
  // jacob 계산 시작 인덱스
	int i = 1;
  // 정렬 후보군 중 현 step에서 정렬 할 갯수
  // 2 2 6 10
	int curr = 2;
	while (prevStart < n)
	{
    //정렬 후보군 중 정렬될 마지막 값의 위치
		int j = std::min(prevStart + curr - 1, n - 1);
    // 마지막 값부터 넣어야 최적화 (최소 비교 가능)
		while (j >= prevStart)
		{
			std::deque<int>::iterator low;
			std::deque<int>::iterator start = temp.begin();
			std::deque<int>::iterator end = start + std::min((1 << (i + 1)) - 1, sortedCnt);
			MyCompareDeque com(origin);
			low = std::lower_bound(start, end, unsorted[j], com);
			temp.insert(low, unsorted[j]);
			++sortedCnt;
			--j;
		}
		prevStart = std::min(prevStart + curr, n);
		curr = ((1 << (i + 1)) - curr);
		++i;
	}
	if (remain != -1)
	{
		std::deque<int>::iterator low;
		std::deque<int>::iterator start = temp.begin();
		std::deque<int>::iterator end = start + (size - 1);
		MyCompareDeque com(origin);
		low = std::lower_bound(start, end, remain, com);
		temp.insert(low, remain);
	}
}

std::vector<int>	mergeInsertionSortInVector(std::vector<int>& input)
{
	std::vector<int> temp;
	std::vector<int> ret;
	int size = input.size();

	for (int i = 0; i < size; ++i)
		temp.push_back(i);

	sortVector(size, input, temp);

	for (int i = 0; i < size; ++i)
		ret.push_back(input[temp[i]]);

	return ret;
}

std::deque<int>	mergeInsertionSortInDeque(std::deque<int>& input)
{
	std::deque<int> temp;
	std::deque<int> ret;
	int size = input.size();

	for (int i = 0; i < size; ++i)
		temp.push_back(i);

	sortDeque(size, input, temp);

	for (int i = 0; i < size; ++i)
		ret.push_back(input[temp[i]]);

	return ret;
}