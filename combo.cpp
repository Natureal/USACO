/*
ID:calvinl2
LANG:C++
TASK:combo
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
int a[3],b[3];

int main(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	scanf("%d",&N);
	for(int i = 0; i < 3; ++i) scanf("%d",a + i);
	for(int i = 0; i < 3; ++i) scanf("%d",b + i);
	int ans = 0;
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= N; ++j){
			for(int k = 1; k <= N; ++k){
				if((abs(i-a[0])<3 || abs(i-N-a[0])<3 || abs(i+N-a[0])<3)
				&& (abs(j-a[1])<3 || abs(j-N-a[1])<3 || abs(j+N-a[1])<3)
				&& (abs(k-a[2])<3 || abs(k-N-a[2])<3 || abs(k+N-a[2])<3))
					++ans;
				else if((abs(i-b[0])<3 || abs(i-N-b[0])<3 || abs(i+N-b[0])<3)
				&& (abs(j-b[1])<3 || abs(j-N-b[1])<3 || abs(j+N-b[1])<3)
				&& (abs(k-b[2])<3 || abs(k-N-b[2])<3 || abs(k+N-b[2])<3))
					++ans;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

