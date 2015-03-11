
/*
ID:naturec1
PROG: palsquare
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

int B;

bool Check(int v){
	int s[100],tot = 0;
	while(v){
		s[tot++] = v % B;
		v /= B;
	}
	for(int i = 0; i < tot / 2; ++i) if(s[i] != s[tot - i - 1])
		return false;
	return true;
}

void Print(int v){
	int s[100],tot = 0;
	while(v){
		s[tot++] = v % B;
		v /= B;
	}
	for(int i = tot - 1; i >= 0; --i){
		if(s[i] >= 10) printf("%c",'A' + s[i] - 10);
		else printf("%d",s[i]);
	}
}

int main(){
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	scanf("%d",&B);
	REP(i,300){
		int sq = i * i;
		if(Check(sq)){
			Print(i);
			printf(" ");
			Print(sq);
			puts("");
		}
	}
	return 0;
}

