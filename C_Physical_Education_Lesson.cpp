        sort(a.begin(),a.end());
        int count;
        for (int j = 0; j < n; j++)
        {
            count = 0;
            map<int,int> mpp;
            for (int i = 0; i < n; i++)
            {
                if (i!=j)
                {
                    
                    mpp[abs(a[j]-a[i])]++;
                    if (abs(a[j]-a[i])<n and mpp.find(diff)!=mpp.end())
                    {
                        count++;
                    }
                }
            }
        }
        cout << count+1 << endl;
    } 