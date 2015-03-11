/*
ID:naturec1
PROG: runround
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
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int M;
int vis[20];

bool Check(ull v){
	string s,s2;
	while(v){
		s += v % 10 + '0';
		v /= 10ULL;
	}
	for(int i = 0; i < s.size(); ++i) if(s[i] == '0') return false;
	for(int i = 0; i < s.size() / 2; ++i) swap(s[i],s[s.size() - i - 1]);
	s2 = s;
	REP(i,6) s2 += s2;
	int p = 0;
	MEM(vis,0);
	vis[s2[p] - '0'] = 1;
	for(int i = 0; i < s.size(); ++i){
		p += s2[p] - '0';
		if((i < s.size() - 1 && vis[s2[p] - '0']) ||
				(i == s.size() - 1 && s2[p] != s2[0]))
			return false;
		vis[s2[p] - '0'] = 1;
	}
	return true;
}

int main(){
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	scanf("%d",&M);
	for(ull i = M + 1; ; ++i){
		if(Check(i)){
			printf("%llu\n",i);
			break;
		}
	}
	return 0;
}

