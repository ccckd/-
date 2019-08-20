#include<vector>
#include<iostream>
using namespace std;

class MinStack {
public:
	vector<int>stack;
	vector<int>min;

	MinStack() {

	}

	void push(int x) {
		stack.push_back(x);

		
		min.push_back(x);
		for (int i = min.size() - 2; i >= 0; i--) {
			if (x < min[i]) {
				min[i + 1] = min[i];
			}
			else {
				min[i + 1] = x;
				return;
			}
		}

		min[0] = x;


	}

	void pop() {
		int del = *(stack.end() - 1);
		stack.pop_back();

		for (auto i = 0; i < min.size(); i++) {
			if (min[i] == del) {
				min.erase(min.begin() + i);
				break;
			}
		}
	}

	int top() {
		if (stack.size() != 0)
			return stack[stack.size() - 1];
		return 0;
	}

	int getMin() const{
		return min[0];
	}
};



int main() {
	MinStack obj;
	obj.push(-2);
	obj.push(0);
	obj.push(-3);
	obj.getMin();   
	obj.pop();
	obj.top();      
	obj.getMin();   


	return 0;
}


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */