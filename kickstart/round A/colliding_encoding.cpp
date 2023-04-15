#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to check if there are any collisions between words
string checkCollisions(vector<string> words, unordered_map<char, int> mapping)
{
  unordered_map<string, int> encodedWords; // map to store encoded words
  for (string word : words)
  {
    string encodedWord = "";
    for (char c : word)
    {
      encodedWord += to_string(mapping[c]); // encode word using mapping
    }
    // check if encoded word already exists in map
    if (encodedWords.find(encodedWord) != encodedWords.end())
    {
      return "YES"; // collision found
    }
    encodedWords[encodedWord] = 1; // add encoded word to map
  }
  return "NO"; // no collisions found
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++)
  {
    unordered_map<char, int> mapping;
    string mappingStr;
    cin >> mappingStr;
    for (int j = 0; j < 26; j++)
    {
      mapping[char('A' + j)] = mappingStr[j] - '0'; // build mapping
    }
    int N;
    cin >> N;
    vector<string> words(N);
    for (int j = 0; j < N; j++)
    {
      cin >> words[j];
    }
    string result = checkCollisions(words, mapping); // check for collisions
    cout << "Case #" << i << ": " << result << endl;
  }
  return 0;
}
