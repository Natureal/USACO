/*
ID:naturec1
PROG: shopping
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
#define X first
#define Y second

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int s,b;
int dp[6][6][6][6][6];
int val[110],pval[10],num[10];
int id[1010];
int bad[110];
vector<pii > of[110];
int o[110][6];

void Solve(){
	MEM(dp,0x3f);
	dp[0][0][0][0][0] = 0;
	REP(i,s + b){
		for(int p1 = o[i][1]; p1 <= num[1]; ++p1)
		for(int p2 = o[i][2]; p2 <= num[2]; ++p2)
		for(int p3 = o[i][3]; p3 <= num[3]; ++p3)
		for(int p4 = o[i][4]; p4 <= num[4]; ++p4)
		for(int p5 = o[i][5]; p5 <= num[5]; ++p5){
			dp[p1][p2][p3][p4][p5] = min(dp[p1][p2][p3][p4][p5],val[i] + 
			dp[p1-o[i][1]][p2-o[i][2]][p3-o[i][3]][p4-o[i][4]][p5-o[i][5]]);
		}
	}
}

int main(){
	//freopen("shopping.in","r",stdin);
	//freopen("shopping.out","w",stdout);
	int n,c,k,p;
	scanf("%d",&s);
	REP(i,s){
		scanf("%d",&n);
		REP(j,n){
			scanf("%d%d",&c,&k);
			of[i].push_back(MP(c,k));
		}
		scanf("%d",&val[i]);
	}
	scanf("%d",&b);
	REP(i,b){
		scanf("%d%d%d",&c,&k,&p);
		id[c] = i;
		num[i] = k;
		pval[i] = p;
	}
	REP(i,s){
		for(int j = 0; j < of[i].size(); ++j){
			pii tmp = of[i][j];
			o[i][id[tmp.X]] = tmp.Y;
		}
	}
	REP(i,b){
		o[i + s][i] = 1;
		val[i + s] = pval[i];
	}
	Solve();
	printf("%d\n",dp[num[1]][num[2]][num[3]][num[4]][num[5]]);
	return 0;
}

