// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

//Brute force
// bool check_rotation(string s, string goal)
// {
// 	if (s.size() != goal.size())
// 		return false;

// 	queue<char> q1;
// 	for (int i = 0; i < s.size(); i++) {
// 		q1.push(s[i]);
// 	}

// 	queue<char> q2;
// 	for (int i = 0; i < goal.size(); i++) {
// 		q2.push(goal[i]);
// 	}

// 	int k = goal.size();
// 	while (k--) {
// 		char ch = q2.front();
// 		q2.pop();
// 		q2.push(ch);
// 		if (q2 == q1)
// 			return true;
// 	}
// 	return false;
// }

//optimal approach
bool check_rotation(string str1, string str2)
{
    
    if (str1.length() != str2.length())
        return false;
 
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}
// Driver code
int main()
{
	string str1 = "AACD", str2 = "ACDA";

	if (check_rotation(str1, str2))
		printf("Strings are rotations of each other");
	else
		printf("Strings are not rotations of each other");
	return 0;
}
