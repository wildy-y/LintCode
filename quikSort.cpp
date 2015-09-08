#include <iostream>
void quikSort(int a[],int first,int end){
    int i=first,j=end;
    int temp=a[first];
    while(i<j){
        while(i<j && a[j]>=temp){
            j--;
        }
        while(i<j && a[i]<=temp){
            i++;
        } 
        std::swap(a[i],a[j]);
    }
    std::swap(a[first],a[i]);

    if(first<i-1){
        quikSort(a,first,i-1);
    }
    if(end>i+1){
        quikSort(a,i+1,end);
    }
}
int  main(int argc, char const *argv[])
{
    /* code */
    int a[9]={1,56,12,53,7,-9.100,20,2};
    quikSort(a,0,8);
    for (int i = 0; i < 9; ++i)
    {
        /* code */
        std::cout<<a[i]<<" ";
    }
    return 0;
}