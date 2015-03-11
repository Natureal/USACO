
/*
ID:naturec1
PROG: ariprog
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

int N,M;
int exi[125010];
int v[125010],cnt;

bool Check(int b,int st){
	REP(i,N - 1){
		st += b;
		if(st > 125010 || !exi[st]) return false;
	}
	return true;
}

int main(){
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i = 0; i <= M; ++i)
		for(int j = i; j <= M; ++j)
			exi[i * i + j * j] = 1;
	for(int i = 0; i <= 125000; ++i) if(exi[i])
		v[++cnt] = i;
	bool flag = false;
	int top = v[cnt] / (N - 1);
	REP(i,top) REP(j,cnt - N + 1) if(Check(i,v[j])){
		flag = true;
		printf("%d %d\n",v[j],i);
	}
	if(flag == false) printf("NONE\n");
	return 0;
}

