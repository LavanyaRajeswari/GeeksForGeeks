class Solution {
public:
    int maxWater(vector<int>& height) {
    int n=height.size();
    if(n==0 and n==1)return 0;
    int i=0;
    int j=n-1;
    int max=0;
    while(i<j){
        int x=min(height[i],height[j]);
        int temp=x*(j-i);
        if(temp>max){
            max=temp;
        }
        if(height[i]>height[j]){
            j--;
        }
        else{
            i++;
        }
    }
    return max;
    }
};