#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


void out(string);

int main()
{
	string org, quo, res; //org:原始输入 quo：每轮的商 res：余数
	int rest;
	bool flag = true;


	org = "100000000000";
	
	while (flag)
	{

		flag = false;
		rest = 0;
		for (auto c : org) {    
			if (rest) {        ////判断余数0或者1，如果是1就乘10加下一位
				quo.push_back((rest * 10 + (c - '0')) / 2 + '0');    
				rest = (rest * 10 + (c - '0')) % 2;
			}
			else {
				quo.push_back((c - '0') / 2 + '0');
				rest = (c - '0') % 2;
			}
		}
		res.push_back(rest + '0');

		org.clear();
		for (auto i = 0; i < quo.size(); i++) {  //把quo复制到org   
			if (quo[i] != '0') {
				for (auto j = i; j < quo.size(); j++) {
					org.push_back(quo[j]);
				}
				if(!flag)
					flag = true;     //根据商是否为0判断是否还需要继续
				break;
			}
		}
		quo.clear();

	}

	out(res);

}


void out(string s) {       //倒叙输出
	auto rbegin = s.rbegin();
	auto rend = s.rend();
	while (rbegin != rend)
	{
		cout << *rbegin++;
	}
}