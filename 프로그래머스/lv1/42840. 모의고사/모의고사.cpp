#include <bits/stdc++.h>
using namespace std;

int num1[] = {1,2,3,4,5};
int num2[] = {2,1,2,3,2,4,2,5};
int num3[] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[] = {0,0,0};
    int max_score = 0;
    
    for(int i = 0; i<answers.size(); i++)
    {
        if(answers[i] == num1[i%5]) score[0]++;
        if(answers[i] == num2[i%8]) score[1]++;
        if(answers[i] == num3[i%10]) score[2]++;
    }
    
    max_score = max(max(score[0], score[1]), score[2]);

    for(int i = 0; i< 3; i++)
    {
        if(max_score == score[i]) answer.push_back(i+1);
    }
    return answer;
}