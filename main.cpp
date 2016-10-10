#include <iostream>
#include<algorithm>
#define MINVALUE -1 ;
using namespace std;
int cutRod(int p[],int len)
{
	if (len == 0)
	{
		return 0;
	}
	int q = -1;
	for (int i = 1; i <= len; i++)
	{
		q = max(q, p[i] + cutRod(p, len - i));
	}
	return q;
}
//void BottomUpCutRod(int p[], int r[], int s[], int len)
//{
//	r[0] = 0;
//	s[0] = 0;
//	int q = 0;
//	for (int j = 1; j <= len; j++)
//	{
//		q = MINVALUE;
//		for (int i = 1; i <= len; i++)
//		{
//			if (p[i] + r[j - i] > q)
//			{
//				q = p[i] + r[j - i];
//				s[j] = i;
//			}
//			//q = max(q, p[i] + r[j - i]);
//		}
//		r[j] = q;
//	}
//}
int memorizedCutRod(int p[], int r[], int len)
{
	int q = 0;
	if (r[len] > 0)
	{
		return r[len];
	}
	if (len == 0)
	{
		q = 0;
	}
	else
	{
		q = MINVALUE;
		for (int i = 1; i <= len; i++)
		{
			q = max(q, p[i] + memorizedCutRod(p, r, len - i));

		}
		r[len] = q;
	}
	return q;
}

void printS(int s[], int n)
{
	while (n > 0)
	{
		cout << s[n] << " ";
		n = n - s[n];
	}
}
void main()
{
	const int N = 10; 
	int p[N + 1] = {0,1, 5, 8, 9, 10, 17, 17, 20, 24, 30}; // 单根钢条不割的价格
	int r[N + 1] ;// 长度为 N 的钢条的最优价格
	int s[N + 1]; // 长度为N的钢条为达到最优价格，第一刀切在哪？
	int len;
	cin >> len;
	//int tp = cutRod(p, len);
	for (int i = 0; i <= len; i++)
	{
		r[i] = MINVALUE;
	}
	//BottomUpCutRod(p, r, s, len);
	int tp = memorizedCutRod(p, r, len);
	cout << tp << endl;
	
}