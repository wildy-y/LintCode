#include <iostream>
using namespace std;
class theQueen{
public:
    theQueen(int a){
        this->N=a;
        res= new int *[a+1];
        for(int i=0;i<a+1;++i){
            res[i]=new int[a+1];
        }
    }
    ~theQueen(){
        free(res);
    }
    void solve(){
        backTrack(1);
    }
private:
    int N;
    int **res;
    bool isLegal(int i,int j){
        for(int p=1;p<=i-1;p++){
            int q=res[p][0];
            if(q==j||abs(p-i)==abs(q-j)) {
                return false;
            }
        }
        return true;
    }
    void backTrack(int t){
        static int NUM=1;
        if(t>N){
            cout<<"the solution"<<" "<<NUM<<endl;
            NUM++;
            for(int i=1;i<=N;++i){
                for(int j=1;j<=N;++j){
                    res[i][j]==1?cout<<"O"<<" " :cout <<"+"<<" ";
                }
                cout<<endl;
            }
        }
        else{
            for(int j=1;j<=N;j++){
                res[t][j]=1;
                if(isLegal(t,j)){
                    res[t][0]=j;//the legal place of line t
                    backTrack(t+1);
                }
                res[t][j]=0;
            }

        }
    }
};
int main(){
    theQueen test(8);
    test.solve();
}