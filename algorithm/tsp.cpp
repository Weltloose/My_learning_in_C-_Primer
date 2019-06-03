#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <bitset>
#include <queue>

using namespace std;

const double MAX = 100000;

double x[21];
double y[21];
int n;
double dp[1100000][21];

inline double dis(int i, int j){
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double go(int b, int stop){
	if(dp[b][stop] != -1) return dp[b][stop];
	if(b == (1 << (n - 1))) return dis(n - 1, stop);
	dp[b][stop] = MAX;
	for(int i = 0; i < n - 1; i++){
		if(b & (1 << i)){
			dp[b][stop] = min(dp[b][stop], go(b & (~(1 << i)), i) + dis(i, stop));
		}
	}
	return dp[b][stop];
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		
		cin >> n;
		for(int i = 0; i < 1100000; i++)
			for(int j = 0; j < 21; j++)
				dp[i][j] = -1;
		for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
		
		int b = 0;
		for(int i = 1; i < n; i++) b = b | (1 << i);
		printf("%.2lf\n", go(b, 0));

	}
}