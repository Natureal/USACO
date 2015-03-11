/*
ID:naturec1
PROG: prefix
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

vector<string> word;
string s;

bool Check(int id,int pos){
	for(int i = 0; i < word[id].size(); ++i)
		if(word[id][i] != s[pos + i]) return false;
	return true;
}

int main(){
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	string a;
	ios::sync_with_stdio(false);
	while(cin >> a && a[0] != '.')
		word.push_back(a);
	while(cin >> a) s += a;
	int ans = -1;
	for(int i = 0; i < s.size(); ++i){
		for(int j = 0; j < word.size(); ++j){
			if(i + word[j].size() - 1 >= s.size()) continue;
			if(Check(j,i)) ans = max(ans,(int)(i + word[j].size() - 1));
		}
		if(i > ans) break;
	} 
	cout << ans + 1 << endl;
	return 0;
}

