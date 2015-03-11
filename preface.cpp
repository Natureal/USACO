/*
ID:naturec1
PROG: preface
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
int arr1[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
string arr2[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

string Trans(int v){
	string s;
	int i = 0;
	while(v){
		if(v >= arr1[i]){
			v -= arr1[i];
			s += arr2[i];
		}
		else ++i;
	}
	return s;
}

int main(){
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	int Ch[10] = {'I','V','X','L','C','D','M'};
	int cnt[200] = {0};
	scanf("%d",&N);
	REP(i,N){
		string res = Trans(i);
		for(int i = 0; i < res.size(); ++i) cnt[res[i]]++;
	}
	for(int i = 0; i < 7; ++i)
		if(cnt[Ch[i]]) printf("%c %d\n",Ch[i],cnt[Ch[i]]);	
	return 0;
}	

