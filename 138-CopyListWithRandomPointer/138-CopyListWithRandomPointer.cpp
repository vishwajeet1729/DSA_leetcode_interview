// Last updated: 1/17/2026, 12:33:56 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
              
              Node *lol=head;

              map<Node*,Node*>m;
              while(lol){
                 Node *n1=new Node(lol->val);
                 m[lol]=n1;
                 lol=lol->next;

              }
    lol=head;
           while(lol){
               m[lol]->next=m[lol->next];
               m[lol]->random=m[lol->random];
               lol=lol->next;

           }



              return m[head];

    }
};