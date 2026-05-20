#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class NhanVien {
protected:
    string ten;
    string ngaysinh;
    int luong;

public:
    virtual void Nhap();
    int getLuong();
    string getNgaySinh();
    virtual void Xuat();
    virtual void TinhLuong() = 0; 
    virtual ~NhanVien();
};


class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;

public:
    void Nhap() override;
    void TinhLuong() override;
};


class NhanVienSanXuat : public NhanVien {
private:
    int luongCoBan;
    int soSanPham;

public:
    void Nhap() override;
    void TinhLuong() override;
};


bool cmp(string x, string y);

#endif