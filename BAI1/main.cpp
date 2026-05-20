#include "NhanVien.h"

void inTieuDe(string noiDung) {
    cout << "\n===== " << noiDung << " =====\n";
}

int main() {
    int n;
    cout << "Nhap so nhan vien cua cong ty: "; 
    cin >> n;
    
    vector<NhanVien*> nhanvien(n);
    long long tong_luong = 0;
    NhanVien *A = nullptr, *B = nullptr; 

    for (int i = 0; i < n; i++) {
        bool d;
        cout << "\nChon loai (0: Nhan vien san xuat, 1: Nhan vien van phong): "; 
        cin >> d;
        
        if (d) {
            nhanvien[i] = new NhanVienVanPhong();
            cout << "Nhap thong tin nhan vien van phong:\n";
            nhanvien[i]->Nhap();
            nhanvien[i]->TinhLuong();
        } else {
            nhanvien[i] = new NhanVienSanXuat();
            cout << "Nhap thong tin nhan vien san xuat:\n";
            nhanvien[i]->Nhap();
            nhanvien[i]->TinhLuong();
        }
        
        tong_luong += nhanvien[i]->getLuong();
        
        // Tìm nhân viên sản xuất có lương thấp nhất
        if (d == false && (A == nullptr || A->getLuong() > nhanvien[i]->getLuong())) {
            A = nhanvien[i];
        }
        // Tìm nhân viên văn phòng có tuổi cao nhất (ngày sinh nhỏ nhất)
        if (d == true && (B == nullptr || cmp(nhanvien[i]->getNgaySinh(), B->getNgaySinh()))) {
            B = nhanvien[i];
        }
    }

    inTieuDe("DANH SÁCH NHÂN VIÊN");
    for (NhanVien* i : nhanvien) {
        i->Xuat();
    }

    inTieuDe("KẾT QUẢ THỐNG KÊ");
    cout << "Tong luong ma cong ty phai tra la: " << tong_luong << '\n' << '\n';

    if (A == nullptr) {
        cout << "Khong co nhan vien san xuat\n";
    } else {
        cout << "Nhan vien san xuat co luong thap nhat:\n";
        A->Xuat();
        cout << '\n';
    }

    if (B == nullptr) {
        cout << "Khong co nhan vien van phong\n";
    } else {
        cout << "Nhan vien van phong co tuoi cao nhat:\n";
        B->Xuat();
    }

    // Giải phóng bộ nhớ con trỏ
    for (NhanVien* i : nhanvien) {
        delete i;
    }
    
    return 0;
}