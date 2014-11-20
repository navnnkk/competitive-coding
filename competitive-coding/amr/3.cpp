/*
 *  Author		: Krypten
 *  Algorithm	: Adhoc
 */

#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define INF INT_MAX/2
#define ONLINE_JUDGE 1

#define ull 		unsigned long long
#define ill 		long long int
#define pii 		pair<int,int>
#define pb(x) 		push_back(x)
#define mp make_pair
#define F(i,a,n) 	for(int i=(a);i<(n);++i)
#define FI(i,a,n) 	for(i=(a);i<(n);++i)
#define FD(i,a,n) 	for(int i=(a);i>=(n);--i)
#define FE(it,x) 	for(it=x.begin();it!=x.end();++it)
#define V(x) 		vector<x>
#define S(x) 		scanf("%d",&x)
#define Sl(x) 		scanf("%lld",&x)
#define Ss(x)		scanf("%s", x)
#define P(x) 		printf("%d",x)
#define Pl(x) 		printf("%lld",x)
#define Ps(x)		printf("%s", x)
#define M(x,i) 		memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) 	((a)>(b)?(a):(b))
#define MIN(a,b) 	((a)>(b)?(b):(a))
#define LSOne(S) 	(S & (-S))

ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

void input() {
#if !ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}
int n;
char s[20020];
int dp[20020][512];

int solve(int m)
{
	dp[0][(s[0]-'0')%m]++;
	for (int i = 1; i < n; i++) {
		dp[i][(s[i]-'0')%m]++;
		for (int j = 0; j < m; j++) {
			dp[i][(j*10 + s[i]-'0')%m] += dp[i-1][j];
		}	
	}
}

int main()
{
	input();
	int t;
	int m;
	int mod, rem;
	//S(t);
	//t = 1;
	//while (t--) {
		Ss(s);
		n = strlen(s);
		S(t);
		F(i,0,t) {
			M(dp, 0);
			S(m),S(rem);
			solve(m);
			int ans = 0;
			F(i,0,n)
				ans += dp[i][rem];
			P(ans), Ps("\n");
		}
	//}
	return 0;
}
