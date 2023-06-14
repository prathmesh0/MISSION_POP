#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout<<j<<" ";
        }
            cout<<endl;
    }

    for (int i = 0; i < n; i++)
    { // for number of rows
        for (int j = 0; j < (n - i - 1); j++)
        { // space
            cout << " ";
        }
        //space
        for (int k = 0; k < (2 * i + 1); k++)
        {
            cout << "*";
        }
        cout<<endl;
    }

    for (int i = 0; i < n; i++)
    {

        // space

        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        // star
        for (int k = 0; k < (2*n - (2*i + 1)); k++)
        {
            cout << "*";
        }
        cout << endl;
    }


    for(int i = 0; i<n; i++){
        //spade
        for(int j = 0;j<(n-i-1); j++){
            cout<<" ";
        }
        //star
        for(int k = 0; k<(2*i+1); k++){
            cout<<"*";
        }
        cout<<endl;

    }
    for(int i = 0; i<n;i++){
        //space
        for(int j =0 ; j<i; j++){
            cout<<" ";
        }
        //star
        for(int k = 0; k<(2*n-(2*i+1));k++){
            cout<<"*";
        }
        cout<<endl;
    }

   for (int i =1 ; i<=(2*n-1); i++){
    //star
    int star = i;
    if(i>n){
        star = 2*n-i;
    }
    for(int i =0; i<star; i++){
        cout<<"*";
    }
    cout<<endl;
   }

    int start = 1;
    for (int i = 0; i < n; i++)
    {
        if(i%2 == 0){
            start = 1;
        }
        else{
            start = 0;
            }
        for(int j =0; j<=i; j++){
            cout<<start;
            start = 1- start;
        }
        cout<<endl;
    }


     int spce = 2 * (n - 1);

        for (int i = 1; i <= n; i++)
        {

            // number
            for (int j = 1; j <= i; j++)
            {
                cout << j << " ";
            }

            // space
            for (int j = 1; j <= spce; j++)
            {
                cout << "  ";
            }

            // number
            for (int j = i; j >= 1; j--)
            {

                cout << j << " ";
            }

            cout << endl;
            spce -= 2;
        }


    int num = 1;
    for(int i =1; i<=n;i++){
        for(int j = 1; j<=i; j++){
            cout<<num<<" ";
            num +=1;
        }
        cout<<endl;
    }


    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }

        for (int i = 0; i < n; i++)
        {
            char ch = 'A' + i;
            for (int j = 0; j <= i; j++)
            {
                cout << ch << " ";
            }
            cout << endl;
        }



    // space = 3,2,1,0 letters -> 1,3,5,7 rows->4
    for (int i = 0; i < n; i++)
    {
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // alphabets
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= (2 * i + 1); j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }

        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }

    for(int i = 0; i< n; i++){
        for(char ch = 'E'-i; ch<='E';ch++ ){
                cout<<ch<<" ";
        }
        cout<<endl;
    }

    int ispace = 0;
    for (int i = 0; i < n; i++)
    {
        // star
        for (int j = 1; j <= (n - i); j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < ispace; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 1; j <= (n - i); j++)
        {
            cout << "*";
        }
        cout << endl;
        ispace += 2;
    }

    ispace = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {
        // star
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < ispace; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
        ispace -= 2;
    }

    int space = 2 * n - 2;
    for (int i = 1; i <= (2 * n - 1); i++)
    {
        // star
        int star = i;
        if (i > n)
            star = 2 * n - i;
        for (int j = 1; j <= star; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }

        // star
        for (int j = 1; j <= star; j++)
        {
            cout << "*";
        }
        cout << endl;
        if (i < n)
            space -= 2;
        else
            space += 2;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
   
   for(int i = 0; i<(2*n-2); i++){
    for(int j = 0; j<(2*n-2); j++){
        int top = i;
        int left = j;
        int right = (2*n-2)-j;
        int bottom = (2*n-2)-i;
        cout<<(n- min(min(top,bottom), min(left, right)));
    }
    cout<<endl;
   }
}