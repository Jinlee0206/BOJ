#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m_min = 2147000000, m_max= -2147000000;
vector<int> operands;
vector<int> operators;

void DFS(int res, int lv)
{
	if (lv == n)
	{
		m_min = min(m_min, res);
		m_max = max(m_max, res);
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (operators[i] > 0)
			{
				operators[i]--;
				if (i == 0)
					DFS(res + operands[lv], lv + 1);
				else if (i == 1)
					DFS(res - operands[lv], lv + 1);
				else if (i == 2)
					DFS(res * operands[lv], lv + 1);
				else
					DFS(res / operands[lv], lv + 1);
				operators[i]++;
			}
		}
		return;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		operands.push_back(a);
	}

	for (int i = 0; i < 4; i++)
	{
		int a;
		cin >> a;
		operators.push_back(a);
	}

	DFS(operands[0], 1);
	cout << m_max << " " << m_min << "\n";

	return 0;
}