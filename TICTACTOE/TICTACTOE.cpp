#include <string>
#include <iostream>
#include <array>
using namespace std;

struct 	array<array<int, 3>, 3> ttt{ {
		{0,0,0},
		{0,0,0},
		{0,0,0}
		} };

void eingabe(int x, int y, int z) {
	system("cls");
	if (ttt[x][y] == 0) {
		ttt[x][y] = z;
		if (ttt[0][0] != 0 && ttt[0][1] != 0 && ttt[0][2] != 0 &&
			ttt[1][0] != 0 && ttt[1][1] != 0 && ttt[1][2] != 0 &&
			ttt[2][0] != 0 && ttt[2][1] != 0 && ttt[2][2] != 0)
		{
			cout << "Niemand hat Gewonnen!" << endl;
			system("pause");
			exit(0);
		}
		for (int k = 0; k <= 2; k++) {
			if ((ttt[k][0] == z && ttt[k][1] == z && ttt[k][2] == z) ||
				(ttt[0][k] == z && ttt[1][k] == z && ttt[2][k] == z) ||
				(ttt[0][0] == z && ttt[1][1] == z && ttt[2][2] == z) ||
				(ttt[0][2] == z && ttt[1][1] == z && ttt[2][0] == z)) {
				cout << "Player " << z << " hat gewonnen!" << endl;
				system("pause");
				exit(0);
			}
		}
	}
	else {
		cout << "An dieser Poistion ist schon was" << endl;
	}

	cout << "  1|2|3" << endl;
	for (int a = 0; a < ttt[0].size(); a++) {
		cout << a + 1 << "|";
		for (int b = 0; b < ttt[1].size(); b++) {
			if (b < ttt[1].size() - 1) {
				cout << ttt[a][b] << "|";
			}
			else {
				cout << ttt[a][b];
			}
		}
		cout << endl;
	}

}
void start() {
	cout << "   1|2|3" << endl;
	for (int a = 0; a < ttt[0].size(); a++) {
		cout << a + 1 << "| ";
		for (int b = 0; b < ttt[1].size(); b++) {
			if (b < ttt[1].size() - 1) {
				cout << ttt[a][b] << "|";
			}
			else {
				cout << ttt[a][b];
			}
		}
		cout << endl;
	}
}


int main(int argc, const char* argv[]) {
	start();
	int win = 0;
	int player = 1;
	int vk = 0;
	int hz = 0;
	while (win == 0)
	{
		while (player == 1)
		{
			cout << "Player " << player << endl;
			cout << "Horizontale Reihe: ";
			cin >> vk;
			cout << "Vertikale Reihe: ";
			cin >> hz;
			if ((vk > 0 && vk < 4) && (hz > 0 && hz < 4))
			{
				eingabe(vk - 1, hz - 1, player);
				if (ttt[vk - 1][hz - 1] == 1) {
					player++;
				}
			}
			else {
				start();
			}
		}
		while (player == 2)
		{
			cout << "Player " << player << endl;
			cout << "Horizontale Reihe: ";
			cin >> vk;
			cout << "Vertikale Reihe: ";
			cin >> hz;
			if ((vk > 0 && vk < 4) && (hz > 0 && hz < 4)) {
				eingabe(vk - 1, hz - 1, player);
				if (ttt[vk - 1][hz - 1] == 2) {
					player--;
				}
			}
			else {
				start();
			}
		}
	}
	return 0;
}