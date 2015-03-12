/*
ID:naturec1
PROG: spin
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

struct node{
	int now,sp,num;
	pii w[5];
}nd[5];

int emp[370],tem[370];

bool Check(){
	MEM(emp,0);
	for(int i = 0; i < 5; ++i){
		MEM(tem,-1);
		for(int j = 0; j < nd[i].num; ++j){
			pii &cur = nd[i].w[j];
			int top = (cur.X + cur.Y + nd[i].now) % 360;
			for(int k = (cur.X + nd[i].now) % 360; ;){
				tem[k] = 0;
				if(k == top) break;
				if((++k) == 360) k = 0;
			}
		}
		for(int j = 0; j < 360; ++j) if(tem[j] == -1) emp[j] = 1;
	}
	for(int i = 0; i < 360; ++i) if(emp[i] == 0) return true;
	return false;
}

int main(){
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	while(scanf("%d",&nd[0].sp) != EOF){
		scanf("%d",&nd[0].num);
		for(int i = 0; i < nd[0].num; ++i)
			scanf("%d%d",&nd[0].w[i].X,&nd[0].w[i].Y);
		REP(k,4){
			scanf("%d%d",&nd[k].sp,&nd[k].num);
			for(int i = 0; i < nd[k].num; ++i)
				scanf("%d%d",&nd[k].w[i].X,&nd[k].w[i].Y);
		}
		for(int i = 0; i < 5; ++i)
			nd[i].now = 0;
		bool flag = false;
		for(int o = 0; o <= 32400; ++o){
			if(Check()){
				flag = true;
				printf("%d\n",o);
				break;
			}
			for(int i = 0; i < 5; ++i)
				nd[i].now = (nd[i].now + nd[i].sp) % 360;
		}
		if(flag == false) printf("none\n");
	}
	return 0;
}


