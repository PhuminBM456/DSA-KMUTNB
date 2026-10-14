#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
        string cmd;
        vector<int> arr;
        int count;

        Heap(string cmd){
            this->cmd = cmd;
            count = 0;
        }

        void heapifyUp(){
            int i = arr.size() - 1;

            while(true){
                if(i == 0)
                    break;

                int parent = (i-1) / 2;

                if(cmd == "max"){
                    if(arr[parent] < arr[i]){
                        swap(arr[parent],arr[i]);
                        ++count;
                    }else{
                        break;
                    }
                }else{
                    if(arr[parent] > arr[i]){
                        swap(arr[parent],arr[i]);
                        ++count;
                    }else{
                        break;
                    }
                }

                i = parent;
            }
        }

        void heapifyDown(){
            for(int i=arr.size()-1;i>=0;i--){
            //for(int i=arr.size()/2-1;i>=0;i--){

                int largest,curr;

                largest = curr = i;

                while(true){
                    int left,right;

                    left = curr*2 + 1;
                    right = curr*2 + 2;

                    if(cmd == "max"){
                        if(left < arr.size() && arr[left] > arr[largest])
                            largest = left;

                        if(right < arr.size() && arr[right] > arr[largest])
                            largest = right;
                    }else{
                        if(left < arr.size() && arr[left] < arr[largest])
                            largest = left;

                        if(right < arr.size() && arr[right] < arr[largest])
                            largest = right;
                    }

                    if(largest == curr)
                        break;

                    swap(arr[curr],arr[largest]);
                    ++count;

                    curr = largest;

                }

            }
        }

        void insert(int data){
            arr.push_back(data);
        }
};

int main(){
    
    string cmd;
    int n;

    cin >> cmd;

    Heap heap1(cmd);
    Heap heap2(cmd);

    cin >> n;

    for(int i=0;i<n;i++){
        int temp;

        cin >> temp;

        heap1.insert(temp);
        heap2.insert(temp);

        heap1.heapifyUp();
        //cout << heap1.count << '\n';
    }

    heap2.heapifyDown();

    cout << heap1.count << '\n';
    cout << heap2.count << '\n';

    return 0;
}