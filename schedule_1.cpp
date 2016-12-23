#include <iostream>

using namespace std;

char* choices;

int schedule( int r, int c, int* s, int size )
{
    int A[size];

    for( int i = 0; i < size; i++ )
    {            
        if( i < 3 ) //no room for 4 weeks of B, so choose A for each
        {
            if( i == 0 )
            {
                A[i] = r*s[i];
                choices[i] = 'A'; //record choice
            }
            else
            {
                A[i] = A[i-1] + s[i];
                choices[i] = 'A';
            }
        }
        else if( i == 3 ) //first place B can be chosen, pick min of B or A
        {
            A[i] = min( A[i-1] + r*s[i], 4*c );
            choices[i] = A[i-1] + r*s[i] < 4*c ? 'A' : 'B'; //record choice
        }
        else //pick min of either B for previous 4 weeks or A for current
        {
            A[i] = min( A[i-1] + r*s[i], A[i-4] + 4*c );
            choices[i] = A[i-1] + r*s[i] < A[i-4] + 4*c ? 'A' : 'B';
        }
    }
    
    //Print auxiliary table
    cout << "Auxiliary table: ";
    
    for( int i = 0; i < size; i++ )
        cout << choices[i] << ' ';
        
    cout << endl;
    
    return A[size-1]; //minimum cost is stored in last array element
}

int main()
{
    int r, c, size, *s;

    cout << "Input r: ";
    cin >> r;
    cout << "Input c: ";
    cin >> c;
    cout << "Length of sequence: ";
    cin >> size;
    s = new int[size];
    cout << "Input sequence values: ";
    for( int i = 0; i < size; i++ )
        cin >> s[i];
    
    cout << endl;
    
    choices = new char[size];
    
    int sol = schedule( r, c, s, size );
    
    cout << "Minimum cost: " << sol << endl;  
    
    delete[] choices;
    choices = NULL;
    delete[] s;
    s = NULL;
    
    return 0;
}







