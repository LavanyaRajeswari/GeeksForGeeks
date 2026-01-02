class Solution
{
    public:
    void sort012(vector<int>&a)
    {
        int n = a.size();
        map<int,int>mp;
        for(int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        int i = 0;
        for(auto it:mp){
            while(it.second){
                a[i] = it.first;
                i++;
                it.second--;
            }
        }
    }
    
};
