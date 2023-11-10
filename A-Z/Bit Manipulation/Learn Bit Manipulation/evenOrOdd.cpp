#include<iostream>
using namespace std;
string oddEven(int N){
   if(N & 1){
       return  "odd";
   }
   return "even";
}

int main(){
    int n;
    cin>>n;
    cout<<oddEven(n);
    return 0;
}