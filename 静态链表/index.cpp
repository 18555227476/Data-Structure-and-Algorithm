#include<iostream>
using namespace std;

class node { //节点
	public:
		node() {
			this->value = 0;
			this->pointer = 0;
		};
		int value; //值
		int pointer; //指针
};

class static_list { //静态链表
	public:
		static_list() {
			this->list[0].pointer = 2; //初始化备用数据链表
			this->list[0].value = 10;
			int length = sizeof(this->list) / sizeof(node);
			for (int index = 2; index < length - 1;index++) {
				this->list[index].pointer = index + 1;
			};
		};
		bool push(int value) { //获取数据链表的最后节点
			if (this->list[0].value > 0) {
				int pointer = 1;
				while (this->list[pointer].pointer)
				{
					pointer = this->list[pointer].pointer;
				};
				this->list[this->list[0].pointer].value = value;
				this->list[pointer].pointer = this->list[0].pointer;
				this->list[0].pointer = this->list[this->list[0].pointer].pointer;
				this->list[this->list[pointer].pointer].pointer = 0;
				-- this->list[0].value;
				++ this->list[1].value;
				return true;
			}
			else
			{
				return false;
			};
		};

		bool pull() { //获取数据链表最后节点的前一个节点
			if (this->list[1].value > 0) {
				int pointer = 1;
				while (this->list[this->list[pointer].pointer].pointer)
				{
					pointer = this->list[pointer].pointer;
				};
				this->list[this->list[pointer].pointer].pointer = this->list[0].pointer;
				this->list[0].pointer = this->list[pointer].pointer;
				this->list[pointer].pointer = 0;
				++ this->list[0].value;
				-- this->list[1].value;
				return true;
			}
			else
			{
				return false;
			}
		};

		bool add(int index,int value) { //获取数据链表要插入位置的前一个节点
			if (index >= 0 && index <= this->list[1].value) {
				int pointer = 1;
				int time = 1;
				while (time <= index)
				{
					pointer = this->list[pointer].pointer;
					time++;
				};
				int temp = this->list[this->list[0].pointer].pointer;
				this->list[this->list[0].pointer].value = value;
				this->list[this->list[0].pointer].pointer = this->list[pointer].pointer;
				this->list[pointer].pointer = this->list[0].pointer;
				this->list[0].pointer = temp;
				-- this->list[0].value;
				++ this->list[1].value;
				return true;
			}
			else
			{
				return false;
			};
		};

		bool del(int index) { //获取数据链表要插入位置的前一个节点
			if (index >= 0 && index < this->list[1].value) {
				int pointer = 1;
				int time = 1;
				while (time <= index)
				{
					pointer = this->list[pointer].pointer;
					time ++;
				};
				int temp = this->list[this->list[pointer].pointer].pointer;
				this->list[this->list[pointer].pointer].pointer = this->list[0].pointer;
				this->list[0].pointer = this->list[pointer].pointer;
				this->list[pointer].pointer = temp;
				++ this->list[0].value;
				-- this->list[1].value;
			}
			else
			{
				return false;
			};
		};

		void read() {
			int pointer = 1;
			while (this->list[pointer].pointer)
			{
				pointer = this->list[pointer].pointer;
				cout << this->list[pointer].value << endl;
			};
		};
		node list[12];
};

int main() {
	static_list list;
	for (int time = 0; time < 11; time++) {
		list.push(time + 1);
	};
	for (int time = 0; time < 11; time++) {
		list.pull();
	};
	list.add(0, 1);
	list.add(0, 10);
	list.add(1, 8);
	list.add(2, 7);
	list.add(3, 6);
	list.add(4, 3);
	list.add(4, 4);
	list.add(6, 2);
	list.add(1, 9);
	list.add(5, 5);
	list.del(1);
	list.del(0);
	list.add(0, 10);
	list.add(1, 9);
	list.read();
	return 0;
};