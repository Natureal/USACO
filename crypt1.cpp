/*
ID:naturec1
PROG: crypt1
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

int n,ans;
int v[15];
int hash[15];

bool Check(int num){
	while(num){
		if(hash[num % 10] == 0) return false;
		num /= 10;
	}
	return true;
}

int main(){
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	scanf("%d",&n);
	REP(i,n) scanf("%d",&v[i]),hash[v[i]] = 1;
	for(int p1 = 1; p1 <= n; ++p1){
		for(int p2 = 1; p2 <= n; ++p2){
			for(int p3 = 1; p3 <= n; ++p3){
				for(int p4 = 1; p4 <= n; ++p4){
					for(int p5 = 1; p5 <= n; ++p5){
						int v1 = v[p1] * 100 + v[p2] * 10 + v[p3];
						int v2 = v[p4] * 10 + v[p5];
						int v3 = v1 * v[p5];
						if(v3 / 1000) continue;
						int v4 = v1 * v[p4];
						if(v4 / 1000) continue;
						int v5 = v3 * 10 + v4;
						if(v5 / 10000) continue;
						if(Check(v3) && Check(v4) && Check(v5)){
							++ans;
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}


