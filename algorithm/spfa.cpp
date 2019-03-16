#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

const int MAX = 100;

int main(){
	ifstream in("3.txt");
	int graph[10][10];
	bool pre[10];
	memset(pre, 0, sizeof(pre));
	memset(graph, MAX, sizeof(graph));
	int a, b, value, count = 0;
	while(in >> a >> b >> value){
		graph[a][b] = value; 
		count ++ ;
	}
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));
	int d[10];
	memset(d, MAX, sizeof(d));
	d[0] = 0;
	queue<int> q;
	q.push(0);
	pre[0] = 1;
	cnt[0]++;
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		pre[temp] = 0;
		for(int i = 1; i < 10; i++){
			if(d[i] > d[temp] + graph[temp][i]){
				if(!pre[i]){
					q.push(i);	
					cnt[i] ++ ;
					if(cnt[i] > count) return 0;   //negative weight routin
				}
				cout << temp << ' ' << i << endl;	
				d[i] = d[temp] + graph[temp][i];
				pre[i] = 1;
			}
		}	
	}
	cout << endl;
	for(int i = 1; i <= 7; i++)
		cout << d[i] << ' ';

}