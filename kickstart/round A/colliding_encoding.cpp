#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    // Read the mapping
    int mapping[26];
    for (int i = 0; i < 26; i++)
    {
      cin >> mapping[i];
    }

    // Read the words and check for collisions
    int N;
    cin >> N;
    unordered_map<string, bool> seen;
    bool collision = false;
    for (int i = 0; i < N; i++)
    {
      string word;
      cin >> word;

      // Encode the word using the mapping
      for (char &c : word)
      {
        c = mapping[c - 'A'] + '0';
      }

      // Check if the encoded word has been seen before
      if (seen[word])
      {
        collision = true;
      }
      else
      {
        seen[word] = true;
      }
    }

    // Output the result
    cout << "Case #" << t << ": " << (collision ? "YES" : "NO") << endl;
  }
  return 0;
}
