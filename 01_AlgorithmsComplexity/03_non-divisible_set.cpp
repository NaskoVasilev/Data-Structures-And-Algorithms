int nonDivisibleSubset(int k, vector<int> s) {
    int max=0;
    vector<int> mods(k);
    for(int i=0;i<s.size();i++)
    {
        mods[s[i]%k]++;
    }

    for(int i=1; i<k/2 + k%2 ; i++)
    {
        if(mods[i]>mods[k-i])
        {
            max +=mods[i];
        }
        else
        {
            max +=mods[k-i];
        }
    }
    if(k%2==0)
    {
        if(mods[k/2]>0) max++;
    }
    if(mods[0]>0) max++;

    return max;
}