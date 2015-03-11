
/*
ID:naturec1
PROG: transform
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

int N;
char g1[15][15],g2[15][15],tmp[15][15];

bool Check(){
	REP(i,N) REP(j,N) if(g1[i][j] != g2[i][j]) return false;
	return true;
}

void Rotate(){
	REP(i,N) REP(j,N) tmp[j][N - i + 1] = g1[i][j];
}

void Reflec(){
	REP(i,N) REP(j,N) tmp[i][N - j + 1] = g1[i][j];
}

int main(){
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	scanf("%d",&N);
	REP(i,N) scanf("%s",g1[i] + 1);
	REP(i,N) scanf("%s",g2[i] + 1);
	REP(i,4){
		Rotate();
		memcpy(g1,tmp,sizeof(tmp));
		if(i < 4 && Check()){
			printf("%d\n",i);
			return 0;
		}
	}
	Reflec();
	memcpy(g1,tmp,sizeof(tmp));
	if(Check()){
		printf("4\n");
		return 0;
	}
	REP(i,4){
		Rotate();
		memcpy(g1,tmp,sizeof(tmp));
		if(i < 4 && Check()){
			printf("5\n");
			return 0;
		}
	}
	Reflec();
	memcpy(g1,tmp,sizeof(tmp));
	if(Check()) printf("6\n");
	else printf("7\n");
	return 0;
}

