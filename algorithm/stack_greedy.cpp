#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 30;

class classes{
public:
	int start, end;
	int order;
	classes() = default;
	classes(int n, int a, int b): start(a), end(b), order(n){}
	void print(){cout << order << ' ';}
};

class room{
public:
	int last_time;
	int room_num;
	vector<int> vds;
	room() = default;
	room(int r, int n = 0): last_time(n), room_num(r){}
	room(const room &) = default;
	void print(){
		cout << "Room: " << room_num << endl;
		for(auto i : vds) cout << i << ' ';
		cout << endl;
	}
};

int main(){
	int d = 0;
	vector<room> vs;   //store room info
	vector<classes> v;  //store class info
	int starts[] = {0, 0, 0, 4, 4, 8, 8, 10, 12, 12};
	int ends[] = {3, 7, 3, 7, 10, 11, 11, 15, 15, 15};
	for(int i = 0; i < 10; i++)
		v.push_back(classes(i, starts[i], ends[i]));
	sort(v.begin(), v.end(), [](classes a, classes b){return a.start < b.start;});
	vs.push_back(room(0));
	for(int i = 0; i < 10; i++){
		room temp(vs[0]);
		if(temp.last_time <= v[i].start){
			pop_heap(vs.begin(), vs.end(), [](room a, room b){return a.last_time > b.last_time;});
			vs.pop_back();
			temp.last_time = v[i].end;
			temp.vds.push_back(v[i].order);
			vs.push_back(temp);
			push_heap(vs.begin(), vs.end(), [](room a, room b){return a.last_time > b.last_time;});
		}
		else{
			room t(++d, v[i].end);
			t.vds.push_back(v[i].order);
			vs.push_back(t);
			push_heap(vs.begin(), vs.end(), [](room a, room b){return a.last_time > b.last_time;});
		}
	}
	cout << d << endl;
	for(auto i : vs) i.print();
}