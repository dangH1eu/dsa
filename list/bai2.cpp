#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Hanghoa {
  string mahang;
  string tenhang;
  int soluong;
};

struct List {
  int count;
  Hanghoa e[MAX];
};

void create(List &L) { L.count = -1; }

int full(List L) {
  if (L.count == MAX - 1) {
    return true;
  } else {
    return false;
  }
}

int empty(List L) { return L.count == -1; }

int push_back(List &L, Hanghoa h) {
  if (full(L)) {
    return 0;
  } else {
    L.count++;
    L.e[L.count] = h;
    return 1;
  }
}

void nhap_hh(Hanghoa &h) {
  cout << "\tnhap ma hang: ";
  getline(cin, h.mahang);
  if (h.mahang.compare("***") == 0) {
    return;
  }
  cout << "\tnhap ten hang: ";
  getline(cin, h.tenhang);
  cout << "\tnhap so luong: ";
  cin >> h.soluong;
  cin.ignore(256, '\n');
}

void nhap_ds(List &L) {
  create(L);
  Hanghoa h;
  int i = 0;
  do {
    cout << "nhap hang hoa thu " << i + 1 << endl;
    nhap_hh(h);
    if (h.mahang.compare("***") == 0) {
      return;
    }
    if (!push_back(L, h)) {
      return;
    }
    i++;
  } while (1);
}

void remove(List &L, int k) {
  for (int i = k; i <= L.count; i++) {
    L.e[i] = L.e[i + 1];
  }
  L.count--;
}

void insert(List &L, int k) {
  Hanghoa h;
  if (!full(L) && k <= L.count + 1 && k > 0) {
    nhap_hh(h);
    for (int i = L.count; i >= k - 1; i--) {
      L.e[i + 1] = L.e[i];
    }
    L.count++;
    L.e[k - 1] = h;
  }
}

void bubble_sort(List &L) {
  for (int i = 0; i <= L.count; i++) {
    for (int j = 0; j < L.count - i; j++) {
      if (L.e[j].soluong > L.e[j + 1].soluong) {
        Hanghoa tg;
        tg = L.e[j];
        L.e[j] = L.e[j + 1];
        L.e[j + 1] = tg;
      }
    }
  }
}

void hien_thi_ds(List L) {
  cout << setw(5) << "stt";
  cout << setw(10) << "ma hang";
  cout << setw(15) << "ten hang";
  cout << setw(10) << "so luong" << endl;
  for (int i = 0; i <= L.count; i++) {
    cout << setw(5) << i + 1;
    cout << setw(10) << L.e[i].mahang;
    cout << setw(15) << L.e[i].tenhang;
    cout << setw(10) << L.e[i].soluong << endl;
  }
  cout << endl;
}
int main() {
  List L;

  nhap_ds(L);
  cout << "\ndanh sach vua nhap\n";
  hien_thi_ds(L);

  cout << "day sau khi xoa phan tu thu 3 la: " << endl;
  remove(L, 2); // truyen vao chi so cua mang
  hien_thi_ds(L);

  cout << "chen vao vi tri dau danh sach" << endl;
  insert(L, 1);
  hien_thi_ds(L);

  cout << "danh sach sau khi sap xep theo so luong" << endl;
  bubble_sort(L);
  hien_thi_ds(L);
  return 0;
}
