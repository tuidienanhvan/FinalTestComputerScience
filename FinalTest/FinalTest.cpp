#include<iostream>
#include<cmath>
#include <string>
#include <stack>
#include <queue>

using namespace std;


void tongUoc(int a[]) {
    int sum[1000] = { 0 };
    int num;
    cout << "Nhap so luong so nguyen duong: ";
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "Nhap so nguyen duong thu " << i + 1 << ": ";
        cin >> a[i];

        for (int j = 1; j <= a[i] / 2; ++j) {
            if (a[i] % j == 0) {
                sum[i] += j;
            }
        }
    }

    for (int i = 0; i < num; i++) {
        cout << "So nguyen duong " << a[i] << " co tong uoc la: " << sum[i] << endl;
    }
}

class Vemaybay {
private:
    string tenchuyen;
    string ngaybay;
    double giave;

public:

    Vemaybay() {
        tenchuyen = "";
        ngaybay = "";
        giave = 0.0;
    }

    ~Vemaybay() {

    }

    void Nhap() {

        cout << "Nhap ten chuyen bay: ";
        getline(cin, tenchuyen);

        cout << "Nhap ngay bay: ";
        getline(cin, ngaybay);

        cout << "Nhap gia ve: ";
        cin >> giave;

        cin.ignore();
    }

    void Xuat() {
        cout << "Ten chuyen bay: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }

    double getgiave() {
        return giave;
    }
};

class Nguoi {
protected:
    string hoten;
    string gioitinh;
    int tuoi;

public:

    Nguoi() {
        hoten = "";
        gioitinh = "";
        tuoi = 0;
    }

    ~Nguoi() {

    }

    void Nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoten);

        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);

        cout << "Nhap tuoi: ";
        cin >> tuoi;

        cin.ignore();
    }

    void Xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class HanhKhach : public Nguoi {
private:
    Vemaybay* ve;
    int soluong;

public:

    HanhKhach() {
        ve = nullptr;
        soluong = 0;
    }

    ~HanhKhach() {
        delete[] ve;
    }

    void Nhap() {
        Nguoi::Nhap();
        cout << "Nhap so luong ve may bay: ";
        cin >> soluong;

        cin.ignore();

        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; ++i) {
            cout << "Nhap thong tin ve may bay thu " << i + 1 << ":" << endl;
            ve[i].Nhap();
        }
    }

    void Xuat() {
        Nguoi::Xuat();

        cout << "So luong ve may bay: " << soluong << endl;

        for (int i = 0; i < soluong; ++i) {
            cout << "Thong tin ve may bay thu " << i + 1 << ":" << endl;
            ve[i].Xuat();
        }
    }

    double tongtien() {
        double total = 0.0;
        for (int i = 0; i < soluong; ++i) {
            total += ve[i].getgiave();
        }
        return total;
    }
};

void Sort(HanhKhach danhSachHanhKhach[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (danhSachHanhKhach[i].tongtien() < danhSachHanhKhach[j].tongtien()) {
                swap(danhSachHanhKhach[i], danhSachHanhKhach[j]);
            }
        }
    }
}

string encodeString(const string& s) {
    string result = "";
    stack<pair<char, int>> charStack;

    for (char ch : s) {
        if (!charStack.empty() && charStack.top().first == ch) {
            charStack.top().second++;
        }
        else {
            charStack.push(make_pair(ch, 1));
        }
    }

    while (!charStack.empty()) {
        result = charStack.top().first + to_string(charStack.top().second) + result;
        charStack.pop();
    }

    return result;
}

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool isSuperPrime(int num) {
    if (num < 2) {
        return false;
    }

    while (num > 0) {
        if (!isPrime(num)) {
            return false;
        }
        num /= 10;
    }

    return true;
}

void printSuperPrimes(int n) {
    cout << "Cac so sieu nguyen to nho hon hoac bang " << n << " la:\n";

    queue<int> superPrimesQueue;
    for (int i = 2; i <= n; ++i) {
        if (isSuperPrime(i)) {
            superPrimesQueue.push(i);
        }
    }

    while (!superPrimesQueue.empty()) {
        cout << superPrimesQueue.front() << " ";
        superPrimesQueue.pop();
    }

    cout << endl;
}

int main() {
    int choice = 1, n = 0, a[1000];
    Vemaybay ve;
    string s;

    do {

        system("cls");
        cout << "Menu:" << endl;
        cout << "1. Bai tap 1" << endl;
        cout << "2. Bai tap 2" << endl;
        cout << "3. Bai tap 3" << endl;
        cout << "4. Bai tap 4" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tongUoc(a);
            break;
        case 2:
        {
            cout << "Nhap so luong hanh khach: ";
            cin >> n;
            cin.ignore();
            HanhKhach* danhSachHanhKhach = new HanhKhach[n];
            for (int i = 0; i < n; ++i) {
                cout << "Nhap thong tin hanh khach thu " << i + 1 << ":" << endl;
                danhSachHanhKhach[i].Nhap();
            }
            cout << "\n------DANH SACH------\n";
            for (int i = 0; i < n; ++i) {
                danhSachHanhKhach[i].Xuat();
                cout << "Tong tien phai tra: " << danhSachHanhKhach[i].tongtien() << endl;
                cout << "--------------------------\n";
            }

            Sort(danhSachHanhKhach, n);

            cout << "\nDanh sach hanh khach sau khi sap xep:\n";
            for (int i = 0; i < n; ++i) {
                danhSachHanhKhach[i].Xuat();
                cout << "Tong tien phai tra: " << danhSachHanhKhach[i].tongtien() << endl;
                cout << "--------------------------\n";
            }

            delete[] danhSachHanhKhach;
            break;
        }
        case 3:
        {
            cin.ignore();
            cout << "Nhap chuoi: ";
            getline(cin, s);
            string encodedString = encodeString(s);
            cout << "Encoded String: " << encodedString << endl;
            break;
        }
        case 4:
        {
            cout << "Nhap mot so nguyen n: ";
            cin >> n;
            printSuperPrimes(n);
            break;
        }
        case 0:
            cout << "Cam on ban da su dung chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }

        system("pause");

    } while (choice != 0);

    return 0;
}
