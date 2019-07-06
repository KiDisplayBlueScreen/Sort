#include "pch.h"
#include <iostream>
#include<Windows.h>
#include <random>
#pragma warning(disable:4996)
using namespace std;



VOID Swap(PINT A, PINT B)
{
	INT Temp = *A;
	*A = *B;
	*B = Temp;
}

PINT ArrayGenerate(ULONG CountOfElement)
{
	PINT Array = (PINT)malloc(CountOfElement * sizeof(INT));
	if (Array == NULL) return 0;
	memset(Array, 0, CountOfElement * sizeof(INT));

	default_random_engine RandomNumbers(GetTickCount());

	for (ULONG i = 0; i <= CountOfElement - 1; i++)
	{
		Array[i] = RandomNumbers() % 100;
	}

	return Array;
}

VOID SelectSort(PINT Array, ULONG CountOfElement)
{
	for (int i = 0; i < CountOfElement-1; i++)
	{
		int min = i;

		for (int j = i + 1; j < CountOfElement; j++)
		{
			if (Array[min] > Array[j]) min = j;//�ҵ���Сֵ���±�.
	    }
		Swap(&Array[i], &Array[min]);
	}

}
VOID InsertSort(PINT Array, ULONG CountOfElement)
{
	UINT i = 1;
	INT j = i - 1;
	UINT CurrentPos;
	for (i = 1; i <= CountOfElement - 1; i++)
	{
		CurrentPos = i;
		int Temp = i;
		for (j = i - 1; j >= 0; j--)
		{
			if (Array[j] > Array[i])//�����ߵ�Ԫ�رȵ�ǰ�Ĵ�.
			{
				CurrentPos--;
				continue;
			}
			else break;//�����һ��Ԫ�رȵ�ǰ��С���˳�ѭ��,׼�����뵽���Ԫ�ص��ұ�
		
		}
		
		if (CurrentPos == i) break;

		else
		{
			for (; Temp > CurrentPos; Temp--)
			{
				Swap(&Array[Temp], &Array[Temp - 1]);//�ӵ�ǰλ�ÿ�ʼֱ���ȵ�ǰԪ��С���Ǹ�Ԫ��Ϊֹ���н���.
			}
		}
	}
}
VOID BubbleSort(PINT Array, ULONG CountOfElement)
{
	for (int i = 0; i < CountOfElement; i++)
	{
		for (int j =0; j < CountOfElement - 1-i; j++)//ÿ����ѭ��������߿�ʼ,����ȥ�������Ԫ��Ϊֹ.
		{
			if (Array[j +1] < Array[j])
			{
				Swap(&Array[j+1], &Array[j]);
			}
		}
	}

}



int main()
{
	ULONG CountOfElement;
	cout << "Input the numbers of elements: " << endl;
	cin>> CountOfElement;
	cout << endl;

	PINT Array = ArrayGenerate(CountOfElement);

	cout << "The Elements of This Array are: "<< endl;
	for (ULONG i = 0; i <= CountOfElement - 1; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
	cout << endl;

	BubbleSort(Array, CountOfElement);
	cout << "The Elements of This Array After Sort are: " << endl;
	for (ULONG i = 0; i <= CountOfElement - 1; i++)
	{
		cout << Array[i] << " ";
	}

	cout << endl;
	cout << endl;
	char str[1];
	scanf("%s", str);
	printf("%s\n", str);
	printf("%d\n", strlen(str));

     



	cout << endl;
	system("pause");
	return 0;
}

