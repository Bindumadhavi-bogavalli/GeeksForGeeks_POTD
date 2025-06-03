#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
  public:
    int atmostk(string& s, int k) {
        int left = 0;
        int cnt = 0;
        unordered_map<char, int> freq;
        
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }

    int countSubstr(string& s, int k) {
        return atmostk(s, k) - atmostk(s, k - 1);
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter value of k (1 to 26): ";
    cin >> k;

    int result = sol.countSubstr(s, k);
    cout << "Number of substrings with exactly " << k << " distinct characters: " << result << endl;

    return 0;
}
