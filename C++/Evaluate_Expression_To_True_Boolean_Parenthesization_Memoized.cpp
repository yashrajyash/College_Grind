#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int parenthesis_count(string s,
                      int i,
                      int j,
                      int isTrue)
{
    // Base Condition
    if (i > j)
        return false;
    if (i == j)
    {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    string tmp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);

    if(mp.find(tmp) != mp.end()) {
        return mp[tmp];
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        string tmp1 = to_string(i) + " " + to_string(k-1) + " 1";
        string tmp2 = to_string(k+1) + " " + to_string(j) + " 1";
        string tmp3 = to_string(i) + " " + to_string(k-1) + " 0";
        string tmp4 = to_string(k+1) + " " + to_string(j) + " 0";

        int leftF, leftT, rightT, rightF;
        // Count no. of T in left partition
        if(mp.find(tmp1) != mp.end()) {
            leftT = mp[tmp1];
        } else {
            leftT = parenthesis_count(s, i, k - 1, 1);
        }
        // Count no. of T in right partition
        if(mp.find(tmp2) != mp.end()) {
            rightT = mp[tmp2];
        } else {
            rightT = parenthesis_count(s, k + 1, j, 1);
        }
        // Count no. of F in left partition
        if(mp.find(tmp3) != mp.end()) {
            leftT = mp[tmp3];
        } else {
            leftF = parenthesis_count(s, i, k - 1, 0);
        }
        // Count no. of F in right partition
        if(mp.find(tmp4) != mp.end()) {
            rightF = mp[tmp4];
        } else {
            rightF = parenthesis_count(s, k + 1, j, 0);
        }
        
        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans += leftT * rightT;
            else
                ans += leftF * rightF + leftT * rightF + leftF * rightT;
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += leftT * rightT + leftT * rightF + leftF * rightT;
            else
                ans = ans + leftF * rightF;
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans = ans + leftF * rightT + leftT * rightF;
            else
                ans = ans + leftT * rightT + leftF * rightF;
        }
        mp[tmp] = ans;
    }
    return ans;
}

// Driver Code
int main()
{
    string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;

    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }

    // We obtain the string T|T&F^T
    int n = s.length();

    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
    // (T|((T&F)^T))
    mp.clear();
    cout << parenthesis_count(s, 0, n - 1, 1);
    return 0;
}
