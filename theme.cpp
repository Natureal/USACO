

/*
ID:naturec1
PROG: theme
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
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int N;
int v[5010],dif[5010];
int P[5010];

void Getnext(int len,int st){
	P[0] = -1;
	int j = -1; //当前匹配到的前缀
	for(int i = 1; i < len; ++i){
		while(j >= 0 && dif[st + j + 1] != dif[st + i]) j = P[j];
		if(dif[st + j + 1] == dif[st + i]) j++;
		P[i] = j;
	}
}

int main(){
	freopen("theme.in","r",stdin);
	freopen("theme.out","w",stdout);
	scanf("%d",&N);
	REP(i,N) scanf("%d",v + i);
	REP(i,N - 1) dif[i] = v[i + 1] - v[i];
	N--;
	int ans = 0;
	int l = 0,r = N / 2;
	while(l <= r){
		int len = getmid(l,r);
		int res = 0;
		for(int st = 0; !res && st <= N - 2 * len; ++st){
			Getnext(len,st);
			int j = -1;
 			bool flag = false;
			for(int i = st + len + 1; i < N; ++i){
				while(j >= 0 && dif[st + j + 1] != dif[i]) j = P[j];
				if(dif[st + j + 1] == dif[i]) j++;
				if(j == len - 1){
					flag = true;
					break;
				}
			}
			if(flag) res = len;
		}
		if(!res) r = len - 1;
		else l = len + 1,ans = len;
		//printf("len : %d , l,r : (%d,%d)\n",len,l,r);
	}
	if(ans + 1 < 5) printf("0\n");
	else printf("%d\n",ans + 1);
	return 0;
}



