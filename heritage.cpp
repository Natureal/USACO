/*
ID:naturec1
PROG: heritage
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

char in[30],pre[30],post[30];
int L;
int pos[30];

void Dfs(int in1,int in2,int pre1,int pre2){
	if(in1 > in2) return;
	int nxt_pos = pos[pre[pre1] - 'A'];
	Dfs(in1,nxt_pos - 1,pre1 + 1,pre1 + nxt_pos - in1);
	Dfs(nxt_pos + 1,in2,pre1 + nxt_pos - in1 + 1,pre2);
	printf("%c",pre[pre1]);
}

int main(){
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	scanf("%s%s",in + 1,pre + 1);
	int L = strlen(in + 1);
	REP(i,L) pos[in[i] - 'A'] = i;
	Dfs(1,L,1,L);
	puts("");
	return 0;
}


