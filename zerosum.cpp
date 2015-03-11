/*
ID:naturec1
PROG: zerosum
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
int op[15];
vector<vector<int> > ans;

bool Judge(){
	int sum = 0;
	int t = 1,pre = 1;
	for(int i = 2; i <= N; ++i){
		if(op[i] == 0) t = t * 10 + i;
		else{
			if(pre == 1) sum += t;
			else  sum -= t;
			t = i;
			pre = op[i];
		}
	}
	if(pre == 1) sum += t;
	else sum -= t;
	return sum == 0;
}

void Dfs(int p){
	if(p > N){
		if(Judge()){
			vector<int> t;
			for(int i = 2; i <= N; ++i) t.push_back(op[i]);
			ans.push_back(t);
		}
		return;
	}
	for(int i = 0; i < 3; ++i){
		op[p] = i;
		Dfs(p + 1);
	}
}

int main(){
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	scanf("%d",&N);
	Dfs(2);
	for(int i = 0; i < ans.size(); ++i){
		printf("1");
		for(int j = 2; j <= N; ++j){
			if(ans[i][j - 2] == 0) printf(" ");
			else if(ans[i][j - 2] == 1) printf("+");
			else printf("-");
			printf("%d",j);
		}
		puts("");
	}
	return 0;
}

