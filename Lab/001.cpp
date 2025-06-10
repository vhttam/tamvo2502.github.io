#include <iostream>
#define MAX 20000
using namespace std;

int sumtwo(int nums[MAX],int target,int n){
    int sum;
    int a[2];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++){
            sum=nums[i]+nums[j];
            if (sum==target){
                cout<<"["<<i<<", "<<j<<"]";
            }
        }
    }
    return 0;
}

int main(){
    int nums[MAX];
    int target;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>target;
    sumtwo(nums,target,n);
}
