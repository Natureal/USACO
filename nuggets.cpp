/*
ID:naturec1
PROG: nuggets
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
int num[100];
int cnt;
bool dp[66010];

int Gcd(int a,int b){
	while(a > 0 && b > 0){
		if(a > b) a %= b;
		else b %= a;
	}
	return a + b;
}

int main(){
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout);
	scanf("%d",&N);
	int g;
	REP(i,N){
		scanf("%d",num + i);
		if(i == 1) g = num[i];
		else g = Gcd(g,num[i]);
	}
	if(g != 1){
		printf("0\n");
		return 0;
	}
	dp[0] = true;
	REP(i,N){
		for(int j = num[i]; j < 66000; ++j){
			dp[j] |= dp[j - num[i]];
		}
	}
	bool flag = false;
	for(int i = 66000 - 1; i > 0; --i){
		if(dp[i] == false){
			flag = true;
			printf("%d\n",i);
			break;
		}
	}
	if(flag == false) printf("0\n");
	return 0;
}

