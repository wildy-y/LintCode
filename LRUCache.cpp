#include <iostream>
#include <vector>
#include <map>

using namespace std;
class LRUCache{
private:
    class node{
    public:
        int key;
        int value;
        node *pre;
        node *next;
        node (int k,int v):key(k),value(v),pre(nullptr),next(nullptr){};
    };
    void putToHead(node *cur){
        cur->next= head->next;
        cur->pre=head;
        cur->next->pre=cur;
        head->next =cur;
    }
public:
    // @param capacity, an integer
    // @param key, an integer
    // @param value, an integer
    // @return nothin
    map<int,node *> mp;
    node *head;
    node *tail;
    int size;
    int cap;
    LRUCache(int capacity) {
        // write your code here
        if(capacity<1) return;
        head = new node(0,0);
        tail = new node(0,0);
        head->next=tail;
        tail->pre=head;
        size = 0;
        cap= capacity;
    }

    // @return an integer
    int get(int key) {
        // write your code here
        map<int,node *>::iterator it=mp.find(key);
        if(it==mp.end()){
            return -1;
        }
        node *cur=(*it).second;
        cur->pre->next=cur->next;
        cur->next->pre=cur->pre;
        putToHead(cur);
        return cur->value;
    }


    void set(int key, int value) {
        // write your code here
        if(cap<1) return;
        map<int ,node *>::iterator it = mp.find(key);
        if(it!=mp.end()){
            node *cur=(*it).second;
            cur->pre->next=cur->next;
            cur->next->pre=cur->pre;
            cur->value = value;
            putToHead(cur);
        }
        else{
            node *tmp =new node(key,value);
            putToHead(tmp);
            mp[key]=tmp;
            if(size<cap){
                size++;
            }
            else{
                node *deltmp = tail->pre;
                tail->pre= deltmp->pre;
                deltmp->pre->next=tail;
                it = mp.find((deltmp->key));
                mp.erase(it);
                delete deltmp;
            }
        }
    }

};


int main() {
    //cout << "Hello, World!" << endl;
    LRUCache test(2);
    test.set(2,1);
    test.set(1,1);
    cout <<test.get(2)<<endl;
    test.set(4,1);
    cout <<test.get(1)<<endl;
    cout <<test.get(2)<<endl;
    return 0;
}