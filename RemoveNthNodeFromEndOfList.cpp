ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
   if(head==nullptr or n<=0){
        return head;
   }
   ListNode *pre=head,*tail=head;
   while(n>0&&tail->next!=nullptr){
        tail=tail->next;
        n--;
   }
   if(n>1){
        return nullptr;//n超出链表长度
   }
  
   if(n==1&&tail->next==nullptr){
        return head->next;              //倒数第n个恰好为head
   }
   
   //tail为正数第n+1个
   //同时往前走，则tail走到头，pre就为倒数第n+1个，即删除节点的前一个
   while(tail->next!=nullptr){
       tail=tail->next;
       pre=pre->next; 
   }
   pre->next=pre->next->next;
   return head;
}
