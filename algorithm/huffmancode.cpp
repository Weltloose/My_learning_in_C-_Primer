#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class store{
public:
	store(int count = 0, char ch = '0', store *l = NULL, store *r = NULL): cnt(count), c(ch), left(l), right(r){}
	store(const store &s) = default;
	store(store *s1, store *s2): cnt(s1->cnt + s2->cnt), c('0'), left(s1), right(s2){}
	bool ch_or_not() const {return c != '0';}
	int get_cnt() const {return cnt;}
	friend void rec(store *root, int &, int);
private:
	int cnt;
	char c;
	store *left, *right;
};


void rec(store *root, int &count, int level = 0){
	if(root == NULL) return;
	cout << root->c << ": " << root->cnt << endl;
	if(root->c != '0') count += level * root->cnt;
	rec(root->left, count, level + 1);
	rec(root->right, count, level + 1);
}

int main(){
	ifstream in;
	in.open("test.txt");
	map<char, int> m;
	if(in.is_open()){
		string str;
		while(getline(in, str)){
			int n = str.size();
			for(int i = 0; i < n; i++)
				if((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A'))
					m[str[i]] ++ ;
		}
	}
	vector<store *> v;
	// for(auto i : m) 
	// 	v.push_back(new store(i.second, i.first));
	v.push_back(new store(3, 'a'));
	v.push_back(new store(5, 'b'));
	v.push_back(new store(7, 'c'));
	v.push_back(new store(4, 'd'));

	make_heap(v.begin(), v.end(), [](const store *s1, const store *s2){return s1->get_cnt() > s2->get_cnt();});
	while(v.size() > 1){
		store *temp1 = v[0];
		pop_heap(v.begin(), v.end(), [](const store *s1, const store *s2){return s1->get_cnt() > s2->get_cnt();});
		v.pop_back();
		store *temp2 = v[0];
		pop_heap(v.begin(), v.end(), [](const store *s1, const store *s2){return s1->get_cnt() > s2->get_cnt();});
		v.pop_back();
		store *temp3 = new store(temp1, temp2);
		v.push_back(temp3);
		push_heap(v.begin(), v.end(), [](const store *s1, const store *s2){return s1->get_cnt() > s2->get_cnt();});
	}
	int cnt = 0;
	rec(v[0], cnt);
	cout << cnt << endl;
}