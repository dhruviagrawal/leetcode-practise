class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n>0) && ((n&(n-1))==0) && ((n%3)==1);
            
        
        
        // if(n<1)
        //     return false;
        // int m=n;
        // int c=0;
        // while(n>1)
        // {
        //     n=n>>2;
        //     c++;
        // }
        // while(c--)
        // {
        //     n=n<<c;
        // }
        // if(m==n)
        //     return true;
        // else
        //     return false;
        
    }
};