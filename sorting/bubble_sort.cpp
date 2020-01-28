//
//  bubble_sort.cpp
//  interview_prep
//
//  Created by Jake Beason on 9/25/19.
//  Copyright © 2019 Jake Beason. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

// www.youtube.com/watch?v=nmhjrI-aW5o
void bubble(int p_arr[], int p_size) {
    
    // outer loop for number of passes
    for (int i = 0; i < p_size - 1; ++i) {
        
        cout << "-- PASS #" << i << " --" << endl;
        
        // inner loop for number of comparisons
        // NOTE: no need to perform comparisons in the
        // already sorted portion of the array
        for (int j = 0; j < p_size - i - 1; ++j) {
            if (p_arr[j] > p_arr[j + 1]) {
                swap(p_arr[j], p_arr[j + 1]);
            }
        }// for
        
        // print for testing
        cout << "-- ";
        for (int i = 0; i < p_size; ++i) {
            cout << p_arr[i];
            if (i != p_size - 1) {
                cout << ", ";
            }
            
        }// for

    }// for

}// bubble()


// MAIN FUNCTION
int main() {
    int arr[] = {2, 7, 4, 1, 5 , 4};
    const int ARR_SIZE = 6;
    bubble(arr, ARR_SIZE);
    return 0;
}
