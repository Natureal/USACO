
/*
ID:naturec1
PROG: beads
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
int l[400],r[400];
char s[400];

int Left(int x){
	int len = 1;
	char c = s[x];
	for(int i = (x == 1 ? n : x - 1); i != x; i = (i == 1) ? n : i - 1){
		if(s[i] == 'w' || s[i] == c) ++len;
		else break;
	}
	return len;
}

int Right(int x){
	int len = 1;
	char c = s[x];
	for(int i = (x == n ? 1 : x + 1); i != x; i = (i == n) ? 1 : i + 1){
		if(s[i] == 'w' || s[i] == c) ++len;
		else break;
	}
	return len;
}

int main(){
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s + 1);
	REP(i,n){
		if(s[i] == 'w'){
			s[i] = 'r';
			l[i] = Left(i);
			r[i] = Right(i);
			s[i] = 'b';
			l[i] = max(l[i],Left(i));
			r[i] = max(r[i],Right(i));
			s[i] = 'w';
		}
		else l[i] = Left(i),r[i] = Right(i);
	}
	int ans = r[1] + l[n];
	REP(i,n){
		ans = max(ans,r[i] + l[i - 1]);
	}
	ans = min(ans,n);
	printf("%d\n",ans);
	return 0;
}


