class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long maxWater(vector<int>&arr){
        int n = arr.size();
        int i=0,j=n-1;
        int imax=0,jmax=0;
        long long ans=0;
        while(i<=j){
            if(arr[i]<arr[j]){
                if(arr[i]>imax){
                    imax=arr[i];
                }
                else{
                   ans+=imax-arr[i]; 
                }
                i++;
            }
            else{
                if(arr[j]>jmax){
                    jmax=arr[j];
                }
                else{
                    ans+=jmax-arr[j];
                }
                j--;
            }
        }
        return ans;
    }
};
