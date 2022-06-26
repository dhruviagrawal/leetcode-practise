class Solution {
public:
    int maxScore(vector<int>&A, int B) {
        int n=A.size();
            int sum=0;
            for(int i=0;i<n;i++)
            sum+=A[i]; //total sum

            int minsum=0, s1=0;
            int i=0, j=n-B-1;
            for(int k=i;k<=j;k++)
            s1+=A[k];

            minsum=s1;
            i++;
            j++;
            while(j<n)
            {
                s1+=A[j];
                s1-=A[i-1];
                minsum=min(minsum,s1);
                i++;
                j++;
            }

            return sum-minsum;
    }
};