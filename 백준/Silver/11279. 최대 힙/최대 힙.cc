#include<iostream>

using namespace std;

int Heap[100001];
int Heap_idx=0;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Heap_push(int x) {
	Heap[++Heap_idx] = x;
	int child = Heap_idx;
	int parent = child / 2;
	while (child > 1 && Heap[parent] < Heap[child]) {
		swap(&Heap[parent], &Heap[child]);
		child = parent;
		parent = child / 2;
	}
}
int Heap_pop() {
	if (Heap_idx == 0) {
		return 0;
	}
	int result = Heap[1];
	swap(&Heap[1], &Heap[Heap_idx--]);
	int parent = 1;

	while (true) {
		int child = parent * 2;
		if (child + 1 <= Heap_idx && Heap[child] < Heap[child + 1]) {
			child++;
		}
		if (child > Heap_idx || Heap[parent] >= Heap[child]) {
			break;
		}
		swap(&Heap[parent], &Heap[child]);
		parent = child;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N,x;
	cin >> N;
	while (N--) {
		cin >> x;
		if (x == 0) {
			cout << Heap_pop() << "\n";
		}
		else {
			Heap_push(x);
		}

	}


	return 0;
}