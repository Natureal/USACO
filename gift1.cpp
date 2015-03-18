/*
ID:naturec1
PROG: gift1
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

map<string,int> mp;
int n,cnt[15][2];
string s[15],s1,s2;

int main(){
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	int a,b;
	scanf("%d",&n);
	REP(i,n){
		cin >> s[i];
		mp[s[i]] = i;
	}
	REP(i,n){
		cin >> s1;
		int id1 = mp[s1];
		scanf("%d%d",&a,&b);
		REP(j,b){
			cin >> s2;
			int id2 = mp[s2];
			if(a) cnt[id2][1] += a / b,cnt[id1][0] += a / b;
		}
	}
	REP(i,n){
		cout << s[i] << ' ';
		printf("%d\n",cnt[i][1] - cnt[i][0]);
	}
	return 0;
}
		
		

