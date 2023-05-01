#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class BranchFinances {  // базовый класс
public:
	BranchFinances() {}  // конструктор и деструктор по умолчанию
	~BranchFinances() {}

	const double rent = 50;   // константные переменные для расчетов
	const double payment = 35;
	const double aurors = 15;
	const double percent = 1.07;
	const double sum_with_percent = 270;
	double allRent;   // прочие переменные для расчетов
	double allCosts;
	double revenue;
	double NetProfit;

	void RoomRental() {   // метод аренда помещения
		if (revenue < sum_with_percent) {   // условие (выручка меньше 270 или нет)
			allRent = rent;  // да
		}
		else {
			allRent = rent + ((revenue - sum_with_percent) * percent);  // нет
		}
	}
	void allCostsCalculation() {   // метод расчет всех расходов
		allCosts = allRent + payment + aurors;
	}
	void out_allCosts() {  // метод вывод всех расходов
		cout << allCosts;
	}
	void RevenueCalculation() {   // метод расчет выручки с ГПСЧ
		srand(time(nullptr));
		revenue = rand() % 251 + 250;
	}
	double NetProfit1() {   // метод расчет чистой прибыли 
		RevenueCalculation();  // проще сразу в методе обратиться к другим необходимым методам
		RoomRental();
		allCostsCalculation();
		NetProfit = revenue - allCosts;  // собственно сам расчет
		return NetProfit;
	}
};

class NewBranch : public BranchFinances {  // класс - наследник 
public:
	NewBranch(string name) {  // конструктор от вводимого значения
		Name = name;
	}
	~NewBranch() {}  // деструктор

	string GetName() {  // геттер имени
		return Name;
	}

private:
	string Name;  // приватная строковая переменная
};

int main() {  // выполнение программы
	string name;
	cout << "Enter name your shop: ";
	cin >> name;
	NewBranch n(name);  // объект типа NewBranch
	cout << n.GetName() << "`s shop" << endl;
	cout << "==================\n";
	n.NetProfit1();    // выполнение всех расчетов
	cout << "Revenue: " << n.revenue << endl;
	cout << "All costs: " << n.allCosts << endl;
	cout << "Profit: " << n.NetProfit1() << endl;

	return 0;
}