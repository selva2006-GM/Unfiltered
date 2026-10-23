#include <iostream>

using namespace std;



int main(){

    int n;
    cin >> n;

    int arr[3];
    int a;
    int min;
    for(int i ; i < n ; i++){
        cin >> a;
        cin >> arr[0];
        min = arr[0];
        for(int j = 1 ; j < 3 ; j++){
            cin >> arr[j];
            if(arr[j] < min) min = arr[j];
        }
        cout << a - min << endl;
    }
}