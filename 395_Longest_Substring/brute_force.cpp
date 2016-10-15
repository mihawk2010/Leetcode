#include<string>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) 
	{
		for (int length = s.size(); length >= 1; length--)
			for (int start = 0; start + length - 1 < s.size(); start++)
				if (is_valid(s.substr(start, length), k))
				{
					cout << s.substr(start, length) << endl;
					return length;
				}
		return 0;
	}

	bool is_valid(string s, int k)
	{
		map<char, int> count;
		for (string::iterator it = s.begin(); it != s.end(); ++it)
		{
			if (count.find(*it) != count.end())
				count[*it]++;
			else
				count[*it] = 1;
		}
		for (map<char, int>::iterator it = count.begin(); it != count.end(); ++it)
		{
			if (it->second < k)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.longestSubstring("aaabb", 3) << endl;
	cout << s.longestSubstring("ababbc", 2) << endl;
	system("pause");
	return 0;
}