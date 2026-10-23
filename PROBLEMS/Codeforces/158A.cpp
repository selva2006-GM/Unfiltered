#include <iostream>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    int arr[n];

    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }

    int i = 0;
    int count = 0;
    while(i < n && arr[i] >= arr[k - 1] && arr[i]>0){
        count++;
        i++;
    }
    cout << count << endl;

}