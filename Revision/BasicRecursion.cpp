#include <iostream>
using namespace std;

int count = 0;
void printNum(int n)
{
    // BS

    if (count == n)
        return;
    cout << count;
    count++;
    // RC
    printNum(n);
}

void printName(int i, int n)
{
    // BC
    if (i > n)
    {
        return;
    }
    cout << "POP" << endl;
    // RC
    printName(i + 1, n);
}
void printOnetoN(int i, int n)
{
    // BC
    if (i > n)
    {
        return;
    }
    cout << i << " ";
    // RC
    printOnetoN(i + 1, n);
}

void printOnetoNBac(int n)
{
    // BC
    if (n == 0)
    {
        return;
    }
    printOnetoNBac(n - 1);
    cout << n << " ";
}

void printNtoOne(int i, int n)
{
    // BC
    if (i < 1)
    {
        return;
    }
    cout << i << " ";
    // RC
    printNtoOne(i - 1, n);
}

void printNtoOneBac(int i, int n)
{
    // BC
    if (i > n)
    {
        return;
    }

    printNtoOneBac(i + 1, n);
    cout << i << " ";
}

// paameterized way
void printSum(int i, int sum)
{
    // bs
    if (i < 1)
    {
        cout << sum << " ";
        return;
    }
    // rc
    printSum(i - 1, sum + i);
}

int printSumf(int n)
{
    if (n == 0)
        return 0;
    return n + printSumf(n - 1);
}

int factf(int num)
{
    int fact = 1;
    if (num == 0)
        return 1;
    fact = num * factf(num - 1);
    return fact;
}

void factpara(int i, int fact)
{
    // bc
    if (i < 1)
    {
        cout << fact << endl;
        return;
    }
    // rc
    factpara(i - 1, fact * i);
}

void reverse(int arr[], int s, int e)
{
    if (s < e)
    {
        swap(arr[s], arr[e]);
        reverse(arr, s+1, e-1);
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int  fibbonacci(int n){
    //base case
    if(n<=1)return n;
    return fibbonacci(n-1)+fibbonacci(n-2);
}

bool palindrome(int i, string& s){
    
    // Base Condition
    // If i exceeds half of the string means all the elements 
    // are compared, we return true.
    if(i>=s.length()/2) return true;
    
    // If the start is not equal to the end, not the palindrome.
    if(s[i]!=s[s.length()-i-1]) return false;
    
    // If both characters are the same, increment i and check start+1 and end-1.
    return palindrome(i+1,s);
}

int main()
{
    int num;
    cin >> num;
    printNum(num);
    printName(1, num);
    printOnetoN(1, num);
    printOnetoNBac(num);
    printNtoOne(num, num);
    printNtoOneBac(1, num);
    printSum(num, 0);
    int ans = printSumf(num);
    cout<<ans;
    int facto = factf(num);
    cout<<facto<<endl;
    factpara(num, 1);

    int n = 4;
    int arr[] = {12, 23, 32, 11};

    reverse(arr, 0, n-1);
    printArray(arr, n);
    

    //fibonacci number series => 0,1,1,2,3,5,8...
    int fibo = fibbonacci(num);
    cout<<fibo<<endl;

    string s ="mahjam";
    bool ispalindrome = palindrome(0, s);
    if(ispalindrome == true){
        cout<<"Given String is Plaindrome.."<<endl;
    }
    else{
        cout<<"Given String is not Plaindrome.."<<endl;
    }

    return 0;
}