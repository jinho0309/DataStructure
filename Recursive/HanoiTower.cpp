#include <iostream>

using namespace std;

void hanoiTower(int num, char from, char by, char to) {
	if (num == 1)
		cout << "����1�� " << from << "���� " << to << "�� �̵�" << endl;
	else {
		hanoiTower(num - 1, from, to, by);//n-1�� ���� A���� B��
		cout << "����"<<num<<"�� " << from << "���� " << to << "�� �̵�" << endl;//�ǹؿ� ���̸� A���� C��
		hanoiTower(num - 1, by, from, to);//n-1�� B���� C��
		
	}
}
int main(void) {
	
	hanoiTower(3,  'A', 'B', 'C');
	while (1);
	return 0;
}