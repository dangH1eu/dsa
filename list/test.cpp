#include <cctype>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
struct Sinhvien {
  string masv;
  string hodem;
  string ten;
  int namsinh;
  double diemtk;
};

template <typename T> struct List {
  int count;
  T e[MAX];
};

void create(List<Sinhvien> &L) { L.count = -1; }

int full(List<Sinhvien> L) { return L.count == MAX - 1; }

int empty(List<Sinhvien> L) { return L.count == -1; }

int add(List<Sinhvien> &L, Sinhvien x) {
  if (full(L)) {
    return 0;
  } else {
    L.count++;
    L.e[L.count] = x;
    return 1;
  }
}

void nhap_sv(Sinhvien &sv) {
  cout << "\tnhap ma sv: ";
  fflush(stdin);
  getline(cin, sv.masv);
  if (sv.masv.compare("***") == 0) {
    return;
    cout << "\tho dem: ";
    fflush(stdin);
    getline(cin, sv.hodem);
  }
  cout << "\tten: ";
  fflush(stdin);
  getline(cin, sv.ten);
  cout << "\tnam sinh: ";
  cin >> sv.namsinh;
  cout << "\tdiem tk: ";
  cin >> sv.diemtk;
}

void nhap_ds(List<Sinhvien> &L) {
  create(L);
  Sinhvien x;
  int i = 1;
  do {
    cout << "nhap sinh vien thu " << i << endl;
    nhap_sv(x);
    if (x.masv.compare("***") == 0) {
      return;
    }
    if (!add(L, x)) {
      return;
    }
    i++;
  } while (1);
}

void hien_thi_ds(List<Sinhvien> L) {
  cout << setw(5) << "stt";
  cout << setw(10) << "ma sv";
  cout << setw(25) << "ho va ten";
  cout << setw(10) << "nam sinh";
  cout << setw(10) << "diem tk" << endl;
  for (int i = 0; i <= L.count; i++) {
    cout << setw(5) << (i + 1);
    cout << setw(10) << L.e[i].masv;
    cout << setw(17) << L.e[i].hodem;
    cout << setw(8) << L.e[i].ten;
    cout << setw(10) << L.e[i].namsinh;
    cout << setw(10) << L.e[i].diemtk << endl;
  }
}

void del_first(List<Sinhvien> &L) {
  if (empty(L)) {
    return;
  }
  for (int i = 1; i < L.count; i++) {
    L.e[i - 1] = L.e[i];
  }
  L.count--;
}

int search(List<Sinhvien> L, string ma) {
  int i = 0;
  while (i <= L.count && L.e[i].masv.compare(ma) != 0) {
    i++;
  }
  if (i <= L.count) {
    return i + 1;
  } else {
    return 0;
  }
}

void remove(int k, List<Sinhvien> &L) {
  for (int i = k - 1; i < L.count; i++) {
    L.e[i] = L.e[i + 1];
  }
  L.count--;
}

int xoa_sv8089(List<Sinhvien> &L) {
  int k = search(L, "sv8089");
  if (k == 0) {
    return 0;
  }
  remove(k, L);
  return 1;
}

int insert(int k, List<Sinhvien> &L) {
  int i;
  Sinhvien x;
  if (!full(L) && k <= L.count + 1 && k >= 1) {
    cout << "\nnhap sinh vien can bo sung\n";
    nhap_sv(x);
    for (i = L.count; i >= k; i--) {
      L.e[i + 1] = L.e[i];
    }
    L.count = L.count + 1;
    L.e[k - 1] = x;
    return 1;
  } else {
    return 0;
  }
}

void liet_ke(List<Sinhvien> L) {
  int i = 0, d = 0;
  cout << setw(5) << "stt";
  cout << setw(10) << "ma sv";
  cout << setw(25) << "ho va ten";
  cout << setw(10) << "nam sinh";
  cout << setw(10) << "diem tk" << endl;
  while (i <= L.count) {
    if (L.e[i].ten.compare("Doanh") == 0) {
      cout << setw(5) << (i + 1);
      cout << setw(10) << L.e[i].masv;
      cout << setw(17) << L.e[i].hodem;
      cout << setw(8) << L.e[i].ten;
      cout << setw(10) << L.e[i].namsinh;
      cout << setw(10) << L.e[i].diemtk << endl;
      d++;
    }
    i++;
  }
  if (d == 0) {
    cout << "khong co ten sv ten Doanh" << endl;
  }
}

void sort(List<Sinhvien> &L) {
  for (int i = 0; i <= L.count; i++) {
    for (int j = 0; j <= L.count - i; j++) {
      if (L.e[j].diemtk < L.e[j + 1].diemtk) {
        Sinhvien tg = L.e[j];
        L.e[j] = L.e[j + 1];
        L.e[j + 1] = tg;
      }
    }
  }
}

int sort_insert(List<Sinhvien> &L) {
  Sinhvien x;
  if (full(L)) {
    return 0;
  }
  nhap_sv(x);
  int i = L.count;
  while (i >= 0 && L.e[i].diemtk < x.diemtk) {
    L.e[i + 1] = L.e[i];
    i--;
  }
  L.e[i + 1] = x;
  L.count++;
  return 1;
}

int main() {
  List<Sinhvien> L;
  nhap_ds(L);
  cout << "danh sach vua nhap\n";
  hien_thi_ds(L);
  cout << "danh sach vua xoa sv dau tien\n";
  del_first(L);
  hien_thi_ds(L);
  if (xoa_sv8089(L) == 1) {
    cout << "danh sach sau khi xoa sv8089\n";
    hien_thi_ds(L);
  } else {
    cout << "khong co sv ma sv8089\n";
  }

  int k;
  cout << "nhap vi tri can bo sung: ";
  cin >> k;
  if (insert(k, L) == 1) {
    cout << "\ndanh sach sv vua bo sung\n";
    hien_thi_ds(L);
  } else {
    cout << "vi tri khong thich hop\n";
  }

  sort(L);
  cout << "\ndanh sach duoc sap xep\n";
  hien_thi_ds(L);
  if (sort_insert(L) == 0) {
    cout << "danh sach day\n";
  } else {
    cout << "\ndanh sach bo sung sau sap xep \n";
    hien_thi_ds(L);
  }
  return 0;
}
