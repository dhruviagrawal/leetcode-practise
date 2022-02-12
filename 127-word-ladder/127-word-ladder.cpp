class Solution {
public:
    //TC O(26 * size of beginWord * number of words in wordList)
    
    /*
    To find word in O(1) time, use hash set
    visualize as a graph
    words as nodes
    the path is word as changed 
    start n end node given
    So,
    here we have to find 'shortest' path,
    when shortest needed do BFS traversal

    //Algorithm-
    take queue
    add begin word
    pop it
    loop 1 to word size //checking all characters which must be replaced
             loop a to z : replace and check set whether new word there
	                       if new word there, put in queue new word 



    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        int n=beginWord.size();
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            pair<string,int> p=q.front();
            string word=p.first;
            int ans=p.second;
            q.pop();
            if(word==endWord) return ans;
            st.erase(word);
            for(int i=0;i<n;i++)
            {
                char ch=word[i];
                for(int j=0;j<26;j++)
                {
                    word[i]='a'+j;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,ans+1});
                    }
                }
                word[i]=ch; //we have to check other possibilties!
            }
        }
        return 0;
    }
    
};