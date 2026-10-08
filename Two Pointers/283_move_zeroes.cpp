class Solution {
public:                              
  void moveZeroes(vector<int>& nums) {                    
      for (int j = 0, cur = 0; cur < nums.size(); cur++) {
          if (nums[cur] != 0) {
              swap(nums[j++], nums[cur]);
          }
      }
  }
};
// more easy version is also there but uses more complexity
