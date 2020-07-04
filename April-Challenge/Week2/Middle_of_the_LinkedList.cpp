#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Single pass
    
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *ptr1=head, *ptr2=head;
        while(ptr2!=NULL && ptr2->next!=NULL){
            ptr1=ptr1->next;
            ptr2=ptr2->next->next;
        }
        return ptr1;
    }

    //Naive
    /*
    ListNode* middleNode(ListNode* head) 
    {
        int lsize=1;
        ListNode * ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
            lsize++;
        }
        lsize=(int)(lsize/2);
        ptr=head;
        while(lsize--){
            ptr=ptr->next;
        }
        return ptr;
    }*/
};

int main()
{
	Solution solve;
//	int inpsize=0;
	int input;
	ListNode *head, *nums;
//	cin>>inpsize;
        cin>>input;
        head=new ListNode(input);
        nums=head;
	while(cin>>input)
        {
		nums->next=new ListNode(input);
                nums=nums->next;
        }
	nums=solve.middleNode(head);
        while(nums!=NULL)
        {

            cout<<nums->val<<"\t";
            nums=nums->next;
        }    
        cout<<endl;
	return 0;
}
