/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soilee <soilee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:27:33 by soilee            #+#    #+#             */
/*   Updated: 2020/07/09 16:31:07 by soilee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int num)
{
	char n[2];
	
	n[0] = num / 10 + '0';
	n[1] = num % 10 + '0';
	write(1, &n, 2);
}

void	ft_print_comb2(void)
{
	int nums[2];
	char c[2];

	nums[0] = 0;
	c[0] = ',';
	c[1] = ' ';
	while (nums[0] <= 98)
	{
		nums[1] = nums[0] + 1;
		while (nums[1] <= 99)
		{
			print(nums[0]);
			write(1, &c[1], 1);
			print(nums[1]);
			if (!(nums[0] == 98 && nums[1] == 99))
			{
				write(1, &c, 2);
			}
			nums[1]++;
		}
		nums[0]++;
	}
}
