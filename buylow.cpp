/*
ID:naturec1
PROG: buylow
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)
#define X first
#define Y second

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 5010;

int N;
int P[MAXN],tP[MAXN];
int cnt[MAXN];

struct BIT{
	int c[MAXN],cnt[MAXN];
	void clear(){
		MEM(c,0);
		MEM(cnt,0);
	}
	int lowbit(int x){
		return x & (-x);
	}
	void update(int x,pii d){
		while(x <= N){
			if(c[x] == d.X){
				cnt[x] += d.Y;
			}
			else if(c[x] < d.X){
				c[x] = d.X;
				cnt[x] = d.Y;
			}
			x += lowbit(x);
		}
	}
	pii getmax(int x){
		pii res(0,0);
		while(x){
			if(c[x] == res.X){
				res.Y += cnt[x];
			}
			else if(c[x] > res.X){
				res.X = c[x];
				res.Y = cnt[x];
			}
			x -= lowbit(x);
		}
		return res;
	}
}bt;

int main(){
	//freopen("buylow.in","r",stdin);
	//freopen("buylow.out","w",stdout);
	scanf("%d",&N);
	REP(i,N) scanf("%d",P + i),tP[i] = P[i];
	sort(tP + 1,tP + N + 1);
	int sz = unique(tP + 1,tP + N + 1) - tP;
	REP(i,N) P[i] = lower_bound(tP + 1,tP + sz + 1,P[i]) - tP;
	int ans = 0;
	bt.clear();
	REV(i,N){ //倒序
		pii tmp = bt.getmax(P[i] - 1);
		printf("i(%d) : %d %d\n",i,tmp.X,tmp.Y);
		tmp.X++;
		if(tmp.X == 1) tmp.Y = 1;
		if(tmp.X == ans) cnt[P[i]] = max(cnt[P[i]],tmp.Y);
		else if(tmp.X > ans) ans = tmp.X,cnt = tmp.Y;
		bt.update(P[i],tmp);
	}
	printf("%d %d\n",ans,cnt);
	return 0;
}

