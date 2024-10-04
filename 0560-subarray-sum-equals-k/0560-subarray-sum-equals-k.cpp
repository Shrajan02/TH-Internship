class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, preSum = 0;
        int n = nums.size();
        map<int, int> hash; 

        hash[0] = 1; // considering addition with singleton subarrays

        for (int i = 0; i < n; i++) {
            preSum += nums[i]; 

            // Check if (preSum - k) exists in hashmap
            int rem = preSum - k;
            if (hash.find(rem) != hash.end()) {
                count += hash[rem]; 
            }

            hash[preSum]++; // Updating hashmap
        }

        return count;
    }
};