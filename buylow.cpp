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

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 5010;
const int maxn = 100;

struct bign{
	vector<int> s;
	bign(){
		s.clear();
	}
	bign operator = (int val){
		s.clear();
		while(val){
			s.push_back(val % 10);
			val /= 10;
		}
		return *this;
	}
	bign operator = (bign B){
		s = B.s;
		return *this;
	}
	bign operator + (bign B){
		bign res;
		int c = 0,top = max(s.size(),B.s.size()),v1,v2;
		for(int i = 0; i < top; ++i){
			v1 = i < s.size() ? s[i] : 0;
			v2 = i < B.s.size() ? B.s[i] : 0;
			res.s.push_back((v1 + v2 + c) % 10);
			c = (v1 + v2 + c) / 10;
		}
		if(c) res.s.push_back(c);
		return res;
	}
	void print(){
		for(int i = s.size() - 1; i >= 0; --i)
			printf("%d",s[i]);
	}
};

int N;
int v[MAXN],tv[MAXN];
int dp[MAXN];
int vis[MAXN];

bign cnt[MAXN];

int main(){
	freopen("buylow.in","r",stdin);
	freopen("buylow.out","w",stdout);
	scanf("%d",&N);
	REP(i,N) scanf("%d",v + i),tv[i] = v[i];
	sort(tv + 1,tv + N + 1);
	int sz = unique(tv + 1,tv + N + 1) - tv;
	REP(i,N) v[i] = lower_bound(tv + 1,tv + sz + 1,v[i]) - tv;
	int ans = 0;
	REP(i,N){
		MEM(vis,0);
		dp[i] = 1;
		cnt[i] = 1;
		vis[v[i]] = 1;
		for(int j = i - 1; j >= 1; --j) if(v[j] > v[i]){
			if(dp[j] + 1 > dp[i]){
				dp[i] = dp[j] + 1;
				cnt[i] = cnt[j];
			}
			else if(dp[j] + 1 == dp[i]){
				if(!vis[v[j]]){
					cnt[i] = cnt[i] + cnt[j];
				}
			}
			vis[v[j]] = 1;
		}
		if(dp[i] > ans) ans = dp[i];
	}
	printf("%d ",ans);
	MEM(vis,0);
	bign anscnt;
	anscnt = 0;
	for(int i = N; i >= 1; --i) if(!vis[v[i]] && dp[i] == ans){
		vis[v[i]] = 1;
		anscnt = anscnt + cnt[i];
	}
	anscnt.print();
	puts("");
	return 0;
}

