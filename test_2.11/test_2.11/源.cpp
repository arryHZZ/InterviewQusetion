#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits.h>

int ArryMin(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
		return INT_MAX;
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

int main()
{
	int arr[5] = { 5, 6, 1, 2, 3 };
	int ret = ArryMin(arr, sizeof(arr)/sizeof(arr[0]));
	printf("%d\n", ret);
	return 0;
}
