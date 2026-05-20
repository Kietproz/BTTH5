#ifndef CONGTY_H
#define CONGTY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhanVien {
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string sdt;
    string email;
    double luongCoBan;

public:
    NhanVien();
    virtual ~NhanVien();

    virtual void nhap();
    virtual void xuat() const;
    virtual double tinhLuong() const = 0;


    string getMaNV() const;
    string getHoTen() const;
    virtual string getLoai() const = 0;
};


class LapTrinhVien : public NhanVien {
private:
    int soGioOvertime;

public:
    void nhap() override;
    void xuat() const override;
    double tinhLuong() const override;
    string getLoai() const override;
};


class KiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;

public:
    void nhap() override;
    void xuat() const override;
    double tinhLuong() const override;
    string getLoai() const override;
};


class QuanLyCongTy {
private:
    vector<NhanVien*> danhSachNV;

public:
    ~QuanLyCongTy();
    void nhapDanhSach();
    void xuatDanhSach() const;
    double tinhLuongTrungBinh() const;
    void xuatNVLuongThapHonTrungBinh() const;
    void xuatNVLuongCaoNhat() const;
    void xuatNVLuongThapNhat() const;
    void xuatLapTrinhVienLuongCaoNhat() const;
};

#endif
