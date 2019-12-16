#define _CRT_SECURE_NO_WARNINGS
/*
问题描述:不修改数组找出重复的数字。
	在一个长度为n+1的数组里面的所有的数字都在1 ~ n的范围内，所有数字中至少有一个数字是重复的。请找出数组中任意一个重复的数字，
但不能修改输入的数组。如：输入长度为8 的数组{2，3，5，4, 3, 2, 4, 7}，那么对应输出的是重复的数字2或者3。
*/

/*
问题分析:
	方法一：使用哈希思想
		我们可以创建一个长度为n+1的数组来记录每个数字出现的次数，当发现记录出现的次数一旦超过2次，则证明找到了重复出现的数字。
*/

#include<stdio.h>
#include<malloc.h>
#include<string>

//找到返回重复的数字，找不到返回-1
int getDuplication1(int* arr, int len)
{
	if (arr == NULL || len <= 0)
		return -1;
	int* count = (int *)malloc(sizeof(int)* (len + 1));
	memset(count, 0, (sizeof(int))*(len + 1));
	for (int i = 0; i < len; i++)
	{
		if ((++count[arr[i]]) >= 2)
		{
			free(count);
			return i;
		}
	}
	return -1;
}

/*
算法分析：
	时间复杂度: o(n);
	空间复杂度: o(n);
	优点:对于原数组内容没有进行修改。
	缺点:开辟了额外的空间，空间复杂提高。不能找到所有的重复的数字。
*/


/*
	方法二:我们把从 1~n的数字从中间进行数字m进行划分，前一半为1~m，后一半为 m+1 ~ n。如果前一半数字出现的次数超过m，
则前一半中一定包含重复出现的数字，否则重复出现的数字一定在后一半。继续将存在重复数字出现的区域进行划分，直至找到重复出现的数字，
其过程类似于二分查找。
*/

int getCount(int* arr, int len, int begin, int mid)
{
	if (arr == NULL)
		return 0;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= begin && arr[i] <= mid)
			++count;
	}
	return count;
}

//找到返回重复的数字，找不到返回-1
int getDuplication2(int* arr, int len)
{
	if (arr == NULL || len <= 0)
		return -1;
	int begin = 1;
	int end = len - 1;
	while (begin <= end)
	{
		int mid = (end - begin) / 2 + begin;
		int count = getCount(arr, len, begin, mid);
		if (begin == end)
		{
			if (count > 1)
				return begin;
			else
				break;
		}
		if (count > (mid - begin + 1))
			end = mid;
		else
			begin = mid + 1;
	}
	return -1;
}

int main()
{
	int arr[] = { 2, 1, 5, 4, 3, 2, 4, 7 };
	/*int ret = getDuplication1(arr, sizeof(arr) / sizeof(arr[0]));*/
	int ret = getDuplication2(arr, sizeof(arr) / sizeof(arr[0]));
	printf("%d", ret);
	return 0;
}


/*
算法分析：
	时间复杂度:o(nlogn);
	空间复杂度:o(1);
	优点:没有对原数组进行修改，也没有开辟额外的空间。
	缺点:不能将所有重复的数字找到，时间消耗略有增加，但可以接受。
*/