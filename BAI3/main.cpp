#include "QuanLySinhVien.h"

using namespace std;

int main() {
    int n;
    cout << "Nhap so sinh vien: "; cin >> n;
    vector<SinhVien*> v(n);
    vector<SinhVien*> totnghiep;
    vector<SinhVien*> Ktotnghiep;
    int a = 0, b = 0;
    SinhVien* best1 = nullptr;
    SinhVien* best2 = nullptr;

    for (int i = 0; i < n; i++) {
        int d;
        cout << "(0: sinh vien cao dang, 1: sinh vien dai hoc): "; cin >> d;
        int maSV, tongTC;
        string HoTen, diaChi;
        double dtb;
        cout << "Nhap ma so sinh vien: "; cin >> maSV;
        cin.ignore();
        cout << "Nhap ho ten: "; getline(cin, HoTen);
        cout << "Nhap dia chi: "; getline(cin, diaChi);
        cout << "Nhap tong so tin chi: "; cin >> tongTC;
        cout << "Nhap diem trung binh: "; cin >> dtb;

        if (d == 0) {
            double diemTN;
            cout << "Nhap diem tot nghiep: "; cin >> diemTN;
            v[i] = new SinhVienCaoDang(maSV, HoTen, diaChi, tongTC, dtb, diemTN);
            if (tongTC >= 120 && dtb >= 5 && diemTN >= 5) {
                totnghiep.push_back(v[i]);
            } else {
                Ktotnghiep.push_back(v[i]);
                a++;
            }
            if (best1 == nullptr || best1->getDtb() < dtb) {
                best1 = v[i];
            }
        } else {
            string tenLuanVan;
            double diemLuanVan;
            cout << "Nhap ten luan van: "; cin.ignore(); getline(cin, tenLuanVan);
            cout << "Nhap diem luan van: "; cin >> diemLuanVan;
            v[i] = new SinhVienDaiHoc(maSV, HoTen, diaChi, tongTC, dtb, tenLuanVan, diemLuanVan);
            if (tongTC >= 170 && dtb >= 5 && diemLuanVan >= 5) {
                totnghiep.push_back(v[i]);
            } else {
                Ktotnghiep.push_back(v[i]);
                b++;
            }
            if (best2 == nullptr || best2->getDtb() < dtb) {
                best2 = v[i];
            }
        }
    }

    // In toàn bộ danh sách nhập vào ban đầu
    for (SinhVien* i : v) {
        i->in();
        cout << '\n';
    }

    // In danh sách đủ điều kiện tốt nghiệp
    if (totnghiep.size() != 0) {
        cout << "Danh sach sinh vien du dieu kien tot nghiep: " << '\n';
        for (SinhVien* i : totnghiep) {
            i->in();
            cout << '\n';
        }
    }

    // In danh sách không đủ điều kiện tốt nghiệp
    if (Ktotnghiep.size() != 0) {
        cout << "Danh sach sinh vien khong du dieu kien tot nghiep: " << '\n';
        for (SinhVien* i : Ktotnghiep) {
            i->in();
            cout << '\n';
        }
    }

    // Thống kê sinh viên Đại học có ĐTB cao nhất
    if (best2 != nullptr) {
        cout << "Sinh vien dai hoc co diem trung binh cao nhat: " << '\n';
        best2->in();
        cout << '\n';
    }

    // Thống kê sinh viên Cao đẳng có ĐTB cao nhất
    if (best1 != nullptr) {
        cout << "Sinh vien cao dang co diem trung binh cao nhat: " << '\n';
        best1->in();
        cout << '\n';
    }

    // Xuất số lượng không đủ điều kiện tốt nghiệp của từng hệ
    cout << "So sinh vien dai hoc khong du dieu kien tot nghiep: " << b << '\n';
    cout << "So sinh vien cao dang khong du dieu kien tot nghiep: " << a << '\n';

    // Giải phóng bộ nhớ động để hoàn thiện code chuẩn, tránh rò rỉ bộ nhớ
    for (SinhVien* i : v) {
        delete i;
    }

    return 0;
}