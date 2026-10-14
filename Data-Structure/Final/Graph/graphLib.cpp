#include<bits/stdc++.h>
#define sp ' '
using namespace std;

class Graph{
    public:
        int size;
        vector<vector<int>> matrix;

        Graph(int size){
            this->size = size;
            matrix.resize(size);
        }

        void insert(int idx,int data){
            matrix[idx].push_back(data);
            sort(matrix[idx].begin(),matrix[idx].end());
        }

        void BFS(int vertex){
            queue<int> q;
            vector<bool> visited;

            q.push(vertex);
            visited.resize(size+1);

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                cout << curr << sp;

                for(int i=0;i<matrix[curr].size();i++){
                    if(visited[matrix[curr][i]] == false){
                        visited[matrix[curr][i]] = true;

                        q.push(matrix[curr][i]);
                    }
                }
            }

            cout << '\n';
        }
};

int main(){
    Graph g(6);

    g.insert(0,2); g.insert(0,1);
    g.insert(1,3); g.insert(1,4);
    g.insert(2,5); g.insert(2,6);

    g.BFS(0);

    return 0;
}