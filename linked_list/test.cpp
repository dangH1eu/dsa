#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct Sinhvien {
  string masv;
  string hodem;
  string ten;
  int namsinh;
  double diemtk;
};

struct Node {
  Sinhvien data;
  Node *next;
};

void init(Node *&L) { L = nullptr; }

int empty(Node *L) {
  if (L == nullptr) {
    return true;
  } else {
    return false;
  }
}

void nhap_sv(Sinhvien &sv) {
  cout << "\tnhap ma sv: ";
  getline(cin, sv.masv);
  if (sv.masv.compare("***") == 0) {
    return;
  }
  cout << "\tnhap ho dem: ";
  getline(cin, sv.hodem);
  cout << "\tnhap ten: ";
  getline(cin, sv.ten);
  cout << "\tnhap nam sinh: ";
  cin >> sv.namsinh;
  cout << "\tnhap diem tk: ";
  cin >> sv.diemtk;
  cin.ignore(256, '\n');
}

void nhap_ds(Node *&L) {
  init(L);
  Sinhvien x;
  Node *q;
  Node *p;
  int i = 1;
  do {
    cout << "nhap sinh vien thu " << i << endl;
    nhap_sv(x);
    if (x.masv.compare("***") == 0) {
      return;
    }
    q = new Node;
    q->data = x;
    q->next = nullptr;

    if (L == nullptr) {
      L = q;
    } else {
      p->next = q; // tro vao node moi
    }
    p = q; // gan q vao node tiep theo
    i++;
  } while (1);
}

void hien_thi_ds(Node *L) {
  if (L == nullptr) {
    cout << "danh sach rong " << endl;
    return;
  }
  cout << setw(5) << "stt";
  cout << setw(10) << "ma sv";
  cout << setw(25) << "ho va ten";
  cout << setw(10) << "nam sinh";
  cout << setw(10) << "diem tk" << endl;

  Node *p = L;
  int i = 0;
  while (p != nullptr) {

    Sinhvien x = p->data; // gan x de xuat du lieu tu node
    cout << setw(5) << i + 1;
    cout << setw(10) << x.masv;
    cout << setw(17) << x.hodem;
    cout << setw(8) << x.ten;
    cout << setw(10) << x.namsinh;
    cout << setw(10) << x.diemtk << endl;

    i++;
    p = p->next; // move to next node
  }
}

int length(Node *L) {
  Node *p = L;
  int n = 0;
  while (p != nullptr) {
    p = p->next;
    n++;
  }
  return n;
}

void pop_front(Node *&L) {
  if (L != nullptr) {
    Node *p = L;
    L = L->next; // move L to next node
    delete p;
    cout << "danh sach sau khi xoa sinh vien dau tien\n";
    hien_thi_ds(L);
    return;
  }
  cout << "danh sach rong, khong the xoa sinh vien dau tien duoc\n";
}

Node *search(Node *L, string ma) {
  Node *p = L;
  while (p != nullptr && p->data.masv.compare(ma) != 0) {
    p = p->next;
  }
  return p;
}

void remove(Node *&L, Node *T) {
  Node *p;
  if (T == L) {
    L = T->next;
  } else {
    p = L;
    while (p->next != T) {
      p = p->next;
    }
    p->next = T->next;
  }
  delete T;
}

void xoa_sv8089(Node *&L) {

  Node *T = search(L, "sv8089"); // tim sv8089 trong danh sach

  if (T == nullptr) {
    cout << "khong co ma sv8089 trong danh sach\n";
    return;
  }

  remove(L, T);
  cout << "danh sach vua xoa sv8089\n";
  hien_thi_ds(L);
}

void push_front(Node *&L, Sinhvien x) {
  Node *p;
  p = new Node; // create a new Node
  p->data = x;  // insert data on Node
  p->next = L;
  L = p; // move L pointer to p Node
}

void insert(Node *&L, Node *p, Sinhvien x) {
  Node *t;
  t = new Node;

  t->data = x;
  t->next = p->next;

  p->next = t;
}

