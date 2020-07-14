#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

//===== Khai bao bien =====//
int Input_Key;

bool is_Page_Exit = false;
bool is_Goto_Next_Page = false;
int Page_Number = 0;			// Page hien tai.

string Page_0[] = { "1. Cong-Tru-Nhan-Chia", "2. Giai phuong trinh", "3. Tim so nguyen to", "4. Sap xep mang", "0. EXIT" };

string Page_1_0[] = { "1. Thuc hien phep cong", "2. Thuc hien phep tru", "3. Thuc hien phep nhan", "4. Thuc hien phep chia" };
string Page_1_1[] = { "1. He phuong trinh", "2. Phuong trinh bac n" };

string Page_2_1_0[] = { "1. He phuong trinh 2 an", "2. He phuong trinh 3 an" };
string Page_2_1_1[] = { "1. Phuong trinh bac 2", "2. Phuong trinh bac 3" };


//===== Khai bao ham =====//
void Menu_Direction();
void MenuPage0Processing();
void MenuPage1Processing();
void MenuPage2Processing();
void MenuPage3Processing();

void TimSoNguyenTo();
void SapXepMang();
void TinhAB(unsigned int _Phep_Tinh);
void GiaiPTBac2();
void GiaiPTBac3();
void GiaiHePT2An();
void GiaiHePT3An();

class Page {									// Khoi tao class Page, moi noi dung hien thi se tuong ung voi 1 page ( trang )
public:
	int Pointer = 0;
	void Display(string _Page_List[], int _Page_List_Size);		// hien thi page + cho nguoi dung thao tac 
	void hello() {								// ham nay chi dung de test/ debug 
		system("cls") ;
		cout << "Hello world *-*";
		_getch();
	}
};

