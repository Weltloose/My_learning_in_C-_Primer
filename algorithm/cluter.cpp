#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAX 1e20

struct points{
	int x, y;
};

class line{
public:
	int p1, p2;
	double weight;
	line(int f = 0, int t = 0, double w = 0): p1(f), p2(t), weight(w){}
};

int find(int x, int *p)
{
	return (p[x] == -1) ? x : find(p[x], p);
}

int main(){
	int n, k, ret[101];
	while(cin >> n >> k){
		memset(ret, -1, sizeof(ret));
		points p[101];
		for(int i = 0; i < n; i++){
			int a, b;
			cin >> a >> b;
			p[i].x = a;
			p[i].y = b;
		}
		vector<line> v;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				v.push_back(line(i, j, sqrt((double)((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y)))));
		make_heap(v.begin(), v.end(), [](const line &l1, const line &l2){return l1.weight > l2.weight;});
		int cnt = 0;
		while(cnt < n - k + 1){
			line temp = v[0];
			//cout << temp.weight << endl;
			pop_heap(v.begin(), v.end(), [](const line &l1, const line &l2){return l1.weight > l2.weight;});
			v.pop_back();
			int	n1 = find(temp.p1, ret);
			int	n2 = find(temp.p2, ret);
			if(n1 != n2){
				cnt ++ ;
				if(n1 < n2){
					ret[n2] = n1;
					ret[temp.p2] = n1;
				}
				else{
					ret[n1] = n2;
					ret[temp.p1] = n2;
				}
			}
			else
				continue;
		}
		int temp = int(v[0].weight * 100 + 0.5);
		printf("%.2f\n", temp / 100.0);
		//cout << temp / 100.0  << endl;
	}
}