void bo_sung(Node *&L) {
  int index;
  Sinhvien x;
  do {
    cout << "nhap vi tri bo sung (0 < index <= " << length(L) << "): ";
    cin >> index;
  } while (index < 0 || index > length(L));

  cout << "nhap thong tin sinh vien can bo sung" << endl;
  do {
    cin.ignore(256, '\n');
    nhap_sv(x);
    if (x.masv.compare("***") == 0) {
      cout << "ma sv phai khac ***, nhap lai" << endl;
    }
  } while (x.masv.compare("***") == 0);

  if (index == 0) {
    push_front(L, x);
  } else {

    Node *p = L;
    for (int i = 0; i < index - 1; i++) {
      p = p->next;
    }
    insert(L, p, x);
  }
  cout << "danh sach vua bo sung\n";
  hien_thi_ds(L);
}

void hien_thi_sv_doanh(Node *L) {
  if (L == nullptr) {
    cout << "danh sach rong\n";
    return;
  }
  cout << setw(5) << "stt";
  cout << setw(10) << "ma sv";
  cout << setw(25) << "ho va ten";
  cout << setw(10) << "nam sinh";
  cout << setw(10) << "diem tk" << endl;

  Node *q = L;
  int i = 0;
  while (q != nullptr) {
    Sinhvien x = q->data;
    if (x.masv.compare("Doanh") == 0) {
      cout << setw(5) << i + 1;
      cout << setw(10) << x.masv;
      cout << setw(17) << x.hodem;
      cout << setw(8) << x.ten;
      cout << setw(10) << x.namsinh;
      cout << setw(10) << x.diemtk << endl;
      i++;
    }
    q = q->next;
  }
  if (i == 0) {
    cout << "khong co sv Doanh nao trong danh sach\n";
  }
}

void sort_diemtk(Node *&L) {
  Node *p, *q, *r;
  p = L;
  while (p->next != nullptr) {
    r = p;
    q = p->next;
    while (q != nullptr) {
      if (q->data.diemtk > r->data.diemtk) {
        r = q;
      }
      q = q->next;
    }
    Sinhvien tg = p->data;
    p->data = r->data;
    r->data = tg;
    p = p->next;
  }
  cout << "danh sach sap giam theo diem tk la" << endl;
  hien_thi_ds(L);
}

void bo_sung_theo_trat_tu(Node *&L) {
  Sinhvien x;
  cout << "nhap thong tin sinh vien can bo sung" << endl;
  do {
    nhap_sv(x);
    if (x.masv.compare("***") == 0) {
      cout << "ma sv phai khac ***, nhap lai" << endl;
    }
  } while (x.masv.compare("***") == 0);

  if (x.diemtk >= L->data.diemtk) {
    push_front(L, x);
  } else {
    Node *q = L;
    Node *p;
    p = q->next;
    while (p != nullptr && p->data.diemtk > x.diemtk) {
      p = p->next;
      q = q->next;
    }
    insert(L, q, x);
  }
  cout << "=========================================================\n";
  hien_thi_ds(L);
}
int main() {
  Node *L;

  cout << "nhap danh sach sinh vien\n";
  nhap_ds(L);
  cout << "=========================================================\n";
  cout << "danh sach vua nhap\n";
  hien_thi_ds(L);

  cout << "=========================================================\n";
  cout << "chieu dai cua danh sach: " << length(L) << endl;

  cout << "=========================================================\n";
  pop_front(L);

  cout << "=========================================================\n";
  xoa_sv8089(L);

  cout << "=========================================================\n";
  bo_sung(L);

  cout << "=========================================================\n";
  cout << "danh sach nhung sinh vien ten doanh" << endl;
  hien_thi_sv_doanh(L);

  cout << "=========================================================\n";
  sort_diemtk(L);

  cout << "=========================================================\n";
  bo_sung_theo_trat_tu(L);
  return 0;
}
