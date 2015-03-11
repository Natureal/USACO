/*
ID:naturec1
PROG: sprime
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

int n;

bool Prime(int v){
	if(v == 1) return false;
	for(int i = 2; i * i <= v; ++i)
		if(v % i == 0) return false;
	return true;
}

void Dfs(int p,int v){
	if(p > n){
		printf("%d\n",v);
		return;
	}
	int tmp = v * 10 + 1;
	if(Prime(tmp)) Dfs(p + 1,tmp);
	tmp = v * 10 + 2;
	if(Prime(tmp)) Dfs(p + 1,tmp);
	for(int i = 3; i <= 9; i += 2){
		tmp = v * 10 + i;
		if(Prime(tmp)) Dfs(p + 1,tmp);
	}
}

int main(){
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	scanf("%d",&n);
	Dfs(1,0);
	return 0;
}

