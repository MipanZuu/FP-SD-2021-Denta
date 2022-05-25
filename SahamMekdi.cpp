//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//


#include <bits/stdc++.h>
using namespace std;


int main() {
   
    int mystock, index, stock[10001], g ,h;
    while(cin>> mystock >> index) {
        
        if(mystock == 0) {
            break;
        }
        
        for(int i = 0; i < mystock; i++) {
            
            scanf("%d.%d", &g, &h);
            g = g * 100 + h;
            stock[i] = g;
        }
        if(stock[index-1] > 5000) {
            cout<<"100.00"<<endl;
            continue;
        }
        int arr[10001] = {}, tmp = 10000-stock[index-1];
        arr[0] = 1;
        for(int i=0; i < mystock; i++) {
            if(i == index-1) {
                continue;
            }
            for(int j = tmp-stock[i]; j >= 0; j--) {
                if(arr[j]) {
                    arr[j+stock[i]] = 1;
                }
            }
        }
        tmp = 5001-stock[index-1];
        while(!arr[tmp])  {
            tmp++;
        }
        
        printf("%.2lf\n", (double)stock[index-1]*100/(tmp+stock[index-1]));
    }
    return 0;
}
