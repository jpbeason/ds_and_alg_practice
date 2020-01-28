//
//  main.cpp
//  interview_prep
//
//  Created by Jake Beason on 8/14/19.
//  Copyright © 2019 Jake Beason. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class StepCounter {
    vector<int> waysToStep;
    
public:
    
    // constructor
    StepCounter(int p_numSteps) {
        waysToStep.resize(p_numSteps, 0);
        waysToStep[0] = 0;
        waysToStep[1] = 1;
    }
    
    // recursive function
    int countWays(int p_numSteps) {
        
        // base cases
        if (p_numSteps <= 0) {
            return 0;
        } else if (p_numSteps == 1) {
            return 1;
        }
        
        // memoization
        for (int i = 0; i < p_numSteps; ++i) {
            if (i >= 1) {
                waysToStep[i] += waysToStep[i - 3];
            }
            if (i >= 2) {
                waysToStep[i] += waysToStep[i - 2];
            }
            if (i >= 3) {
                waysToStep[i] += waysToStep[i - 1];
            }
        }
        
        return waysToStep[p_numSteps - 1];

    }// StepCounter
};

int main() {
    StepCounter myStepCounter(5);
    int solution = myStepCounter.countWays(5);
    cout << solution << endl;
}
