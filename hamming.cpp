/*
ID:naturec1
PROG: hamming
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
const int RA = 18;

int N,B,D;
int s[100];
int ans[100][100],cnt;

bool Judge(int id){
	int res = 0;
	for(int i = 1; i <= RA; ++i) if(ans[id][i] != s[i]) ++res;
	if(res < D) return false;
	return true;
}

bool Check(){
	REP(i,cnt){
		if(!Judge(i))
			return false;
	}
	return true;
}

void Dfs(int p){
	if(p > RA){
		if(Check()){
			++cnt;
			REP(i,RA) ans[cnt][i] = s[i];
		}
		return;
	}
	Dfs(p + 1);
	if(cnt >= N) return;
	s[p] = 1;
	Dfs(p + 1);
	s[p] = 0;
}

void Print(int id){
	ll t = 0;
	for(int i = 1; i <= RA; ++i) if(ans[id][i]) t |= (1 << (RA - i));
	printf("%lld",t);
}

int main(){
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	scanf("%d%d%d",&N,&B,&D);
	Dfs(1);
	//REP(i,cnt){
	//	REP(j,10) printf("%d",ans[i][j]);
	//	puts("");
	//}
	REP(i,N){
		Print(i);
		if(i == N || i % 10 == 0) puts("");
		else printf(" ");
	}
	return 0;
}