void Page::Display(string _Page_List[], int _Page_List_Size) {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "CHUONG TRINH: MENU CAC HAM \n";
	cout << "HOC VIEN:     NGUYEN VO KHANH TOAN\n";
	cout << "LOP:          20Cpp02 (toi t3 - t5)\n\n";
	cout << "\n			[	MENU        ]			\n\n";
	for (int i = 0; i < _Page_List_Size; i++) {
		if (i == Pointer) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "			" << _Page_List[i] << "\n";
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "			" << _Page_List[i] << "\n";
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "									" << Pointer;

	Input_Key = _getch();			// cho nguoi dung nhap ban phim 
	if (Input_Key == 80) {			// phim mui ten xuong
		if (Pointer > _Page_List_Size - 2) { Pointer = _Page_List_Size - 1; }
		else Pointer++;
	}
	else if (Input_Key == 72) {		// phim mui ten len
		if (Pointer <= 0) Pointer = 0;
		else Pointer--;
	}
	else if (Input_Key == 13) {		// phim Enter
		is_Goto_Next_Page = true;
	}
	else if (Input_Key == 27) {		// Phim ESC
		is_Page_Exit = true;
	}
}

class Page Menu_Page[4];				// khai bao 1 menu gom 4 trang 

void MenuDirection() {					// Xu ly Page Hien thi moi khi nguoi dung thao tac tu ban phim
	if (is_Page_Exit) {					// BACK
		is_Page_Exit = false;
		if (Page_Number <= 0) Page_Number = 0;
		else Page_Number--;

	}
	if (is_Goto_Next_Page) {			// ENTER
		is_Goto_Next_Page = false;
		if (Page_Number >= 4) Page_Number = 4;		// chi tao toi da 4 trang thoi ( Menu_Page[0]->[1]->[2]->[3] ) 
		else Page_Number++;

	}

	// Xu ly hien tri Page tuong ung
	switch (Page_Number) {				// Page_Number : Page hien tai 
	case 0: {
		MenuPage0Processing();
		break; }
	case 1: {
		MenuPage1Processing();
		break; }
	case 2: {
		MenuPage2Processing();
		break; }
	case 3: {
		MenuPage3Processing();
		break; }
	default: break;
	}

}

// Xu ly hien thi tung Page tuong ung 
void MenuPage0Processing() {
	Menu_Page[0].Display(Page_0, sizeof(Page_0) / sizeof(Page_0[0]));
}

void MenuPage1Processing() {
	if (Menu_Page[0].Pointer == 0) Menu_Page[1].Display(Page_1_0, sizeof(Page_1_0) / sizeof(Page_1_0[0]));
	else if (Menu_Page[0].Pointer == 1) Menu_Page[1].Display(Page_1_1, sizeof(Page_1_1) / sizeof(Page_1_1[0]));
	else if (Menu_Page[0].Pointer == 2) { TimSoNguyenTo(); Page_Number--; }
	else if (Menu_Page[0].Pointer == 3) { SapXepMang(); Page_Number--; }

	else { system("cls"); cout << "Update later"; _getch(); Page_Number--; }

}

void MenuPage2Processing() {
	if (Menu_Page[0].Pointer == 0 && Menu_Page[1].Pointer == 0) { TinhAB(0); Page_Number--;}
	else if (Menu_Page[0].Pointer == 0 && Menu_Page[1].Pointer == 1) { TinhAB(1); Page_Number--; }
	else if (Menu_Page[0].Pointer == 0 && Menu_Page[1].Pointer == 2) { TinhAB(2); Page_Number--; }
	else if (Menu_Page[0].Pointer == 0 && Menu_Page[1].Pointer == 3) { TinhAB(3); Page_Number--; }

	else if (Menu_Page[0].Pointer == 1 && Menu_Page[1].Pointer == 0) Menu_Page[2].Display(Page_2_1_0, sizeof(Page_2_1_0) / sizeof(Page_2_1_0[0]));
	else if (Menu_Page[0].Pointer == 1 && Menu_Page[1].Pointer == 1) Menu_Page[2].Display(Page_2_1_1, sizeof(Page_2_1_1) / sizeof(Page_2_1_1[0]));

	else { system("cls"); cout << "Update later"; _getch(); Page_Number--; }
}

void MenuPage3Processing() {
	if ((Menu_Page[0].Pointer == 1) && (Menu_Page[1].Pointer == 0) && (Menu_Page[2].Pointer == 0)) { GiaiHePT2An(); Page_Number--; }
	else if ((Menu_Page[0].Pointer == 1) && (Menu_Page[1].Pointer == 0) && (Menu_Page[2].Pointer == 1)) { GiaiHePT3An(); Page_Number--; }
	else if ((Menu_Page[0].Pointer == 1) && (Menu_Page[1].Pointer == 1) && (Menu_Page[2].Pointer == 0)) { GiaiPTBac2(); Page_Number--; }
	else if ((Menu_Page[0].Pointer == 1) && (Menu_Page[1].Pointer == 1) && (Menu_Page[2].Pointer == 1)) { GiaiPTBac3(); Page_Number--; }
	else { system("cls"); cout << "Update later"; _getch(); Page_Number--; }
}



int main() {
	while (true) {
		MenuDirection();
	}

	_getch();
}

// Ham sap xep mang theo thu tu tu nho den lon 
void SapXepMang() {
	system("cls");
	int so_Phan_Tu_Mang;
	cout << "Nhap so phan tu mang : ";
	cin >> so_Phan_Tu_Mang;
	while ((so_Phan_Tu_Mang < 5) || (so_Phan_Tu_Mang > 20)) {
		printf("So phan tu mang khong hop le, nhap lai : ");
		cin >> so_Phan_Tu_Mang;
	}

	int Mang[10];

	for (int i = 0; i < so_Phan_Tu_Mang; i++) {

		printf("Mang[%d] = ", i);
		cin >> Mang[i];
	}

	for (int i = 0; i < so_Phan_Tu_Mang; i++) {
		for (int j = i; j < so_Phan_Tu_Mang; j++) {
			if (Mang[i] > Mang[j]) {
				int temp = Mang[i];
				Mang[i] = Mang[j];
				Mang[j] = temp;
			}
		}
	}

	printf("\n===========================RESULTS======================================");
	printf("\nMang sau khi da sap xep : ");
	for (int i = 0; i < so_Phan_Tu_Mang; i++) {
		printf("\nMang[%d] = %d", i, Mang[i]);
	}
	_getch();
}

// Ham thuc hien tim so nguyen to nhap vao tu ban phim 
void TimSoNguyenTo() {
	system("cls"); 
	int n;
	cout << "\nNhap n = ";
	cin >> n;
	if (n < 2) cout << n << " khong phai so nguyen to\n";
	else {
		int count = 0;
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) count++;
		}
		if (count == 0) cout << n << " la so nguyen to\n";
		else cout << n << " khong phai so nguyen to\n";
	}
	_getch();
}

// Ham thuc hien phep cong tru nhan chia 2 so a va b : 
void TinhAB(unsigned int _Phep_Tinh) {
	system("cls");
	int a,b ;
	cout << "\nNhap a = ";
	cin >> a;
	cout << "\nNhap b = ";
	cin >> b;
	switch (_Phep_Tinh){
	case 0: cout << "\na + b = " << (a + b); break;
	case 1: cout << "\na - b = " << (a - b); break;
	case 2: cout << "\na x b = " << (a * b); break;
	case 3: cout << "\na : b = " << (a / b); break;
	default:
		break;
	}
	_getch();
}

void GiaiPTBac2() {
	system("cls");
	cout << "Hello world ! *-*";
	_getch();
}

void GiaiPTBac3() {
	system("cls");
	cout << "Hello world !! *-*";
	_getch();
}

void GiaiHePT2An() {
	system("cls");
	cout << "Hello world !!! *-*";
	_getch();
}

void GiaiHePT3An() {
	system("cls"); 
	cout << "Hello world !!!! *-*";
	_getch();
}