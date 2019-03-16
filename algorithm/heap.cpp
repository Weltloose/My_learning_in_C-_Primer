#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 30;

class HEAP{
private:
	int heap[SIZE];
	int size;
public:
	HEAP() = default;
	HEAP(int a[], int s): size(s){
		memcpy(heap, a, sizeof(int) * s);
		for(int i = size - 1; i > 0; i--)
			go_up(i);
		for(int i = 0; i < size; i++)
			go_down(i);
	}
	void go_up(int index){
		int child = index;
		int parent = (child + 1) / 2 - 1;  // 1 / 2 = 0
		while(child != 0){
			if(heap[parent] > heap[child]){
				swap(heap[parent], heap[child]);
				child = parent;
				parent = (child + 1) / 2 - 1;
			}
			else break;
		}
	} 
	void go_down(int index){
		int parent = index;
		int child = parent * 2 + 1;
		while(child < size){
			if(child + 1 < size && heap[child + 1] < heap[child]) child ++ ;
			if(heap[parent] > heap[child]){
				swap(heap[parent], heap[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else break;
		}
	}
	int pop(){
		swap(heap[0], heap[--size]);
		go_down(0);
		return heap[size + 1];
	}
	void push(int a){
		heap[size] = a;
		go_up(size++);
	}
	void print(){
		for(int i = 0; i < size; i++) cout << heap[i] << ' ';
	}
};

int main(){
	int a[] = {11, 23, 51, 12, 32, 1, 24, 26};
	HEAP h(a, 8);
	cout << h.pop() << endl;
	h.push(22);
	h.print();
}