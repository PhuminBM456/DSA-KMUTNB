#include<bits/stdc++.h>
using namespace std;

class Heap{
	public:
		vector<int> arr;
		
		void addNode(int data){
			arr.push_back(data);
			heapifyUp();
		}
		
		void delNode(){
			int temp;
			
			if(arr.empty()){
				return;
			}
			
			if(arr.size() == 1){
				arr.pop_back();
				return;
			}
			
			temp = arr.back();
			arr[0] = temp;
			arr.pop_back();
			
			heapifyDown();
		}
		
		void heapifyUp(){
			int i = arr.size() - 1;
			
			while(i != 0){
				int parent = (i-1)/2;
				
				if(arr[parent] < arr[i]){
					swap(arr[parent] , arr[i]);
				}
				
				else{
					break;
				}
				
				i = parent;
			}
		}
		
		void heapifyDown(){
			int i = 0;
			
			while(true){
				int largest,left,right;
				
				largest = i;
				left = 2*i+1;
				right = 2*i+2;
				
				if(left < arr.size() // basecase
					&& arr[largest] < arr[left]){
					largest = left;
				}
				
				if(right < arr.size() // basecase
					&& arr[largest] < arr[right]){
					largest = right;
				}

				if(largest == i){
					break;
				}
				
				swap(arr[i] , arr[largest]);
				
				i = largest;
			}
		}
};

int main(){
	
}