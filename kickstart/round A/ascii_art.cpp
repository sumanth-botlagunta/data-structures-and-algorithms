#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    long long N;
    cin >> N;
    long long len = 0, i = 1;
    while (N > len + 26 * i)
    {
      len += 26 * i;
      i++;
    }
    N -= len;
    long long j = 0;
    while (N > (j + 1) * i)
    {
      j++;
    }
    N -= j * i;
    long long k = pow(26, i - j - 1);
    N--;
    k += N / (i - j - 1);
    N %= i - j - 1;
    while (j < i - 1)
    {
      k /= 26;
      j++;
      if (N == 0)
      {
        cout << "Case #" << t << ": " << char('A' + k % 26) << endl;
        break;
      }
      k += k % 26 * pow(26, i - j - 1);
      N--;
    }
    if (N > 0)
    {
      cout << "Case #" << t << ": " << char('A' + k / pow(26, i - 1)) << endl;
    }
  }
  return 0;
}
