//LC fastest with splice
class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    int capacity;
    LRUCache(int capacity):capacity(capacity) {

    }

    int get(int key) {
        auto it=m.find(key);
        if (it==m.end()) return -1;
        l.splice(l.begin(),l,it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it=m.find(key);
        if (it==m.end()){
            if (m.size()==capacity){
                m.erase(l.back().first);
                l.pop_back();
            }
            l.push_front({key,value});
            m[key]=l.begin();
        }else{
            l.splice(l.begin(),l,it->second);
            it->second->second=value;
        }
    }
};


//Custom LList sol, naive af
/*class Node{
public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int k, int v){
        key=k;
        val=v;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
private:
    int cap, items;
    Node* head;
    Node* tail;

    void makeHead(Node* ptr, Node* preptr){
        if(ptr->next!=NULL)
            ptr->next->prev=preptr;
        else
            tail=preptr;
        preptr->next=ptr->next;
        ptr->prev=NULL;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
    }

    void findNode(Node* &ptr, Node* &preptr, int key){
        while(ptr!=NULL){
            if(ptr->key==key){
                return;
            }
            preptr=ptr;
            ptr=ptr->next;
        }
    }

public:
    LRUCache(int capacity) {
        cap=capacity;
        items=0;
        head=NULL;
        tail=NULL;
    }

    int get(int key) {
        Node *ptr=head;
        Node *preptr=NULL;
        findNode(ptr, preptr, key);
        if(ptr==NULL){
            return -1;
        }
        if(preptr!=NULL)
            makeHead(ptr, preptr);
        return ptr->val;
    }

    void put(int key, int value) {
        Node* ptr=head;
        Node* preptr=NULL;
        findNode(ptr,preptr, key);
        if(ptr==NULL){
            ptr=new Node(key,value);
            if(head==NULL){
                head=ptr;
                tail=ptr;
            }
            else{
                head->prev=ptr;
                ptr->next=head;
                head=ptr;
            }
            items++;
            if(items>cap){
                ptr=tail;
                tail=tail->prev;
                tail->next=NULL;
                //free(ptr);
                items--;
            }
        }
        else{
            ptr->val=value;
            if(preptr!=NULL)
                makeHead(ptr, preptr);
        }
    }
};
*/

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
