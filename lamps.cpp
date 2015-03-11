/*
ID:naturec1
PROG: lamps
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

int N,C;
int st[110];
int CP[110][5];
int p[5];
int cnt;
vector<string> ans;
vector<int> on;
vector<int> off;

void Solve(){
	string now;
	REP(i,N){
		int cur = p[1] ^ 1;
		for(int j = 2; j <= 4; ++j) if(CP[i][j]) cur ^= p[j];
		now += cur + '0';
	}
	ans.push_back(now);
}

void Pre(){
	REP(i,N){
		if(i & 1) CP[i][2] = 1;
		else CP[i][3] = 1;
		if((i - 1) % 3 == 0) CP[i][4] = 1;
	}
}

bool Check(){
	for(int i = 0; i < on.size(); ++i){
		int cur = p[1] ^ 1;
		for(int j = 2; j <= 4; ++j) if(CP[on[i]][j]) cur ^= p[j];
		if(cur == 0) return false;
	}
	for(int i = 0; i < off.size(); ++i){
		int cur = p[1] ^ 1;
		for(int j = 2; j <= 4; ++j) if(CP[off[i]][j]) cur ^= p[j];
		if(cur == 1) return false;
	}
	return true;
}

int main(){
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	scanf("%d",&N);
	Pre();
	scanf("%d",&C);
	int a;
	bool exi = false;
	while(scanf("%d",&a) != EOF && a != -1)	on.push_back(a);
	while(scanf("%d",&a) != EOF && a != -1)	off.push_back(a);
	if(C >= 4){
		for(p[1] = 0; p[1] <= 1; ++p[1])
		for(p[2] = 0; p[2] <= 1; ++p[2])
		for(p[3] = 0; p[3] <= 1; ++p[3])
		for(p[4] = 0; p[4] <= 1; ++p[4]){
			if((p[1] ^ p[2] ^ p[3] ^ p[4]) != (C & 1)) continue;
			if(Check()){
				exi = true;
				Solve();
			}
		}
	}
	else{
		FOR(k1,0,C) FOR(k2,0,C) FOR(k3,0,C) FOR(k4,0,C){
			if(k1 + k2 + k3 + k4 == C){
				p[1] = k1 & 1,p[2] = k2 & 1,p[3] = k3 & 1,p[4] = k4 & 1;
				if(Check()){
					exi = true;
					Solve();
				}
			}
		}
	}
	if(!exi) printf("IMPOSSIBLE\n");
	sort(ans.begin(),ans.end());
	for(int i = 0; i < ans.size(); ++i){
		if(i == 0 || ans[i] != ans[i - 1])
			cout << ans[i] << endl;
	}
	return 0;
}

