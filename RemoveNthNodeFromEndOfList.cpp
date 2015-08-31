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
        return nullptr;
   }
   if(n==1&&tail->next==nullptr){
        return head->next;
   }
   while(tail->next!=nullptr){
       tail=tail->next;
       pre=pre->next; 
   }
   pre->next=pre->next->next;
   return head;
}