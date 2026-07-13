class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> cnt1;
        for(int i=0;i<s1.size();i++){
            cnt1[s1[i]]++;
        }
        unordered_map<char,int> count;
        int res=0;
        int left=0;
        for(int r=0;r<s2.size();r++){
            count[s2[r]]++;
            while(count[s2[r]]>cnt1[s2[r]] && left<=r){
                count[s2[left]]--;
                left++;
            }
            res= max(res,r-left+1);  
        }
        cout << res<< endl;
        if(res==s1.size()){
            return 1;
        }
        return 0;
    }
};
