Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []

  ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<>>pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            while(lists[i]!=NULL){
                pq.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        ListNode *current = new ListNode(0);
        ListNode *dummy = current;
        while(!pq.empty()){
            current->next=new ListNode(pq.top());
            pq.pop();
            current=current->next;
        }
        return dummy->next;
    }
