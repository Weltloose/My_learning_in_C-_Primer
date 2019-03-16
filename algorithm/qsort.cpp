#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int random_piv(int start, int end){
	int n = rand() % (end - start) + start;
	return n;
}

void qsort(int start, int end, int array[])
{
	if(start >= end) return;
	int i = start, j = end + 1;
	int p = random_piv(start, end);
	swap(array[p], array[start]);
	int pri = array[start];
	while(1){
		while(array[++ i] < pri);
		while(array[-- j] > pri);
		if(i < j)
			swap(array[i], array[j]);
		else break;
	}
	swap(array[start], array[i - 1]);
	qsort(start, i - 2, array);
	qsort(i, end, array);
}

int main(){
	srand(time(NULL));
	int a[] = {3, 5, 1, 32, 541, 12, 43};
	qsort(0, 6, a);
	for(auto i = begin(a); i != end(a); i++)
		cout << *i << ' ';
}