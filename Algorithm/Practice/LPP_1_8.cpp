#include<bits/stdc++.h>
#define sp ' '
#define NEG_INF -1000000
using namespace std;
using vi = vector<int>;
using ll = long long;


int main(){
    vi v;
    int n;
    ll max;


    max = NEG_INF;
    cin >> n;
    v.resize(n);

    for(int i=0;i<n;++i){
        cin >> v[i];
    }

    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            //cout << i << sp << j << sp;

            int sum = 0;

            for(int k=i;k<=j;k++){
                sum += v[k];
            }

            //cout << sum << endl;

            if(sum > max)
                max = sum;
        }
    }

    cout << max << endl;

    return 0;
}