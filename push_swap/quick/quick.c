#include <stdio.h>

int	a[5] = {-9, 8, 2, 1, -4};
int len_a = 5;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b= temp;
}

void quick_sort(int start, int end)
{
	int	pivot;
	int	left;
	int	right;

	if (end <= start + 1)
		return ;
	pivot = a[start];
	left = start + 1;
	right = end - 1;
	while (1)
	{
		while (left <= right && a[left] <= pivot)
			left++;
		while (left <= right && a[right] > pivot)
			right--;
		if (left > right)
			break ;
		swap(&a[left], &a[right]);
	}
	swap(&a[start], &a[right]);
	quick_sort(start, right);
	quick_sort(right + 1, end);
}

int	main(void)
{
	quick_sort(0, 5);
	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);
	return (0);
}