struct Node {
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};


class LRUCache {
public:

    int cache_capacity;    
    unordered_map<int, Node*>cache;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cache_capacity=capacity;        
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        tail->prev=head;
        head->next=tail;
        
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()){
            Node* curr=cache[key];
            int ans=curr->value;

            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;

            curr->next=head->next;
            head->next->prev=curr;
            head->next=curr;
            curr->prev=head;

            return ans;
            
        }
        else{
            return -1;
        }
    }

    void updateTheHead(Node* newNode){

        

        newNode->next=head->next;
        head->next->prev=newNode;
        head->next=newNode;
        newNode->prev=head;
    }
    
    void put(int key, int value) {

        if(cache.find(key)!=cache.end()){
            cache[key]->value=value;
            Node* takeToHead=cache[key];

            takeToHead->prev->next=takeToHead->next;
            takeToHead->next->prev=takeToHead->prev;

            updateTheHead(takeToHead);
        }

        else{

            Node* newNode=new Node(key, value);

        if(cache.size()==cache_capacity){
            Node* nodeToDelete=tail->prev;

            cache.erase(nodeToDelete->key);

            nodeToDelete->prev->next=tail;
            tail->prev=nodeToDelete->prev;

            nodeToDelete->next=nullptr;
            nodeToDelete->prev=nullptr;
            delete nodeToDelete;
        }

        cache[key]=newNode;


        updateTheHead(newNode);



        }

        


    }
};
