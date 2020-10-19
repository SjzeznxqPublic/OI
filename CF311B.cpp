#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
// TODO:...

const int N = 100010;
long long n, m, p;
long long d[N];
long long q[N + 10];
long long a[N], f[110][N], sum[N];

int main()
{
#ifndef ONLINE_JUDGE
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
	freopen("testdata.out", "w", stdout);
#endif
#ifndef DEBUG
	freopen("CF311B.in", "r", stdin);
	freopen("CF311B.out", "w", stdout);
#endif
#endif
	scanf("%lld%lld%lld", &n, &m, &p);
	for (int i = 2; i <= n; ++i)
	{
		scanf("%lld", &d[i]);
		d[i] = d[i - 1] + d[i];
	}
	long long t = 0, h = 0;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%lld%lld", &h, &t);
		a[i] = t - d[h];
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; ++i)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		f[0][i] = 0x3f3f3f3f3f3f3f3f;
	}
	f[0][0] = 0;
	for (int i = 1; i <= p; ++i)
	{
		int l = 1, r = 1;
		q[r] = 0;
		for (int j = 1; j <= m; ++j)
		{
			while (l < r && (f[i - 1][q[l + 1]] + sum[q[l + 1]] - f[i - 1][q[l]] - sum[q[l]]) < a[j] * (q[l + 1] - q[l]))
				++l;
			f[i][j] = min(f[i - 1][j], f[i - 1][q[l]] + a[j] * (j - q[l]) - (sum[j] - sum[q[l]]));
			while (l < r && (f[i - 1][j] + sum[j] - f[i - 1][q[r]] - sum[q[r]]) * (q[r] - q[r - 1]) <=
								(f[i - 1][q[r]] + sum[q[r]] - f[i - 1][q[r - 1]] + sum[q[r - 1]]) * (j - q[r]))
				--r;
			q[++r] = j;
		}
	}
	printf("%lld", f[p][m]);
	return 0;
}