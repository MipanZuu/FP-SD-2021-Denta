//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long N;
    cin >> N;
 
    vector<long long>arr(N, 0);
    vector<long long>next(N, 0);
    stack<long long>myStack;
 
    for(int i = 0; i < N; i++)
    cin >> arr[i];
    myStack.push(0);
 
    for(int i = 1; i < N; i++){
 
     while(!myStack.empty() && arr[i] > arr[myStack.top()]){
         next[myStack.top()] = i;
         myStack.pop();
    }
 
        myStack.push(i);
    }
 
    while(!myStack.empty()){
        next[myStack.top()] = -1;
        myStack.pop();
 }

    vector<long long> gd(N, 0);
    long long ans = 0;
    for (long long i = N - 1; i >= 0; i--){
 
        if(next[i] == -1){
            gd[i] = arr[i];
            ans = max(ans, gd[i]);
            continue;
        }
        gd[i] = arr[i] ^ gd[next[i]];
        ans = max(ans, gd[i]);
    }
    cout << ans << endl;
    return 0;
}
