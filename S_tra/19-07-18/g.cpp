#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <string.h>
#include <memory.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

int a[MAXN];
int b[MAXN];

bool f(int l, int r)
{
	for (int i = l; i <= r; i++)
	{
		for (int j = i; j <= r; j++)
		{
			int min1 = a[i], min2 = b[i], in1 = i, in2 = i;
			for (int k = i; k <= j; k++)
			{
				if (a[k] < min1)
				{
					min1 = a[k];
					in1 = k;
				}
				if (b[k] < min2)
				{
					min2 = b[k];
					in2 = k;
				}
			}
			if (in1 != in2) return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
                            for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    printf("\n");
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
    printf("\n");
		int min1 = a[1], min2 = b[1], in1 = 1, in2 = 1, ans = n;
		for (int i = 2; i <= n; i++)
		{
			if (a[i] > a[i - 1] && b[i] > b[i - 1] || a[i] < a[i - 1] && b[i] < b[i - 1])
			{

			}
			else
			{
				ans = i - 1;
				break;
			}

			if (a[i] < min1)
			{
				min1 = a[i];
				in1 = i;
			}
			if (b[i] < min2)
			{
				min2 = b[i];
				in2 = i;
			}
			if (in1 != in2)
			{
				ans = i - 1;
				break;
			}

			if (!f(max(i - 3, 1), i))
			{
				ans = i - 1;
				break;
			}

		}
		printf("%d\n", ans);
	}
	return 0;
}