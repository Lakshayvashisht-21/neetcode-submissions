class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int> st(nums.begin(),nums.end());
        
        int cnt=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int length=1;
                while(st.find(it+ length)!=st.end()){
                    length++;
                }
                cnt=max(cnt,length);
            }
        }
        return cnt;
        



    }
};
