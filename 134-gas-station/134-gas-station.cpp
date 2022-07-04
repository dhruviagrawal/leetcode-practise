class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int curr=0;
        
        int start=0,tgas=0,tcost=0;
        
        for(int i=0;i<n;i++)
            tgas+=gas[i];
        
        for(int i=0;i<n;i++)
            tcost+=cost[i];
        
        if(tgas<tcost)
            return -1;
        
        for(int i=0;i<n;i++)
        {
            curr+=(gas[i]-cost[i]);
            if(curr<0)
            {
                start=i+1;
                curr=0;
            }
        }
        
        return start;
    }
};