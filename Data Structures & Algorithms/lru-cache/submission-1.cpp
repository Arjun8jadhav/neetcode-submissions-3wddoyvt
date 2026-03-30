class ListNode{
public:             
    int val,key;
    ListNode* prev;
    ListNode* next;
    
    ListNode(int key,int val){
        this->key=key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};       


class LRUCache {
public:
    unordered_map<int,ListNode*> vk;
    int max_size=0;
    ListNode* start=NULL,*prev=NULL;
    LRUCache(int capacity) {
        max_size=capacity;
        start=new ListNode(0,0);
        prev=new ListNode(0,0);
        start->next=prev;
        prev->prev=start;
    }
    void removeIT(ListNode* temp){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    void addAtEnd(ListNode* temp){
        temp->prev=prev->prev;
        temp->next=prev;
        prev->prev->next=temp;
        prev->prev=temp;
    }

    int get(int key) {
        if(!vk.count(key)){
            return -1;
        }
        ListNode* temp=vk[key];
        removeIT(temp);
        addAtEnd(temp);
        return vk[key]->val;
    }
    
    void put(int key, int value) {
        if(vk.count(key)){
            removeIT(vk[key]);
            addAtEnd(vk[key]);
            vk[key]->val=value;
            return;
        }
        if(vk.size()==max_size){
            ListNode* track=start->next;
            vk.erase(track->key);
            removeIT(track);
            delete track;
            
        }
       
        ListNode* l1=new ListNode(key,value);
        addAtEnd(l1);
        vk[key]=l1;
    
       

    }
};
