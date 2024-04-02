#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    vector<vector<int>> v(land.size(), vector<int>(4));
    
    for(int i = 0;i<4;i++){
        v[0][i] = land[0][i];
    }
    
    for(int i = 1; i<land.size(); i++){
        for(int j = 0;j < 4;j++){
            
            int max = -1;
            
            for(int idx = 0 ; idx < 4; idx++){
                if(j != idx && v[i -1][idx] > max) max = v[i -1][idx];
            }
            
            v[i][j] = land[i][j] + max;
        }
    }
    sort(v[land.size() - 1].begin(), v[land.size() - 1].end());

    return v[land.size() - 1][3];
}