/*
ID:naturec1
PROG: sort3
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

int n;
int v[1010];
int cnt[5];

int main(){
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	scanf("%d",&n);
	REP(i,n){
		scanf("%d",v + i);
		cnt[v[i]]++;
	}
	int ans = 0;
	REP(i,cnt[1]) if(v[i] != 1){
		if(v[i] == 2){
			for(int j = cnt[1] + 1; j <= n; ++j) if(v[j] == 1){
				swap(v[i],v[j]);
				break;
			}
		}
		else{
			for(int j = n; j > cnt[1]; --j) if(v[j] == 1){
				swap(v[i],v[j]);
				break;
			}
		}
		++ans;
	}
	FOR(i,cnt[1] + 1,cnt[1] + cnt[2]) if(v[i] == 3){
		for(int j = cnt[1] + cnt[2] + 1; j <= n; ++j) if(v[j] == 2){
			swap(v[i],v[j]);
			break;
		}
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}

