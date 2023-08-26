    int ans=0;

    for(int j=3;j<=n;j++){
        int count=0;
            for(int i=0;primes[i]*primes[i]<=j;i++){
                if(j%primes[i]==0) count++;
            }
        if(count==2) ans++;
    }

    cout<<ans<<endl;