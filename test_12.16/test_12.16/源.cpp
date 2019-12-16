#define _CRT_SECURE_NO_WARNINGS
/*
在一个长度为n的数组里面的所有数字都在0 ~ n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
*/


/*
分析：
	从头到尾依次扫描数组中的每个数字，当扫描到下标为i的数字时，首先比较这个数字（用M表示）是不是等于i。
如果是则继续扫描下一个数字，如果不是，则再拿他和第M个数字进行比较，如果他和第M个数字相等，就找到了一个重复的数字，
如果不相等，则进行交换，把M放到属于他的位置。继续重复比较，交换，知道找到这个数字。
*/

#include<stdio.h>


//找到返回重复数组，没找到返回-1
int duplicate(int* arr, int len)
{
	if (arr == NULL || len <= 0)
		return -1;
	for (int i = 0; i < len; )
	{
		if (i != arr[i])
		{
			if (arr[i] == arr[arr[i]])
				return arr[i];
			else
			{
				int tmp = arr[arr[i]];
				arr[arr[i]] = arr[i];
				arr[i] = tmp;
			}
		}
		else
		{
			i++;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 0, 1, 2, 4, 4, 5, 1 };
	int ret = duplicate(arr, sizeof(arr) / sizeof(arr[0]));
	printf("%d\n", ret);
	return 0;
}

/*
算法分析：
	时间复杂度:o(n)
	空间复杂度:o(1)
缺陷:对于原数组进行了操作，使得原数组中的元素位置发生了变化，
	 只能查找到一个重复出现的数字,不能查找出所有的重复元素。
*/
