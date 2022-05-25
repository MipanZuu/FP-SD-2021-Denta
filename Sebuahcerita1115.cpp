//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//


#include <bits/stdc++.h>
using namespace std;

long long mod11(long long x)
{
    return x % 11;
}

long long mod15(long long x)
{
    return x % 15;
}

bool search (long long n){
    while(true){
        if(mod11(n) == 0 || mod15(n) == 0){
            return true;
            break;
        }
        n -= 11;
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t, n;
//    cin >> t;
    scanf("%lld", &t);
    
    while (t--){
//        cin >> n;
        scanf("%lld", &n);
        
        if(n >= 11){
            if(search(n))
//            cout << "YES" << endl;
                printf("YES\n");
            else
//            cout << "NO" << endl;
                printf("NO\n");
            
        } else
//        cout << "NO" << endl;
            printf("NO\n");
    }
    return 0;
}
