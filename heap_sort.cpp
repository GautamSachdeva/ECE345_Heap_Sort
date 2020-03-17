#include <bits/stdc++.h> 

using namespace std;

void max_heapify(vector<int> &A,int i){
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	if(left < A.size() && A[left] > A[largest]){
		largest = left;
	}
	if(right < A.size() && A[right] > A[largest]){
		largest = right;
	}
	if(largest != i){
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		max_heapify(A,largest);
	}
}


void build_max_heap(vector<int> &A){
	int last_node = A.size() -1;
	int last_parent = (last_node - 1)/2;
	for(int i = last_parent ; i > -1 ; i--){
		max_heapify(A,i);
	}
}

vector<int> heap_sort(vector<int> A){
	vector<int> ans;
	build_max_heap(A);
	while(!A.empty()){
		int max;
		max = A[0];
		A[0] = A[A.size() - 1];
		A[A.size() - 1] = max;
		ans.push_back(max);
		A.pop_back();
		max_heapify(A,0);
	}
	return ans;
}



int main(){
	vector<int> A{50,20,30,5};
	vector<int> ans = heap_sort(vect);
	for(int i = 0 ; i < ans.size() ; i++){
		cout << ans[i] << endl;
	}	
}

