#include <iostream>

using namespace std;

void hanoiTower(int num, char from, char by, char to) {
	if (num == 1)
		cout << "원반1을 " << from << "에서 " << to << "로 이동" << endl;
	else {
		hanoiTower(num - 1, from, to, by);//n-1를 개를 A에서 B로
		cout << "원반"<<num<<"을 " << from << "에서 " << to << "로 이동" << endl;//맨밑에 아이를 A에서 C로
		hanoiTower(num - 1, by, from, to);//n-1을 B에서 C로
		
	}
}
int main(void) {
	
	hanoiTower(3,  'A', 'B', 'C');
	while (1);
	return 0;
}