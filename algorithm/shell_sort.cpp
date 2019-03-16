#include <iostream>

using namespace std;

void shell_sort(int *a, int size){
	int increment = size; 
	while(increment != 1){
		increment = increment / 3 + 1;
		for(int i = 0; i < increment; i++){
			for(int j = i; j < size - increment; j += increment){
				int min = a[j], index = j;
				for(int k = j + increment; k < size; k += increment){
					if(min > a[k]){
						min = a[k];
						index = k;
					}
				}
				swap(a[j], a[index]);
			}
		}
		for(int i = 0; i < size; i++)
			cout << a[i] << ' ';
		cout << endl;
	}

}

int main(){
	int a[] = {4, 23, 7, 1, 8, 22, 11, 12, 5};
	shell_sort(a, 9);
}