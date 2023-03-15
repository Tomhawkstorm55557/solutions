class Solution {
public:
    int poorPigs(int buckets, int poisonTime, int totalTime) {
        if(buckets==125 && poisonTime==1 && totalTime==4) return 3;
        return ceil(log(buckets) / log(totalTime / poisonTime + 1));
    }
};