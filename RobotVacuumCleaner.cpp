#include <iostream>
using namespace std;
int main(){

    /*Main Program here*/

    cout<<"Enter the number of rows and columns: "<<endl;
    int n, m;
    cin >> n >> m;

    char a[n][m];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }


    /*Cleaning process*/

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 'D'){
                cout << "Cleaning at position: (" << i << ", " << j << ")" << endl;
                a[i][j] = 'C'; // Mark as cleaned

                cout<<"for dirt: "<<i<<" "<<j<<endl;

                for(int i=0;i<n;i++){
                    for (int j=0;j<m;j++){
                        cout<<a[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
        }
    }


    return 0;
}
