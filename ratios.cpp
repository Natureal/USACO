/*
ID:naturec1
PROG: ratios
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

int x,y,z;
int X[3],Y[3],Z[3];

int main(){
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	scanf("%d%d%d",&x,&y,&z);
	for(int i = 0; i < 3; ++i)
		scanf("%d%d%d",X + i,Y + i,Z + i);
	bool flag = false;
	for(int a = 0; a <= 100; ++a){
		for(int b = 0; b <= 100; ++b){
			for(int c = 0; c <+ 100; ++c){
				int k1 = a * X[0] + b * X[1] + c * X[2];
				int k2 = a * Y[0] + b * Y[1] + c * Y[2];
				int k3 = a * Z[0] + b * Z[1] + c * Z[2];
				if(k1 < x || k2 < y || k3 < z) continue;
				if((k1&&!x)||(!k1&&x)||(k2&&!y)||(!k2&&y)||(k3&&!z)||(!k3&&z))
					continue;
				if(k1 * y == k2 * x && k1 * z == k3 * x){
					printf("%d %d %d %d\n",a,b,c,k1 / x);
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) break;
	}
	if(flag == false) printf("NONE\n");
	return 0;
}

