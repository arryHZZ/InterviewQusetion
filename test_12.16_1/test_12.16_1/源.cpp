#define _CRT_SECURE_NO_WARNINGS
/*
��������:���޸������ҳ��ظ������֡�
	��һ������Ϊn+1��������������е����ֶ���1 ~ n�ķ�Χ�ڣ�����������������һ���������ظ��ġ����ҳ�����������һ���ظ������֣�
�������޸���������顣�磺���볤��Ϊ8 ������{2��3��5��4, 3, 2, 4, 7}����ô��Ӧ��������ظ�������2����3��
*/

/*
�������:
	����һ��ʹ�ù�ϣ˼��
		���ǿ��Դ���һ������Ϊn+1����������¼ÿ�����ֳ��ֵĴ����������ּ�¼���ֵĴ���һ������2�Σ���֤���ҵ����ظ����ֵ����֡�
*/

#include<stdio.h>
#include<malloc.h>
#include<string>

//�ҵ������ظ������֣��Ҳ�������-1
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
�㷨������
	ʱ�临�Ӷ�: o(n);
	�ռ临�Ӷ�: o(n);
	�ŵ�:����ԭ��������û�н����޸ġ�
	ȱ��:�����˶���Ŀռ䣬�ռ临����ߡ������ҵ����е��ظ������֡�
*/


/*
	������:���ǰѴ� 1~n�����ִ��м��������m���л��֣�ǰһ��Ϊ1~m����һ��Ϊ m+1 ~ n�����ǰһ�����ֳ��ֵĴ�������m��
��ǰһ����һ�������ظ����ֵ����֣������ظ����ֵ�����һ���ں�һ�롣�����������ظ����ֳ��ֵ�������л��֣�ֱ���ҵ��ظ����ֵ����֣�
����������ڶ��ֲ��ҡ�
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

//�ҵ������ظ������֣��Ҳ�������-1
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
�㷨������
	ʱ�临�Ӷ�:o(nlogn);
	�ռ临�Ӷ�:o(1);
	�ŵ�:û�ж�ԭ��������޸ģ�Ҳû�п��ٶ���Ŀռ䡣
	ȱ��:���ܽ������ظ��������ҵ���ʱ�������������ӣ������Խ��ܡ�
*/