/*
ID:naturec1
PROG: lgame
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
#include <fstream>
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

string s[40000];
int scnt = 0;

void Read(){
	ifstream fin("lgame.dict");
	while(getline(fin,s[scnt++])){
		if(s[scnt - 1][0] == '.')
			break;
	}
	fin.close();
}

int val[200],num[200];
vector<pair<string,int> > g;
string str;

struct node{
	string a,b;
	int val;
	node() {}
	node(string ta,string tb,int tval) :
		a(ta) , b(tb) , val(tval) {}
};

vector<node> ans;

bool cmp(node a,node b){
	return a.a < b.a;
}

int main(){
	Read();
	freopen("lgame.in","r",stdin);
	freopen("lgame.out","w",stdout);
	val['e'] = val['i'] = val['s'] = 1;
	val['r'] = val['t'] = val['a'] = val['n'] = 2;
	val['o'] = val['l'] = 3;
	val['u'] = val['d'] = val['c'] = 4;
	val['y'] = val['p'] = val['g'] = val['h'] = val['b'] = val['m'] = 5;
	val['w'] = val['f'] = val['k'] = val['v'] = 6;
	val['q'] = val['j'] = val['z'] = val['x'] = 7;
	cin >> str;
	for(int i = 0; i < str.size(); ++i)
		num[str[i]]++;
	int cur,len,tnum[200],val_max = 0;
	bool flag;
	for(int i = 0; i < scnt; ++i){
		len = s[i].size();
		MEM(tnum,0);
		flag = true;
		cur = 0;
		for(int j = 0; j < len; ++j){
			tnum[s[i][j]]++;
			cur += val[s[i][j]];
			if(tnum[s[i][j]] > num[s[i][j]]){
				flag = false;
				break;
			}
		}
		if(flag){
			g.push_back(MP(s[i],cur));
			val_max = max(val_max,cur);
		}
	}
	int l1,l2;
	int tnum2[200];
	for(int i = 0; i < g.size(); ++i){
		l1 = g[i].X.size();
		MEM(tnum,0);
		for(int j = 0; j < l1; ++j)
			tnum[g[i].X[j]]++;
		for(int j = i + 1; j < g.size(); ++j){
			memcpy(tnum2,tnum,sizeof(tnum));
			flag = true;
			l2 = g[j].X.size();
			for(int k = 0; k < l2; ++k){
				tnum2[g[j].X[k]]++;
				if(tnum2[g[j].X[k]] > num[g[j].X[k]]){
					flag = false;
					break;
				}
			}
			if(flag){
				ans.push_back(node(g[i].X,g[j].X,g[i].Y + g[j].Y));
				val_max = max(val_max,g[i].Y + g[j].Y);
			}
		}
	}
	printf("%d\n",val_max);
	for(int i = 0; i < g.size(); ++i) if(g[i].Y == val_max)
		ans.push_back(node(g[i].X,"",g[i].Y));
	sort(ans.begin(),ans.end(),cmp);
	for(int i = 0; i < ans.size(); ++i) if(ans[i].val == val_max){
		cout << ans[i].a;
		if(ans[i].b.size()) cout << " " << ans[i].b;
		puts("");
	}
	return 0;
}

