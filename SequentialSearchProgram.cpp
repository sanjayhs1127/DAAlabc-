#include <iostream>
using namespace std;

int main() {
    // Fixed array values
    int arr[] = {5, 12, 8, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Element to search
    int key = 20;

    int position = -1;

    // Sequential Search Logic
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            position = i;
            break;
        }
    }

    // Output result
    if(position != -1) {
        cout << "Element " << key << " found at position "
             << position + 1 << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}