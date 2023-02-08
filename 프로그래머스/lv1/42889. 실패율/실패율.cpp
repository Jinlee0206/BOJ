#include <bits/stdc++.h>

using namespace std;

map<int, double> mp;

bool cmp(const pair<int,double>& a, const pair<int,double>& b)
{
	if (a.second == b.second) return a.first < b.second; // 같으면 key(스테이지) 기준 오름차순
	else return a.second > b.second; // value(실패율) 기준 내림차순 정렬
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
	int reached_player = stages.size();
	double per;

	// 맵을 미리 생성해 놓기
	for (int i = 0; i < N; i++)
	{
		mp.insert({ i + 1, 0 });
	}

	int stage_level = 1;
	while (stage_level <= N)
	{
		int stage_players = count(stages.begin(), stages.end(), stage_level);
		
		if (reached_player == 0) per = 0; //분모가 0인경우 방지
		else per = ((double)stage_players / (double)reached_player);

		mp[stage_level] = per;
		reached_player -= stage_players;
		stage_level++;
	}

	vector<pair<int, double>> newV(mp.begin(), mp.end());
	stable_sort(newV.begin(), newV.end(), cmp);
    
    for(int i = 0 ;i < newV.size(); i++) answer.push_back(newV[i].first);
    
    return answer;
}