#include <iostream>
using namespace std;

int main() {
    int n, K;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> K;
    for(int i = 0; i < n; i++){
        int temp = arr[i];
        int address = i;
        for(int j = address; j < n; j++){
            if(arr[i] + arr[j] == K){
                cout << arr[i] << " " << arr[j];
                cout << endl;
            }
        }
    }
}