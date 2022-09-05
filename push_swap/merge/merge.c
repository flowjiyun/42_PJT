/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:22:26 by jiyunpar          #+#    #+#             */
/*   Updated: 2022/09/01 12:48:07 by jiyunpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	a[5] = {-9, 8, 2, 1, -4};
int len_a = 5;
int	temp[5];

void	merge(int start, int end)
{
	int mid = (start + end) / 2;
	int ldx = start;
	int rdx = mid;
	int k = start;

	while (k < end)
	{
		if (ldx == mid)
			temp[k] = a[rdx++];
		else if (rdx == end)
			temp[k] = a[ldx++];
		else if (a[ldx] <= a[rdx])
			temp[k] = a[ldx++];
		else
			temp[k] = a[rdx++];
		k++;
	}
	k = start;
	while (k < end)
	{
		a[k] = temp[k];
		k++;
	}

}
// start : start index
// end : last index + 1
void	merge_sort(int start, int end)
{
	if (end == start + 1)
		return ;
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid, end);
	merge(start, end);
}

int	main(void)
{
	merge_sort(0, len_a);
	for (int i = 0; i < len_a; i++)
		printf("%d ", a[i]);
	printf("\n");
	return (0);
}