class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
	
        string num = countAndSay(n - 1);

        int count = 1;
        int prev = num[0];
        string res = "";

        for(int i = 1; i < num.length(); i++){
            if(num[i] == prev) count++;
            else{
                res += count + '0';
                res += prev;
                prev = num[i];
                count = 1;
            }
        }
        res += count + '0';
        res += prev;

        return res;
        
    }
};