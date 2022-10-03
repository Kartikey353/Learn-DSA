/*  https://leetcode.com/problems/binary-search/  */


  // Binary search can be used when we have a search space i.e, our answers are within limited range.
  // Binary search can be used on sorted array or when in question we are able to make a monotonic function.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;int hi=nums.size()-1;
        // lo->for lower limit and hi->for higher limit.
      
        while(hi-lo>1){
          //find middle of limit.
          int mid=(hi+lo)/2;    
          // if middle element matched then return  the index.
          if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
            //we will do hi=mid-1 not hi=mid because we have condition nums[mid]>target means at this instance mid element can not be our answer. 
              hi=mid-1;
            }
            else{
               lo=mid+1;
            }
        }
      
        if(nums[lo]==target){return lo;}
        else if(nums[hi]==target){return hi;}
        return -1;
    }
};

//Time complexity-O(logn)
//Space complexity-O(1)
