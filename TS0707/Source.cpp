#include <iostream>
using namespace std;

void sum(int a[], int b[], int maxLen, int minLen, int LenA, int LenB)
{
	int c[200];
	for (int i = 0; i < 200; i++)
	{
		c[i] = 0;
	}
	int mergedSize = 0;
	LenA--;
	LenB--;
	for (int i = 0; i < maxLen; i++)
	{
		if (LenA >= 0 && LenB >= 0)
		{
			c[i] += a[LenA] + b[LenB];
			LenA--;
			LenB--;
		}
		else if (LenA >= 0 && LenB < 0)
		{
			c[i] += a[LenA];
			LenA--;
		}
		else if (LenA < 0 && LenB >= 0)
		{
			c[i] += b[LenB];
			LenB--;
		}
		mergedSize = i;
		if (c[i] > 9)
		{
			c[i] -= 10;
			c[i + 1]++;
			mergedSize = i + 1;
		}
	}
	for (int i = mergedSize; i >= 0; i--)
	{
		cout << c[i];
	}
	cout << endl;
}

void different(int a[], int b[], int maxLen, int minLen,int LenA, int LenB)
{
	int c[200];
	for (int i = 0; i < 200; i++)
	{
		c[i] = 0;
	}
	int mergedSize = 0;
	LenA--;
	LenB--;
	for (int i = 0; i < maxLen; i++)
	{
		if (LenA >= 0 && LenB >= 0)
		{
			if (a[LenA] >= b[LenB])
			{
				c[i] += (a[LenA] - b[LenB]);
			}
			else
			{
				c[i] += a[LenA] + 10 - b[LenB];
				a[LenA - 1]--;
			}
			LenA--;
			LenB--;
		}
		else if (LenA >= 0 && LenB < 0)
		{
			c[i] += a[LenA];
			LenA--;
		}
		if (c[i] != 0)
		{
			mergedSize = i;
		}
	}
	for (int i = mergedSize; i >= 0; i--)
	{
		cout << c[i];
	}
	cout << endl;
}

void product(int a[], int b[], int maxLen, int minLen, int LenA, int LenB)
{
	int c[200];
	for (int i = 0; i < 200; i++)
	{
		c[i] = 0;
	}
	int mergedSize = 0;
	if (LenA >= LenB)
	{
		for (int i = 0; i < LenB; i++)
		{
			for (int j = 0; j < LenA; j++)
			{
				c[i + j] += a[j] * b[i];
				if (c[i + j] > 9)
				{
					c[i + j + 1] += c[i + j] / 10;
					c[i + j] %= 10;
					mergedSize = i + j + 1;
				}
				else
				{
					mergedSize = i + j;
				}
			}
		}
	}
	for (int i = mergedSize; i >= 0; i--)
	{
		cout << c[i];
	}
	cout << endl;
}

int main()
{
	int a[200], b[200];
	string bigA, bigB;
	while (cin >> bigA >> bigB)
	{
		int maxLen = (bigA.length() > bigB.length()) ? bigA.length() : bigB.length();
		int minLen = (bigA.length() < bigB.length()) ? bigA.length() : bigB.length();
		int LenA = bigA.length();
		int LenB = bigB.length();
		for (int i = 0; i < bigA.length(); i++)
		{
			a[i] = bigA[i] - '0';
		}
		for (int i = 0; i < bigB.length(); i++)
		{
			b[i] = bigB[i] - '0';
		}
		sum(a, b, maxLen, minLen, LenA, LenB);
		different(a, b, maxLen, minLen, LenA, LenB);
		product(a, b, maxLen, minLen, LenA, LenB);
	}
}