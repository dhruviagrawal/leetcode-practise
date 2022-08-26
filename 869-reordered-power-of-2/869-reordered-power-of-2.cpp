class Solution {
public:
    vector<int> count(int n)
    {
        vector<int>d(10,0);
        while(n)
        {
            d[n%10]++;
            n/=10;
        }
        return d;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int>cn=count(n);
        
        int num=1;
        for(int i=0;i<31;i++)
        {
            if(cn==count(num))
                return true;
            num<<=1;
        }
        return false;
        
    }
};