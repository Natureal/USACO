/*
ID:naturec1
PROG: humble
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
const ll RA = 1LL << 32;

int K,N;
int prime[105];
set<ll> st;

int main(){
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	scanf("%d%d",&K,&N);
	REP(i,K) scanf("%d",prime + i),st.insert(prime[i]);
	set<ll>::iterator it;
	REP(i,K){
		it = st.begin();
		for(;;){
			ll tmp = (*it) * prime[i];
			if(tmp > RA) break;
			st.insert(tmp);
			if(st.size() > N){
				st.erase(--st.end());
				if(tmp >= *(--st.end())) break;
			}
			it++;
		}
	}
	it = --st.end();
	printf("%lld\n",(*it));
	return 0;
}

