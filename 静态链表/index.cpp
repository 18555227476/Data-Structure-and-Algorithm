#include<iostream>
using namespace std;

class node { //�ڵ�
	public:
		node() {
			this->value = 0;
			this->pointer = 0;
		};
		int value; //ֵ
		int pointer; //ָ��
};

class static_list { //��̬����
	public:
		static_list() {
			this->list[0].pointer = 2; //��ʼ��������������
			this->list[0].value = 10;
			int length = sizeof(this->list) / sizeof(node);
			for (int index = 2; index < length - 1;index++) {
				this->list[index].pointer = index + 1;
			};
		};
		bool push(int value) { //��ȡ������������ڵ�
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

		bool pull() { //��ȡ�����������ڵ��ǰһ���ڵ�
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

		bool add(int index,int value) { //��ȡ��������Ҫ����λ�õ�ǰһ���ڵ�
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

		bool del(int index) { //��ȡ��������Ҫ����λ�õ�ǰһ���ڵ�
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