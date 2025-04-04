#include <iostream>
#include <cstring>
using namespace std;

struct SinhVien {
    char hoTen[50], diaChi[70], lop[10];
    int khoa;
};

struct Node {
    SinhVien data;
    Node* next;
};

struct ListSV {
    Node* head;
    ListSV() { head = NULL; }

    void themSinhVien(SinhVien sv) {
        Node* newNode = new Node{sv, NULL};
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void xoaTheoTen(const char* ten) {
        Node *curr = head, *prev = NULL;
        while (curr && strcmp(curr->data.hoTen, ten) != 0) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return;
        if (!prev) head = curr->next;
        else prev->next = curr->next;
        delete curr;
    }

    void xoaTheoDiaChi(const char* dc) {
        Node *curr = head, *prev = NULL;
        while (curr && strcmp(curr->data.diaChi, dc) != 0) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return;
        if (!prev) head = curr->next;
        else prev->next = curr->next;
        delete curr;
    }

    void inDanhSach() {
        Node* temp = head;
        while (temp) {
            cout << temp->data.hoTen << " - " << temp->data.diaChi << " - "
                 << temp->data.lop << " - " << temp->data.khoa << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ListSV ds;
    SinhVien sv;
    
    cout << "Nhap 10 sinh vien: \n";
    for (int i = 0; i < 10; i++) {
        cout << "Ho ten: "; cin.ignore(); cin.getline(sv.hoTen, 50);
        cout << "Dia chi: "; cin.getline(sv.diaChi, 70);
        cout << "Lop: "; cin.getline(sv.lop, 10);
        cout << "Khoa: "; cin >> sv.khoa;
        ds.themSinhVien(sv);
    }
    ds.inDanhSach();
    
    ds.xoaTheoTen("Nguyen Van Teo");
    ds.inDanhSach();
    
    ds.xoaTheoDiaChi("Nguyen Van Cu");
    ds.inDanhSach();
    
    SinhVien newSV = {"Tran Thi Mo", "25 Hong Bang", "TT0901", 2009};
    ds.themSinhVien(newSV);
    ds.inDanhSach();
    
    return 0;
}