#include<iostream>
using namespace std;

int stringToInt(string str, int last){
    //base case
    if(last == 0){
        return str[last]- '0';
    }
    //Recursive Call
    int ans = stringToInt(str, last-1);

    //Small work
    int digit = str[last]-'0';
    return ans*10+digit;
}

int main(){
    string str = "324";
    int len = str.size();
    cout<<stringToInt(str, len-1);
    return 0;
}