class Solution {
public:
    int guessNumber(int n) {
        long long left = 1, right = n;

        while(left <= right){
            long long mid = left + (right - left) / 2;
            int g = guess(mid);

            if(g == 0) return mid;
            else if(g == -1) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
