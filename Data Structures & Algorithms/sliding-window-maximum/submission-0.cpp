class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> min_heap;
        int l=0;
        unordered_map<int,int> mp;
        vector<int> res;
        int r=0;
        while(r<k){
            mp[nums[r]]++;
            min_heap.push(nums[r]);
            r++;
        }
        res.push_back(min_heap.top());
        
        for(int r=k;r<nums.size();r++){
            mp[nums[l]]--;
            l++;
            mp[nums[r]]++;
            min_heap.push(nums[r]);
            while(mp[min_heap.top()]==0){
                min_heap.pop();
            }
            res.push_back(min_heap.top());
        }
        return res;
    }
};
