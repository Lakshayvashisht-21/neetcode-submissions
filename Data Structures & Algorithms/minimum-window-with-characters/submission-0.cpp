class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count1;
        unordered_map<char,int> window;
        int reslen=INT_MAX;
        for(int i=0;i<t.size();i++){
            count1[t[i]]++;
        }
        int l=0;
        pair<int,int> res={-1,-1};
        int have=0;
        int need=count1.size();
        for(int r=0;r<s.size();r++){
            char c= s[r];
            window[c]++;
            if(count1[c] && window[c]==count1[c]){
                have++;
            }
            while(have==need){
                if(r-l+1<reslen){
                    reslen=r-l+1;
                    res={l,r};
                }
                window[s[l]]--;
                if(count1.count(s[l]) && window[s[l]] < count1[s[l]]){
                    have--;
                }
                l++;
            }
        }
        if(reslen==INT_MAX){
            return "";
        }
        string ans="";
        for(int i=res.first;i<=res.second;i++){
            ans+=s[i];
        }
        return ans;
        

    }
};
