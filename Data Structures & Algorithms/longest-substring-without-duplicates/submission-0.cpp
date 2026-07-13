class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int left=0;
        int ans=0;
        for(int r=0;r<s.size();r++){
            while(st.find(s[r])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[r]);
            ans= max(ans,r-left+1);
        }
        return ans;
    }
};
