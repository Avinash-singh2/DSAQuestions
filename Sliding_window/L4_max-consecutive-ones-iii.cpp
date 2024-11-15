class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0; int r= 0; int n =nums.size();
        int maxlen=0;
        int zeros=0;

        while(r<n){
            if(nums[r]==0) zeros++;
            if(zeros>k){
                 if(nums[l]==0) zeros--;
                l++;
            }
            if(zeros<=k){
                int len = r-l+1;
                maxlen= max(maxlen,len);
            }

            r++;
        }
        return maxlen;
    }
};

// optimal: 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0; int r =0; int zeroes =0; int maxlen =0;
        int n = nums.size();
        while(r<n){
            if(nums[r]==0) zeroes++;

            while(zeroes > k){
                if(nums[l]== 0) zeroes--;
                l++;
            }
            if(zeroes<=k){
                int len =r-l+1;
                maxlen = max(maxlen,len);
                r++;
            }
        }
        return maxlen;
    }
};

// in optimal to remove while and replace it with if 