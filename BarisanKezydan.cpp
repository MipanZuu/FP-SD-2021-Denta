//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//

#include<bits/stdc++.h>
using namespace std;

long long arr[1000010];

int main(){
    int t;
    scanf("%d",&t);
    
    for(int i = 0 ; i < 1000001; i++ ){
        if(i == 0)arr[i] = 11;
        if(i == 1)arr[i] = 15;
        if(i >= 2 && i < 11) arr[i] = ((arr[i-1]% 1000000007) + (arr[i-2]% 1000000007))% 1000000007;
        else if(i >= 11 && i < 15) arr[i] = ((arr[i-11]% 1000000007) + (arr[i-2]% 1000000007))% 1000000007;
        else if(i >= 15) arr[i] = ((arr[i-11]% 1000000007) + (arr[i-15]% 1000000007))% 1000000007;
    }
    
    while(t--){
        int ans;
        scanf("%d",&ans);
        printf("%lld\n", arr[ans]);
    }
    return 0;
}

