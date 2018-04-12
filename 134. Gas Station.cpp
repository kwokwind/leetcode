/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        vector<int> startPoints;
        for (int i=0; i<gas.size(); ++i) {
            total += gas[i] - cost[i];
            if (gas[i] >= cost[i])
                startPoints.push_back(i);
        }
        
        if (total < 0) return -1;
        
        int ret = -1;
        for (auto s : startPoints) {
            int i = s;
            int rest = 0;
            do {
                rest += gas[i] - cost[i];
                if (rest >= 0) {
                    i++;
                    if (i == gas.size()) i = 0;
                    // return to start point, it is a solution
                    if (i == s)  ret = s;
                } else {
                    // solution is broken, break and try next start point
                    break;
                }
            } while( i != s);
            
            if (ret != -1)
                break;
        }
        
        return ret;
    }
};
