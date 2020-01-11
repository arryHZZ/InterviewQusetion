#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

/*
题目：请实现一个函数，把字符串中的每个空格替换成"%20"。
例如，输入"we are happy."，则输出"we%20are%20happy."。

题目分析：当一眼读完题之后，我们可以感觉到题目并不是很难，当我们每次碰你空格是，将字符串后移2个字符，然后插入
%20这样就可以达到题目要求，但是如果这样的话，那么代码的执行效率就会变得很低。时间复杂度达到了O(N^2)。
	因此我们可以对于题目的时间复杂度进行优化。
	在我们第一次想的方中，我们只是想到了将遇到一个空格代码就向后移动，当下次碰见时，又再移动一次，这样就会导致最后面的字符
会被移动多次，但每次只能移动2个字符的位置。因此我们是不是可以将后面的字符一次移动到相应的位置上，然后再给相应的地方补%20.

实现过程：先统计空格个数，然后从后向前移动，利用快慢指针的思想，将块指针指向最后一个字符要最终移动到的位置上，慢指针指向原
字符串最后一个位置，当慢指针指向的内容并非空格时，直接将慢指针的内容复制给快指针，如果为空格，则将快指针赋值"20%"，然后
慢指针后移，结束条件，当快指针追上慢指针时，则证明将所有空格都已经修改结束。

*/

void ReplaceBlank(char* string, int len)
{
	if (string == NULL || len <= 0)
		return;
	int numberOfBlank = 0; //统计空格的个数
	int oldLength = strlen(string);
	char *pl = string;
	while (*pl != '\0')
	{
		if (*pl == ' ')
			numberOfBlank++;
		pl++;
	}
	int newLength = oldLength + numberOfBlank * 2;
	if (newLength > len)
		return;
	int fast = newLength;
	int slow = oldLength;
	while (string+fast != string+slow)
	{
		if (string[slow] == ' ')
		{
			string[fast--] = '0';
			string[fast--] = '2';
			string[fast--] = '%';
		}
		else
		{
			string[fast--] = string[slow];
		}
		slow--;
	}

}
int main()
{
	char arr[30] = { "we are happy" };
	ReplaceBlank(arr, sizeof(arr));
	return 0;
}