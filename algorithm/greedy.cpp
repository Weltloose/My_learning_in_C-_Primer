// Let S = {1, 2, . . . , n} be the set of activities that compete for a resource. 
// Each activity i has its starting time si and finish time fi with si ≤ fi, namely, 
// if selected, i takes place during time [si, fi). No two activities can share the 
// resource at any time point. We say that activities i and j are compatible if 
// their time periods are disjoint.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ev{
public:
	int start, end;
	ev(int a, int b): start(a), end(b){}
	ev() = default;
};

int main(){
	int start[] = {0, 3, 4, 2, 5, 3, 9, 11, 10};
	int end[] = {3, 4, 6, 8, 9, 12, 13, 14, 15};
	vector<ev> v;
	for(int i = 0; i != 9; i++)
		v.push_back(ev(start[i], end[i]));
	sort(v.begin(), v.end(), [](ev e1, ev e2){return e1.end < e2.end;});
	int cnt = 0, fin_time = 0;
	for(auto i = v.cbegin(); i != v.cend(); i++)
		if(i->start >= fin_time){
			fin_time = i->end;
			cnt ++ ;
		}
	cout << cnt << endl;
}