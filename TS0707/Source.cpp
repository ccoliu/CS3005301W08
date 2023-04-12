#include <iostream>
using namespace std;


void sum(int ma[], int mb[], int maxLen, int minLen, int LenA, int LenB, bool isNegative)
{
	int a[200], b[200];
	int c[200];
	for (int i = 0; i < 200; i++)
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	for (int i = 0; i < LenA; i++)
	{
		a[i] = ma[i];
	}
	for (int i = 0; i < LenB; i++)
	{
		b[i] = mb[i];
	}
	int mergedSize = LenA + LenB;
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
		if (c[i] > 9)
		{
			c[i] -= 10;
			c[i + 1]++;
		}
	}
	bool spareZero = true;
	if (isNegative)
	{
		cout << "-";
	}
	for (int i = mergedSize; i >= 0; i--)
	{
		if (spareZero && c[i] == 0 && i != 0)
		{
			continue;
		}
		else
		{
			spareZero = false;
		}
		cout << c[i];
	}
	cout << endl;
}

void different(int ma[], int mb[], int maxLen, int minLen, int LenA, int LenB, bool isNegative) //problems....
{
	int a[200], b[200];
	int c[200];
	for (int i = 0; i < 200; i++)
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	for (int i = 0; i < LenA; i++)
	{
		a[i] = ma[i];
	}
	for (int i = 0; i < LenB; i++)
	{
		b[i] = mb[i];
	}
	int mergedSize = LenA + LenB;
	LenA--;
	LenB--;
	if (LenA >= LenB)
	{
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
					if (LenA != 0)
					{
						c[i] += a[LenA] + 10 - b[LenB];
						a[LenA - 1]--;
					}
					else
					{
						isNegative = !isNegative;
						c[i] += abs(a[LenA] - b[LenB]);
					}
				}
				LenA--;
				LenB--;
			}
			else if (LenA >= 0 && LenB < 0)
			{
				c[i] += a[LenA];
				LenA--;
			}
		}
	}
	else
	{
		isNegative = !isNegative;
		for (int i = 0; i < maxLen; i++)
		{
			if (LenA >= 0 && LenB >= 0)
			{
				if (b[LenB] >= a[LenA])
				{
					c[i] += (b[LenB] - a[LenA]);
				}
				else
				{
					if (LenB != 0)
					{
						c[i] += b[LenB] + 10 - a[LenA];
						b[LenB - 1]--;
					}
					else
					{
						isNegative = true;
						c[i] += abs(b[LenB] - a[LenA]);
					}
				}
				LenA--;
				LenB--;
			}
			else if (LenA < 0 && LenB >= 0)
			{
				c[i] += b[LenB];
				LenB--;
			}
		}
	}
	bool spareZero = true;
	if (isNegative)
	{
		cout << "-";
	}
	for (int i = mergedSize; i >= 0; i--)
	{
		if (spareZero && c[i] == 0 && i != 0)
		{
			continue;
		}
		else
		{
			spareZero = false;
		}
		cout << c[i];
	}
	cout << endl;
}

void product(int ma[], int mb[], int maxLen, int minLen, int LenA, int LenB, bool isNegative)
{
	int a[200], b[200];
	int c[200];
	for (int i = 0; i < 200; i++)
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	for (int i = 0; i < LenA; i++)
	{
		a[i] = ma[i];
	}
	for (int i = 0; i < LenB; i++)
	{
		b[i] = mb[i];
	}
	int mergedSize = LenA + LenB;
	if (LenA >= LenB)
	{
		LenA--;
		LenB--;
		for (int i = LenB; i >= 0; i--)
		{
			for (int j = LenA; j >= 0; j--)
			{
				c[(LenB - i) + (LenA - j)] += a[j] * b[i];
				if (c[(LenB - i) + (LenA - j)] > 9)
				{
					c[(LenB - i) + (LenA - j) + 1] += c[(LenB - i) + (LenA - j)] / 10;
					c[(LenB - i) + (LenA - j)] %= 10;
				}
			}
		}
	}
	else
	{
		LenA--;
		LenB--;
		for (int i = LenA; i >= 0; i--)
		{
			for (int j = LenB; j >= 0; j--)
			{
				c[(LenA - i) + (LenB - j)] += a[i] * b[j];
				if (c[(LenA - i) + (LenB - j)] > 9)
				{
					c[(LenA - i) + (LenB - j) + 1] += c[(LenA - i) + (LenB - j)] / 10;
					c[(LenA - i) + (LenB - j)] %= 10;
				}
			}
		}
	}
	if (isNegative)
	{
		cout << "-";
	}
	bool spareZero = true;
	for (int i = mergedSize; i >= 0; i--)
	{
		if (spareZero && c[i] == 0 && i != 0)
		{
			continue;
		}
		else
		{
			spareZero = false;
		}
		cout << c[i];
	}
	cout << endl;
}

int main()
{
	int a[200], b[200];
	string bigA, bigB;
	bool isNegativeA = false;
	bool isNegativeB = false;
	while (cin >> bigA >> bigB)
	{
		isNegativeA = false;
		isNegativeB = false;
		if (bigA[0] == '-')
		{
			bigA.erase(0, 1);
			isNegativeA = true;
		}
		if (bigB[0] == '-') 
		{
			bigB.erase(0, 1);
			isNegativeB = true;
		}
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
		if (!isNegativeA && !isNegativeB)
		{
			sum(a, b, maxLen, minLen, LenA, LenB, 0);
			different(a, b, maxLen, minLen, LenA, LenB, 0);
			product(a, b, maxLen, minLen, LenA, LenB, 0);
		}
		else if (!isNegativeA && isNegativeB)
		{
			different(a, b, maxLen, minLen, LenA, LenB, 0);
			sum(a, b, maxLen, minLen, LenA, LenB, 0);
			product(a, b, maxLen, minLen, LenA, LenB, 1);
		}
		else if (isNegativeA && !isNegativeB)
		{
			different(a, b, maxLen, minLen, LenA, LenB, 1);
			sum(b, a, maxLen, minLen, LenB, LenA, 1);
			product(a, b, maxLen, minLen, LenA, LenB, 1);
		}
		else if (isNegativeA && isNegativeB)
		{
			sum(a, b, maxLen, minLen, LenA, LenB, 1);
			different(a, b, maxLen, minLen, LenA, LenB, 1);
			product(a, b, maxLen, minLen, LenA, LenB, 0);
		}
	}
}