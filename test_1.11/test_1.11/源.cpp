#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

/*
��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"��
���磬����"we are happy."�������"we%20are%20happy."��

��Ŀ��������һ�۶�����֮�����ǿ��Ըо�����Ŀ�����Ǻ��ѣ�������ÿ������ո��ǣ����ַ�������2���ַ���Ȼ�����
%20�����Ϳ��Դﵽ��ĿҪ�󣬵�����������Ļ�����ô�����ִ��Ч�ʾͻ��úܵ͡�ʱ�临�Ӷȴﵽ��O(N^2)��
	������ǿ��Զ�����Ŀ��ʱ�临�ӶȽ����Ż���
	�����ǵ�һ����ķ��У�����ֻ���뵽�˽�����һ���ո���������ƶ������´�����ʱ�������ƶ�һ�Σ������ͻᵼ���������ַ�
�ᱻ�ƶ���Σ���ÿ��ֻ���ƶ�2���ַ���λ�á���������ǲ��ǿ��Խ�������ַ�һ���ƶ�����Ӧ��λ���ϣ�Ȼ���ٸ���Ӧ�ĵط���%20.

ʵ�ֹ��̣���ͳ�ƿո������Ȼ��Ӻ���ǰ�ƶ������ÿ���ָ���˼�룬����ָ��ָ�����һ���ַ�Ҫ�����ƶ�����λ���ϣ���ָ��ָ��ԭ
�ַ������һ��λ�ã�����ָ��ָ������ݲ��ǿո�ʱ��ֱ�ӽ���ָ������ݸ��Ƹ���ָ�룬���Ϊ�ո��򽫿�ָ�븳ֵ"20%"��Ȼ��
��ָ����ƣ���������������ָ��׷����ָ��ʱ����֤�������пո��Ѿ��޸Ľ�����

*/

void ReplaceBlank(char* string, int len)
{
	if (string == NULL || len <= 0)
		return;
	int numberOfBlank = 0; //ͳ�ƿո�ĸ���
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