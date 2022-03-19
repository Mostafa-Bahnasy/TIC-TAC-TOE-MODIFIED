#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<Windows.h>
using namespace std;
bool is_win(int size, char ch);
void show_board(int size);
void pline(int n);
void make_board(int size);
void alert();
int get_names();
void show_tilte();
bool get_move(int size, char move);
bool GAME(int size, bool isp1);
bool another_game();
vector<vector< char >>v;
string fplayer, splayer;
int main() {

	while (true) {

		
		bool fpt = 1;
		int si=-1;
		while (true) {
			si=get_names();
			if (si <= 0)
				cout << "please, enter valid num!\n\n";
			else break;
		}
		v.clear();
		 make_board(si);

		while (!GAME(si,fpt)) {

			fpt = !fpt;
		}

		if (!another_game()) { break; }

	}
	system("cls");
	cout << "\t\t\t\tTHANK YOU FOR USING OUR GAME\n";

}


void make_board(int size) {
	for (int i = 0; i < size; i++)
	{
		v.push_back(vector<char>());
		for (int j = 0; j < size; j++) {
			v[i].push_back('-');
		}
	}
}

void show_board(int size) {

	for (int i = 0; i < size; i++) {
		cout << "\t\t\t\t\t";
		for (int j = 0; j < size; j++) {
			if (j == size - 1) {
				cout << v[i][j];
			}
			else {
				cout << v[i][j] << " | ";
			}
		}
		cout << "\n";
	}
}
void pline(int n) {
	 for (int i = 0; i < n; i++) { cout << "_"; }cout << "\n";
}
void alert() {
	cout << "\t\t" << "Seems you choose wrong index or a cell which has already filledn\n\n";
	cout << "\t\t\t\tTry with correct index\n\n"; pline(40);
}
bool get_move(int size,char move) {

	string xi, yi;
	
	cout << "ROW NUM:   "; cin >> xi;
	cout << "COL NUM:   "; cin >> yi;
	cout << "\n";
	bool co = 1;
	for (int i = 0; i < xi.size();i++) {
		if (!isdigit(xi[i]) )co = 0;
	}
	for (int i = 0; i < yi.size();i++) {
		if (!isdigit(yi[i]))co = 0;
	}
	while (!co) {
		cout << "Enter valid data\n\n";
		cout << "ROW NUM:   "; cin >> xi;
		cout << "COL NUM:   "; cin >> yi;
		cout << "\n";
		co = 1;
		for (int i = 0; i < xi.size(); i++) {
			bool bl = isdigit(xi[i]);
			if (!bl)co = 0;
		}
		for (int i = 0; i < yi.size(); i++) {
			bool bl = isdigit(yi[i]);
			if (!bl)co = 0;
		}
	}
	int x = stoi(xi);
	int y = stoi(yi);
	
	while (true) {
		bool bl = 1;
		if (x > size || x<1 || y>size || y < 0) { bl = 0; }
		else if (v[x - 1][y - 1] != '-') { bl = 0; }
		if (bl) { break; }
		alert();

		cout << "ROW NUM:   "; cin >> x;
		cout << "COL NUM:   "; cin >> y; cout << "\n";

	}

	v[x - 1][y - 1] = move;
	return is_win(size, move);

}

void show_tilte() {

	cout << "\t\t\t\t  ";
	pline(23);
	cout << "\t\t\t\t  ";

	cout << "|>--TIC-->TAC-->TOE--<|\n";
	cout << "\t\t\t\t  "; pline(23); cout << "\n";

}
bool is_win(int size,char ch) {
	bool iswin = 1;
	for (int i = 0,j=0; i < size; j++,i++) {
		
		if (v[i][j] != ch) { iswin = 0; break; }

	}
	if (iswin) { return 1; }
	iswin = 1;
	for (int i = 0, j = size-1; i < size; j--, i++) {

		if (v[i][j] != ch) { iswin = 0; break; }

	} 
	if (iswin) { return 1; }
	for (int i = 0; i < size;i++) {
		bool is = 1;
		for (int j = 0; j < size; j++) {
			if (v[i][j] != ch) { is = 0; break; }
		}
		if (is) { return 1; }
	}
	for (int i = 0; i < size; i++) {
		bool is = 1;
		for (int j = 0; j < size; j++) {
			if (v[j][i] != ch) { is = 0; break; }
		}
		if (is) { return 1; }
	}


	return 0;
}
int get_names() {
	cout << "ENTER FIRST PLAYER NAME:    "; cin >> fplayer;
	cout << "ENTER SECOND PLAYER NAME:    "; cin >> splayer;
	cout << "\t\t"; pline(50);
	cout << "\t\t\t\t" << "X for " << fplayer << ".\n";
	cout << "\t\t\t\t" << "O for " << splayer << ".\n"; cout << "\t\t";
	pline(50);
	int temp; cout << "\t\t\tchoose number of squaresin game:   "; cin >> temp;
	cout << "\t\t"; pline(50);
	cout << "\t\t\t\t LETS START TE GAME (-_-)\n\n"; 
	return temp;
}
bool GAME(int size,bool isp1) {
	system("cls");
	show_tilte();
	pline(100);
	show_board(size);
	if (isp1) {
		cout << "Its " << fplayer << " move\n\n";
		
		if (get_move(size, 'X')) {
			cout << "\t\t\t\tCONGRATS\n";
			cout << "\t\t\tWINNER WINNER CHICKEN DINNER\n"; pline(100); cout << "\n"; show_board(size); return 1;
		}
		
	}
	else {
		cout << "Its " << splayer << " move\n\n";

		if (get_move(size, 'O')) {
			cout << "\t\t\t\tCONGRATS\n";
			cout << "\t	\t	WINNER WINNER CHICKEN DINNER\n"; pline(100); cout << "\n"; show_board(size); return 1;
			
		}
	}
	return 0;
}

bool another_game() {
	Sleep(7000);
	system("cls");
	char ch;
	cout << "\t\t\t\t ANOTHER GAME?(Y/N)\n";
	cin >> ch; cout << "\n";
	if (tolower(ch) == 'y') { return 1; }
	else if (tolower(ch) == 'n') { return 0; }
	else {
		cout << "ENTER VALID OPREATION\n";
		another_game();
	}
}