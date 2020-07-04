#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int res=0;
        ListNode *head=nullptr, *curr_ptr=nullptr;
        while(l1!=nullptr || l2!=nullptr || res>0){
            if(l1!=nullptr){
                res+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                res+=l2->val;
                l2=l2->next;
            }
            if(head==nullptr){
                head=new ListNode(res%10);
                curr_ptr=head;
            }
            else{
                curr_ptr->next=new ListNode(res%10);
                curr_ptr=curr_ptr->next;
            }
            res/=10;
        }
        return head;
    }
};

int main(){
	// Solution solve;
	// int input;
	// cin>>input;
	return 0;
}
