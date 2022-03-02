class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        //TC O(nlog n)
        //Binary Search
        int n=time.size();
        long long lo=0,hi=1e14,ans=hi;
        while(lo<hi)
        {
            long long mid=lo+(hi-lo)/2;
            long long cnt=0;
            for(int i=0;i<n;i++)
            {
                cnt+=(mid/time[i]);
            }
            if(cnt>=totalTrips)
            {
                ans=min(ans,mid);
                hi=mid;
            }
            else
                lo=mid+1;
        }
        return ans;
        
    }
};