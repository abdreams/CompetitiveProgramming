#include<iostream>
 using namespace std;

 int main()
 {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
     int n,i;
     cin>>n;

     int a[n];

     for ( i=0; i<n; i++) cin>>a[i];

     int min,max,min_index,max_index;

     min=a[0];
     min_index=0;
     max=a[0];
     max_index=0;

     for ( i=0; i<n; i++)
     {
         if ( min>=a[i])
         {
             min=a[i];
             min_index=i;
         }
         if ( max<a[i])
         {
             max=a[i];
             max_index=i;
         }

     }

     if ( min_index<max_index)
     {

          min_index=(n-1)-min_index;
          cout<<(min_index+max_index-1)<<endl;
     }
     else
     {

      min_index=(n-1)-min_index;
     cout<<(min_index+max_index)<<endl;
     }
 }