#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

int array[] = {3, 1, 10, 2, 5, 4, 11, 33, 5};
int a_size = sizeof(array) / sizeof(array[0]);

void merge_sort(int from, int to){
	if(from >= to) return;
	int mid = (from + to) / 2;
	merge_sort(from, mid);
	merge_sort(mid + 1, to);
	int *temp = new int [to - from + 1];
	int i = from, j = mid + 1, cnt = 0;
	while(i <= mid && j <= to){
		if(array[i] < array[j])
			temp[cnt++] = array[i++];
		else 
			temp[cnt++] = array[j++];
	}
	while(i <= mid)
		temp[cnt++] = array[i++];
	while(j <= to)
		temp[cnt++] = array[j++];
	for(i = from; i <= to; i++)
		array[i] = temp[i - from];
	delete temp;
}

int main(){
	merge_sort(0, a_size - 1);
	for(auto i : array) cout << i << ' ';
	cout << endl;
}