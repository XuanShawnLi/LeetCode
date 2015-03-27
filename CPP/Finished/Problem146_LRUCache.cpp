/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
#include<iostream>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;

struct Node{
	int val;
	int key;
	Node* next;
	Node* previous;
	Node(int keyvalue,int value):key(keyvalue),val(value),next(NULL),previous(NULL){};
};

class LRUCache{
public:
	int nsize,capacity;
	int OneKey,OneValue;
	Node *head,*tail;
	unordered_map<int,Node*> dict;
    LRUCache(int capacity) {
        this->capacity=capacity;nsize=0;
		tail=NULL;head=NULL;
		OneKey=0xfffffff;OneValue=0xfffffff;
    }

	void Update(Node* current){
		if(current==tail){return;}//if I am the last element, no need to update it
		//step 1:take care of the next pointer of its parent
		Node* p=current->previous;Node* c=current->next;
		if(p){p->next=c;}
		else{head=c;}
		//step 2:take care of child's previous pointer
		if(c){c->previous=p;}
		//step 3:move it to tail, and current!=tail
		tail->next=current;current->previous=tail;
		tail=current;current->next=NULL;
	}
    
    int get(int key) {
		if(capacity==0){return -1;}
		if(capacity==1){
			if(nsize==0 or key!=OneKey){return -1;}
			else{return OneValue;}
		}
		if(dict.find(key)==dict.end()){return -1;}
		Update(dict[key]);
		return dict[key]->val; 
    }
    
    void set(int key, int value) {
		if(capacity==0){return;}
		if(capacity==1){OneKey=key;OneValue=value;nsize=1;return;}
        if(dict.find(key)==dict.end()){
			if(head==NULL){//empty
				head=tail=new Node(key,value);
				dict.insert(make_pair(key,head));
				nsize++;
			}
			else{
				Node* tmp=new Node(key,value);
                tmp->previous=tail;tail->next=tmp;tail=tmp;
                dict.insert(make_pair(key,tail));
				if(nsize==capacity){//add new elements and delete tail
					dict.erase(head->key);
					tmp=head->next;delete head;head=tmp;head->previous=NULL;
				}
				else{
					nsize++;
				}
			}
		}
		else{
			dict[key]->val=value;
			Update(dict[key]);
		}
    }
};

int main(){
		LRUCache L1(0);
		L1.set(1,1);
		cout<<L1.get(1)<<"==-1"<<endl;

		LRUCache L2(1);
		L2.set(1,1);
		cout<<L2.get(1)<<"==1"<<endl;
		L2.set(1,2);
		cout<<L2.get(1)<<"==2"<<endl;
		L2.set(2,2);
		cout<<L2.get(1)<<"==-1"<<endl;
		cout<<L2.get(2)<<"==2"<<endl;

		LRUCache L3(2);
		L3.set(1,1);L3.set(2,2);
		cout<<L3.get(1)<<"==1"<<endl;
		cout<<L3.get(2)<<"==2"<<endl;
		cout<<L3.get(3)<<"==-1"<<endl;
		L3.set(3,3);
		cout<<L3.get(1)<<"==-1"<<endl;
        cout<<L3.get(2)<<"==2"<<endl;
        cout<<L3.get(3)<<"==3"<<endl;
	
		LRUCache L4(2);
		L4.set(2,1);L4.set(1,1);
		cout<<L4.get(2)<<endl;
		//cout<<L4.head->key<<" "<<L4.tail->key<<endl;exit(1);
		L4.set(4,1);
		cout<<L4.get(1)<<endl;
		cout<<L4.get(2)<<endl;
		L4.set(5,1);
}

