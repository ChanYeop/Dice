#include <iostream>
#include <vector>
using namespace std;

int Dice[6] = { 0 };
int map[20][20];

int main() {
	int N, M;
	int x, y, K;
	int value;

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> value;
			map[i][j] = value;
		}
	}

	int directx = x;
	int directy = y;
	int direct;
	int origin;
	for (int q = 0; q < K; q++) {
		bool ch = false;
		origin = Dice[1];
		cin >> direct;
		if (direct == 1 && directy + 1 < M) {
			Dice[1] = Dice[4];
			Dice[4] = Dice[6];
			Dice[6] = Dice[3];
			Dice[3] = origin;
			directy += 1;
		}
		else if (direct == 2 && directy - 1 >= 0) {
			Dice[1] = Dice[3];
			Dice[3] = Dice[6];
			Dice[6] = Dice[4];
			Dice[4] = origin;;
			directy -= 1;
		}
		else if (direct == 3 && directx - 1 >= 0) {
			Dice[1] = Dice[5];
			Dice[5] = Dice[6];
			Dice[6] = Dice[2];
			Dice[2] = origin;
			directx -= 1;
		}
		else if (direct == 4 && directx + 1 < N) {
			Dice[1] = Dice[2];
			Dice[2] = Dice[6];
			Dice[6] = Dice[5];
			Dice[5] = origin;
			directx += 1;
		}
		else
			ch = true;

		if (ch == false) {
			if (map[directx][directy] == 0)
				map[directx][directy] = Dice[6];
			else {
				Dice[6] = map[directx][directy];
				map[directx][directy] = 0;
			}
			cout << Dice[1] << endl;
		}
	}
	return 0;
}