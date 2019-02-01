#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(){
	map<string, int> word_cnt;
	set<string> exclude = {"and", "or", "the"};
	while(cin >> word)	
		if(exclude.find(word) == exclude.end())
			++word_cnt[word];
	for(const auto &w : word_cnt)
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

}