class Solution {
public:
    int guessNumber(int num) {
        long long l = 1, r = num;

        while(l <= r){
            long long mid = l + (r - l) / 2;
            int g = guess(mid);

            if(g == 0) return mid;
            else if(g == -1) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};
