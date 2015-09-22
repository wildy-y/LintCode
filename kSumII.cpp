#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;
int sovle(int r,int x,int y,int x1,int y1,int r){
    int dis=(x-x1)*(x-x1)+(y-y1)*(y-y1);
    int stepSq=dis/4/r/r;
    return sqrt(dis/stepSq);
}
int main(){
    cout<<sovle(2,0,0,0,4)<<endl;
    return 0;
}
