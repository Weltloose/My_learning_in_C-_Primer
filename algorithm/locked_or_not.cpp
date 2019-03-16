#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <stack>
#include <set>

using namespace std;

int graph[100][100];

int main(){
	set<int> points;
	memset(graph, 0, sizeof(graph));
	int a, b;
	bool check = 0;
	ifstream in("2.txt");
	while(in >> a >> b){
		graph[a][b] = 1;
		points.insert(a);
		points.insert(b);		
	}
	while(points.size()){
		stack<int> s;
		s.push(*points.begin());
		while(!s.empty()){
			int temp = s.top();
			bool ok_to_pop = 1;
			for(int i = 0; i < 100; i++){
				if(graph[temp][i]){
					ok_to_pop = 0;
					s.push(i);
					//cout << i << ' '; 
					graph[temp][i] = 0;
					break;
				}
			}
			if(ok_to_pop){
				s.pop();
				// visited[temp] = 0;
				cout << temp << ' ';
				auto i = points.find(temp);
				if(i == points.end()){
					check = 1;
					break;
				}
				else points.erase(i);
			}
		}
	}
	cout << (check ? "locked" : "unlock") << endl;
}