/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
            return x;
        //long minflag = x, ans = 0, flag = 0;

        //二分查找
        long left = 0, right = x;
        while(right - left > 1){
            long num = (right + left) / 2;
            if(num * num < x)
                left = num;
            else if(num*num>x)
                right = num;
            else
                return num;
        }
        if(right * right < x)
            return right;
        return left;

        /*普通遍历
        for (long i = 0; i <= x / 2;i++){
            flag = x - i * i;
            if (flag<0)
                break;
            else if (flag < minflag){
                minflag = flag;
                ans = i;
            }
            }
            return ans;
            
        */
    }
};
// @lc code=end

