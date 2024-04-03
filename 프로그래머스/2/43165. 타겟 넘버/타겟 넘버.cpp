#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int idx, int result, int target){

    if(idx == numbers.size()){
        if(result == target) answer++;
        return;
    }
    dfs(numbers, idx + 1, result + numbers[idx], target);
    dfs(numbers, idx + 1, result - numbers[idx], target);
}
int solution(vector<int> numbers, int target) {
    
    
    dfs(numbers, 0, 0, target);
    return answer;
}