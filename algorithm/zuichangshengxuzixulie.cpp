#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	int array[] = {9, 44, 32, 12, 7, 42, 34, 92, 35, 37, 41, 8, 20, 27, 83, 64, 61, 28, 39, 93, 29, 17, 13, 14, 55, 21, 66, 72, 23, 73, 99, 1, 2, 88, 77, 3, 65, 83, 84, 62, 5, 11, 74, 68, 76, 78, 67, 75, 69, 70, 22, 71, 24, 25, 26};
	int size = sizeof(array) / sizeof(array[0]);
	//cout << size << endl;
	int pre[100];
	memset(pre, -1, sizeof(pre));
	int a[100];
	memset(a, 0, sizeof(a));
	a[0] = 1;
	int index = 0;
	int cindex = 0;
	for(int i = 1; i < size; i++){
		index = -1;
		a[i] = 1;
		for(int j = 0; j < i; j++){
			if(array[j] < array[i] && (a[j] + 1) > a[i]){
				a[i] = a[j] + 1;
				index = j;
				cindex = i;
			}
		}
		pre[i] = index;
	}
	cout << a[size - 1] << endl;
	cout << a[cindex] << endl;
	while(cindex != -1){
		cout << array[cindex] << ' ';
		cindex = pre[cindex];
	}

}