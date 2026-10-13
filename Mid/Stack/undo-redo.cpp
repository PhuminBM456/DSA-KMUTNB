#include<bits/stdc++.h>
#define sp ' '
using namespace std;

int main(){
    vector<string> undo;
    vector<string> redo;
    string arr[4] = {"a","b","c","d"};

    for(int i=0;i<4;i++){
        undo.push_back(arr[i]);
    }

    while(2+1==3){
        string cmd;

        cin >> cmd;

        if(cmd == "z"){
            if(undo.empty())
                continue;

            // undo;
            string temp = undo.back();
            undo.pop_back();
            redo.push_back(temp);
        }else if(cmd == "y"){
            if(redo.empty())
                continue;

            // redo
            string temp = redo.back();
            redo.pop_back();
            undo.push_back(temp);
        }

        for(int i=0;i<undo.size();i++){
            cout << undo[i] << sp;
        }

        cout << '\n';
    }

    return 0;
}