/*
ID:naturec1
PROG: pprime
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
#include <ctime>
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

int A,B,Len;
int s[15];
int ten[15];

bool Prime(ll v){
	if(!((v % 10) & 1)) return false;
	for(ll i = 2; i * i <= v; ++i)
		if(v % i == 0)
            return false;
	return true;
}

bool Judge(ll t){
	if(!Prime(t) || t < A || t > B) return false;
	return true;
}

void Dfs(int p,ll v){
	if(p > (Len + 1) / 2){
		if(Judge(v)) printf("%lld\n",v);
		return;
	}
	int st = (p == 1) ? 1 : 0;
	if((Len & 1) && p == (Len + 1) / 2)
		for(int i = st; i <= 9; ++i)
			Dfs(p + 1,v + i * ten[p - 1]);
	else
		for(int i = st; i <= 9; ++i)
			Dfs(p + 1,v + i * (ten[p - 1] + ten[Len - p]));
}

int main(){
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	ten[0] = 1;
	clock_t st,ed;
	for(int i = 1; i <= 9; ++i) ten[i] = ten[i - 1] * 10;
	scanf("%d%d",&A,&B);
	int len1 = 0,len2 = 0,b = 1;
	for(int i = 1; i <= 10; ++i){
		if(A / b) len1++;
		if(B / b) len2++;
		b *= 10;
	}
	if(len2 == 9) len2--;
	//st = clock();
	for(int i = len1; i <= len2; ++i) if((i & 1) || i == 2){
		if(i == 2 && 11 >= A && 11 <= B){
			printf("11\n");
			continue;
		}
		Len = i;
		Dfs(1,0);
	}
	//ed = clock();
	//printf("time : %.5f\n",(double)(ed - st) / CLOCKS_PER_SEC);
	return 0;
}


