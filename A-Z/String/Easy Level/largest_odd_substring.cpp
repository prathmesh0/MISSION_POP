#include <iostream>
#include <string>
using namespace std;
// this is not working for certain cases
/*string largestOddSubstr(string str)
{
    string largestsubstr = "";
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if ((str[i] - '0') % 2 == 1)
        {
            string oddsub = "";
            for (int j = i; j < n; j++)
            {
                if ((str[j] - '0') % 2 == 1)
                {
                    oddsub += str[j];
                    if (oddsub.size() > largestsubstr.size())
                    {
                        largestsubstr = oddsub;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    return largestsubstr;
}
*/
string largestOddNumber(string num)
{
    for (int i = num.size() - 1; i >= 0; --i)
        if ((num[i] - '0') % 2)
            return num.substr(0, i + 1);
    return string();
}
int main()
{
    string str = "9721";
    string ans = largestOddNumber(str);
    cout << ans << endl;
    return 0;
}