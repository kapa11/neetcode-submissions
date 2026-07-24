class Solution {
public:

    int totalTime(vector<int>& piles, int speed){
        int timeTaken = 0;
        for(int &i : piles){
            if(i%speed==0) timeTaken += i/speed;
            else timeTaken += i/speed + 1;
        }
        return timeTaken;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r = *max_element(piles.begin(), piles.end());
        int minSpeed;

        while(l<r){
            int mid = r + (l-r)/2;
            if(totalTime(piles, mid)>h){
                l = mid+1;
            }
            else{
                minSpeed = mid;
                r = mid-1;
            }
        }
        return minSpeed;
    }
};
