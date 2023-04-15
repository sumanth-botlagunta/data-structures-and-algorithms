#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int minimum_lightbulbs(int M, int R, vector<int> &streetlights)
{
  vector<int> DP(M + 1, INF);
  DP[0] = 0;

  for (int i = 1; i <= M; i++)
  {
    for (int j = streetlights.size() - 1; j >= 0; j--)
    {
      if (i - streetlights[j] > R)
      {
        break;
      }
      DP[i] = min(DP[i], DP[max(0, streetlights[j] - R)] + 1);
    }
  }

  if (DP[M] == INF)
  {
    return -1; // or any value indicating "IMPOSSIBLE"
  }
  else
  {
    return DP[M];
  }
}

int main()
{
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    int M, R, N;
    cin >> M >> R >> N;

    vector<int> streetlights(N);
    for (int j = 0; j < N; j++)
    {
      cin >> streetlights[j];
    }

    int ans = minimum_lightbulbs(M, R, streetlights);
    if (ans == -1)
    {
      cout << "Case #" << i << ": "
           << "IMPOSSIBLE" << endl;
    }
    else
    {
      cout << "Case #" << i << ": " << ans << endl;
    }
  }

  return 0;
}
