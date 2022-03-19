class FreqStack {
public:
    unordered_map<int,int>freq; //to track freq of number
    unordered_map<int,stack<int>>groupFreq; //track all nos. having certain freq n then using stack top tie
    int maxfreq; //tells curr maxfreq
    
    FreqStack() {
        freq.clear();
        groupFreq.clear();
        maxfreq=0;
    }
    
    void push(int val) {
        freq[val]++;
        groupFreq[freq[val]].push(val);
        maxfreq=max(maxfreq,freq[val]);
    }
    
    int pop() {
        int ans=groupFreq[maxfreq].top();
        freq[ans]--;
        groupFreq[maxfreq].pop();
        if(groupFreq[maxfreq].size()==0)
            maxfreq--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */