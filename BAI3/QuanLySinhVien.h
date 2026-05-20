#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class SinhVien {
protected:
    int maSV;
    string HoTen;
    string diaChi;
    int tongTC;
    double dtb;

public:
    SinhVien(int maSV, string HoTen, string diaChi, int tongTC, double dtb);
    virtual ~SinhVien();
    virtual void in() = 0;
    double getDtb() {
        return dtb;
    }
};


class SinhVienCaoDang : public SinhVien {
private:
    double diemTN;

public:
    SinhVienCaoDang(int maSV, string HoTen, string diaChi, int tongTC, double dtb, double diemTN);
    void in() override;
    ~SinhVienCaoDang() override;
};


class SinhVienDaiHoc : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;

public:
    SinhVienDaiHoc(int maSV, string HoTen, string diaChi, int tongTC, double dtb, string tenLuanVan, double diemLuanVan);
    void in() override;
    ~SinhVienDaiHoc() override;
};