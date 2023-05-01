#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class BranchFinances {  // ������� �����
public:
	BranchFinances() {}  // ����������� � ���������� �� ���������
	~BranchFinances() {}

	const double rent = 50;   // ����������� ���������� ��� ��������
	const double payment = 35;
	const double aurors = 15;
	const double percent = 1.07;
	const double sum_with_percent = 270;
	double allRent;   // ������ ���������� ��� ��������
	double allCosts;
	double revenue;
	double NetProfit;

	void RoomRental() {   // ����� ������ ���������
		if (revenue < sum_with_percent) {   // ������� (������� ������ 270 ��� ���)
			allRent = rent;  // ��
		}
		else {
			allRent = rent + ((revenue - sum_with_percent) * percent);  // ���
		}
	}
	void allCostsCalculation() {   // ����� ������ ���� ��������
		allCosts = allRent + payment + aurors;
	}
	void out_allCosts() {  // ����� ����� ���� ��������
		cout << allCosts;
	}
	void RevenueCalculation() {   // ����� ������ ������� � ����
		srand(time(nullptr));
		revenue = rand() % 251 + 250;
	}
	double NetProfit1() {   // ����� ������ ������ ������� 
		RevenueCalculation();  // ����� ����� � ������ ���������� � ������ ����������� �������
		RoomRental();
		allCostsCalculation();
		NetProfit = revenue - allCosts;  // ���������� ��� ������
		return NetProfit;
	}
};

class NewBranch : public BranchFinances {  // ����� - ��������� 
public:
	NewBranch(string name) {  // ����������� �� ��������� ��������
		Name = name;
	}
	~NewBranch() {}  // ����������

	string GetName() {  // ������ �����
		return Name;
	}

private:
	string Name;  // ��������� ��������� ����������
};

int main() {  // ���������� ���������
	string name;
	cout << "Enter name your shop: ";
	cin >> name;
	NewBranch n(name);  // ������ ���� NewBranch
	cout << n.GetName() << "`s shop" << endl;
	cout << "==================\n";
	n.NetProfit1();    // ���������� ���� ��������
	cout << "Revenue: " << n.revenue << endl;
	cout << "All costs: " << n.allCosts << endl;
	cout << "Profit: " << n.NetProfit1() << endl;

	return 0;
}