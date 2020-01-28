//
//  is_unique.cpp
//  interview_prep
//
//  Created by Jake Beason on 8/14/19.
//  Copyright © 2019 Jake Beason. All rights reserved.
//


/*
 CTCI p. 90:
 
 --1.1 IS UNIQUE--
 Implement an algorithm to determine if a string has all unique characters.
 What if you cannot use additional data structures?
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<string> TEST_STRINGS = {"a", "aa", "az", "abcdefg", "abcdefa", ""};
const vector<bool> TEST_SOLUTIONS = {true, false, true, true, false, true};


bool is_unique(string p_str) {
    // assuming string can only contain 0 - 128 chars
    // could also do 256 (extended ascii)
    // be sure to clarify with interviewer!
    
    vector<bool> char_set(128, false);
    if ((int)p_str.size() > 128) return false;
    
    // iterate through string, process chars
    for (int i = 0; i < (int)p_str.size(); ++i) {
        int ascii_val = (int)p_str[i];
        
        // if char already encountered
        if (char_set[ascii_val] == true) {
            return false;
        } else {
            char_set[ascii_val] = true;
        }
        
    }// for
    return true;
}


// driver
int main() {
    
    bool output = true;
    for (int i = 0; i < (int)TEST_STRINGS.size(); ++i) {
        
        cout << "Test #" << i << "\n";
        output = is_unique(TEST_STRINGS[i]);
        
        // accuracy check
        cout << "\tOutput: " << output << endl;
        if (output == TEST_SOLUTIONS[i]) {
            cout << "\t" << "--CORRECT" << endl;
        } else {
            cout << "\t" << "--INCORRECT" << endl;
        }
        
    }// for
    
    return 0;
}
