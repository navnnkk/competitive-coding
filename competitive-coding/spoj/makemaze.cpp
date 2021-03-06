/*
 *  Author		: Krypten
 *  Algorithm	: BFS
 */

#include <iostream>
#include <queue>
#include <vector>
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
// Logic
#define SIZE 4

int moves[SIZE][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char matrix[32][32];
bool visited[32][32];

typedef struct {
	int x;
	int y;
} node;

int n, m;

bool legalMove(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m) {
		return true;
	}
	return false;
}

bool bfs(node s, node d)
{
	node v;
	queue<node> q;
	M(visited, false);
	q.push(s);
	while (!q.empty()) {
		node u = q.front(); q.pop();
		//cout << u.x << " " << u.y << " " << u.cost << "\n";
		if (u.x == d.x && u.y == d.y) {
			return true;
		}
		if (visited[u.x][u.y])
			continue;
		visited[u.x][u.y] = true;

		//cout << u.x << " " << u.y << " " << u.cost << "\n";
		F(i,0,SIZE) {
			int X = u.x + moves[i][0];
			int Y = u.y + moves[i][1];

			if (legalMove(X, Y) && !visited[X][Y] && matrix[X][Y] == '.') {
				v.x = X; v.y = Y;
				//cout << "Pushing : " << v.x << " " << v.y << " " << v.cost << "\n";
				q.push(v);
			}
		}
		//cout << u.x << " " << u.y << " " << u.cost << " " << pq.size() << "\n";
	}
	return false;
}

int main()
{
	input();
	int t;
	node arr[2];
	S(t);
	//t = 1;
	while (t--) {
		S(n), S(m);
		F(i, 0, n)
			F(j , 0, m) {
				scanf(" %c", &matrix[i][j]);
			}
		int cnt = 0;
		bool flag = true;

		//cout<< n << " " << m << "\n";
		if (n == 1 && m == 1)
			flag = false;
		else if (n > 1 || m > 1) {
			F(i,0,n) {
				//cout << cnt << " " << matrix[i][m-1] << "\n\t";
				if (matrix[i][0] == '.') {
					if (cnt < 2) {
						arr[cnt].x= i;
						arr[cnt].y= 0;
					}
					++cnt;
				}
				if (m-1 > 0 && matrix[i][m-1] == '.') {
					if (cnt < 2) {
						arr[cnt].x= i;
						arr[cnt].y=m-1;
					}
					++cnt;
				}
			}
			F(j,1,m-1) {
				if (matrix[0][j] == '.') {
					if (cnt < 2) {
						arr[cnt].x= 0;
						arr[cnt].y= j;
					}
					++cnt;
				}
				if (n-1 > 0 && matrix[n-1][j] == '.') {
					if (cnt < 2) {
						arr[cnt].x= n-1;
						arr[cnt].y= j;
					}
					++cnt;
				}
			}
			//cout << "count : " << cnt << "\n";
			if (cnt != 2)
				flag = false;
			else if (flag) {
				flag = bfs(arr[0], arr[1]);
			}
		}
		if (flag)
			Ps("valid\n");
		else
			Ps("invalid\n");
	}
	return 0;
}
