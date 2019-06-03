#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
	int graph[10][10];
	memset(graph, 0, sizeof(graph));
	ifstream in("4.txt");
	int a, b;
	set<int> s;
	while(in >> a >> b){
		graph[a][b] = 1;
		s.insert(a);
		s.insert(b);
	}
	stack<int> store;
	for(auto i : s) store.push(i);
	int temp1 = store.top();
	store.pop();
	while(!store.empty()){ 
		int temp2 = store.top();
		store.pop();
		if(graph[temp1][temp2]) temp1 = temp2;
	}
	int ok = 1;
	for(auto i : s){
		if(i != temp1 && (!graph[i][temp1] || graph[temp1][i])){
			ok = 0;
		}
	}
	cout << (ok ? temp1 : 0) << endl;
		
}