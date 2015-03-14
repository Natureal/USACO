/*
ID:naturec1
PROG: fence9
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

int n,m,p;

int Gcd(int a,int b){
	while(a > 0 && b > 0){
		if(a > b) a %= b;
		else b %= a;
	}
	return a + b;
}

int main(){
	freopen("fence9.in","r",stdin);
	freopen("fence9.out","w",stdout);
	//(0,0) -> (n,m) -> (p,0) -> (0,0)
	scanf("%d%d%d",&n,&m,&p);
	int cnt = p;
	int g = Gcd(n,m);
	cnt += g;
	g = Gcd(abs(n - p),m);
	cnt += g;
	printf("%d\n",(p * m - cnt + 2) / 2);
	return 0;
}

