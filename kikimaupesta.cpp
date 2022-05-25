//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//

#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int prim[MAX];
int findset(int edg) {
    if(prim[edg]==edg) return edg;

    return findset(prim[edg]);
}

void mset(int n) {
    for(int i=0; i<n; i++)
    prim[i] = i;
}

struct Edge {
    int x, y;
    double z;
    bool operator < (const Edge &p) const
    {
        return z < p.z;
    }
};

vector<Edge> edge;

double krushkal(int n) {
    double sum = 0;
    sort(edge.begin(), edge.end());
    mset(n);
    for(int i=0; i<(int)edge.size(); i++)
    {
        int x = findset(edge[i].x);
        int y = findset(edge[i].y);

        if(x!=y)
        {
            prim[x] = y;
            sum += edge[i].z;
        }
    }
    return sum;
}

int main()
{
    double koordinat[100][2];
    int kasus, n;
    while(scanf("%d", &kasus)==1)
    {
        while(kasus--)
        {
            scanf("%d", &n);
            for(int i=0; i<n; i++)
            {
                scanf("%lf %lf", &koordinat[i][0], &koordinat[i][1]);
            }
            edge.clear();
            for(int i=0; i<n; i++)
                for(int j=i+1; j<n; j++)
                {
                    Edge value;
                    value.x = i;
                    value.y = j;
                    value.z = sqrt(pow(koordinat[i][0]-koordinat[j][0], 2) + pow(koordinat[i][1]-koordinat[j][1], 2));
                    edge.push_back(value);
                }
            double ans = krushkal(n);
            printf("%.2lf\n", ans);
            if(kasus)
                printf("\n");
        }
    }
}
