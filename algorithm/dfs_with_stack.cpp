#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

int graph[100][100];

int main(){
	memset(graph, 0, sizeof(graph));
	int a, b;
	ifstream in("1.txt");
	while(in >> a >> b){
		graph[a][b] = graph[b][a] = 1;
	}
	int visited[100];
	memset(visited, 0, sizeof(visited));
	stack<int> s;
	s.push(1);
	visited[1] = 1;
	cout << 1 << ' ';
	while(!s.empty()){
		int temp = s.top();
		bool ok_to_pop = 1;
		for(int i = 0; i < 100; i++){
			if(!visited[i] && graph[i][temp]){
				ok_to_pop = 0;
				s.push(i);
				cout << i << ' '; 
				visited[i] = 1;
				break;
			}
		}
		if(ok_to_pop){
			s.pop();
			// visited[temp] = 0;
		}
	}
}