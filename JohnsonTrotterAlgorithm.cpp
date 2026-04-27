#include <iostream>
using namespace std;

#define LEFT 0
#define RIGHT 1

// Structure for element with direction
struct Element {
    int value;
    int direction;
};

// Function to print permutation
void printPermutation(Element arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i].value << " ";
    cout << endl;
}

// Find largest mobile element
int getMobile(Element arr[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i].direction == LEFT && i != 0) {
            if(arr[i].value > arr[i-1].value && arr[i].value > mobile) {
                mobile = arr[i].value;
                mobileIndex = i;
            }
        }
        if(arr[i].direction == RIGHT && i != n-1) {
            if(arr[i].value > arr[i+1].value && arr[i].value > mobile) {
                mobile = arr[i].value;
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

// Generate permutations
void johnsonTrotter(int n) {
    Element arr[n];

    // Initialize elements
    for(int i = 0; i < n; i++) {
        arr[i].value = i + 1;
        arr[i].direction = LEFT;
    }

    printPermutation(arr, n);

    while(true) {
        int mobileIndex = getMobile(arr, n);
        if(mobileIndex == -1)
            break;

        int swapIndex;
        if(arr[mobileIndex].direction == LEFT)
            swapIndex = mobileIndex - 1;
        else
            swapIndex = mobileIndex + 1;

        // Swap
        Element temp = arr[mobileIndex];
        arr[mobileIndex] = arr[swapIndex];
        arr[swapIndex] = temp;

        // Reverse direction of elements greater than mobile
        for(int i = 0; i < n; i++) {
            if(arr[i].value > arr[swapIndex].value) {
                arr[i].direction = (arr[i].direction == LEFT) ? RIGHT : LEFT;
            }
        }

        printPermutation(arr, n);
    }
}

// Main function with fixed value
int main() {
    int n = 3;   // fixed value

    cout << "Permutations using Johnson-Trotter:\n";
    johnsonTrotter(n);

    return 0;
}