#include "pch.h"
#include <iostream>
#include <unordered_map>
#include <memory>
using namespace std;



class LRUCache {
public:
	LRUCache(int capacity):capacity(capacity), len(0) {

	}

	int get(int key) {
		if (dict.count(key)) {
			auto pn = dict[key];
			if(pn == tail)
				return pn->val;
			else if (pn == head) {
				head = pn->pre;
				pn->pre->next = nullptr;
				pn->pre = nullptr;
				pn->next = tail;
				tail->pre = pn;
				tail = pn;
				return pn->val;
			}
			pn->next->pre = pn->pre;
			pn->pre->next = pn->next;
			pn->next = tail;
			pn->pre = nullptr;
			tail = pn;
			return pn->val;

		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {

		node *p = new node(key, value);
		
		if (dict.count(key)) {
			auto pn = dict[key];
			pn->val = value;
			return;
		}
		if (len == capacity) {
			dict.erase(head->val);
			auto del = head;
			head = head->pre;
			head->next = nullptr;
			len--;
			delete del;
		}
		if (tail == nullptr) {
			tail = p;
			head = tail;
			len++;
			dict[key] = tail;
			return;
		}
		p->next = tail;
		tail->pre = p;
		tail = p;
		dict[key] = tail;
		len++;
	}

private:
	struct node
	{
		int key;
		int val;
		node *next;
		node *pre;
		node(int key, int val) :key(key), val(val), next(nullptr), pre(nullptr) {};
	};
	int len;
	node *head;
	node *tail;
	unordered_map<int, node*> dict;
	int capacity;
};







int main()
{
	LRUCache cache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1);       // 返回  1
	cache.put(3, 3);    // 该操作会使得密钥 2 作废
	cout << cache.get(2);       // 返回 -1 (未找到)
	cache.put(4, 4);    // 该操作会使得密钥 1 作废
	cout << cache.get(1);       // 返回 -1 (未找到)
	cout << cache.get(3);       // 返回  3
	cout << cache.get(4);       // 返回  4
    
}

