#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxScore = arr[0];
    int minScore = arr[0];
    int count = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i] > maxScore) {
            count++;
            maxScore = arr[i];
        }
        else if(arr[i] < minScore) {
            count++;
            minScore = arr[i];
        }
    }

    cout << count << endl;
}