//
//  check_perm.cpp
//  interview_prep
//
//  Created by Jake Beason on 8/15/19.
//  Copyright © 2019 Jake Beason. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 CTCI p. 90:
 
 --1.2 CHECK PERMUTATION--
Given two strings, write a method to decide
if one is a permutation of the other.
 
 --FOOD FOR THOUGHT--
 - consider uppercase vs. lowercase
 - consider whitespace
 - PERMUTATIONS MUST BE THE SAME LENGTH
 
 */


bool check_perm_ds(string p_str1, string p_str2) {
    
    // assuming charset population is confined to ascii alphabet
    vector<int> char_counts(256, 0);
    
    // loop through first, increment count for each char
    for (int i = 0; i < (int)p_str1.size(); ++i) {
        int curr_char = (int)p_str1[i];
        char_counts[curr_char] += 1;
    }
    
    // loop through second, decrement count for each char
    for (int i = 0; i < (int)p_str2.size(); ++i) {
        int curr_char = (int)p_str2[i];
        char_counts[curr_char] -= 1;
    }
    
    // check for discrepencies
    for (int i = 0; i < (int)char_counts.size(); ++i) {
        if (char_counts[i] != 0) {
            return false;
        }
    }
    
    return true;
}// check_perm_ds()

/*
bool check_perm_sort(string p_str1, string p_str2) {
    
    return false;
}// check_perm_sort()
*/


int main() {
    
    string test_1_first = "abcdefg";
    string test_1_second = "eagcbdf";
    
    string test_2_first = "abcdefga";
    string test_2_second = "eagcbdf";
    
    cout << "--TEST_1" << endl;
    cout << "\t" << test_1_first << " vs. " << test_1_second << endl;
    bool output = check_perm_ds(test_1_first, test_1_second);
    
    cout << "--OUPUT: " << output << endl;
    cout << "\t" << test_2_first << " vs. " << test_2_second << "\n" << endl;
    
    
    cout << "--TEST_2" << endl;
    cout << "\t" << test_1_first << " vs. " << test_1_second << endl;
    output = check_perm_ds(test_2_first, test_2_second);
    
    cout << "--OUPUT: " << output << endl;
    cout << "\t" << test_2_first << " vs. " << test_2_second << "\n" << endl;
    
    return 0;
}// main()
