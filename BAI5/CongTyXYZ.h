#ifndef CONGTYXYZ_H
#define CONGTYXYZ_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class KhachHang {
protected:
    string tenKH;
    int soLuongHang;
    double donGiaHang;

public:
    KhachHang();
    virtual ~KhachHang();

    virtual void docFile(ifstream& in);
    virtual void ghiFile(ofstream& out) const;
    virtual double tinhTienTra() const = 0; 

    string getTenKH() const;
};


class KhachHangA : public KhachHang {
public:
    double tinhTienTra() const override;
};

class KhachHangB : public KhachHang {
private:
    int soNamThanThiet;

public:
    void docFile(ifstream& in) override;
    double tinhTienTra() const override;
};

class KhachHangC : public KhachHang {
public:
    double tinhTienTra() const override;
};


class QuanLyMuaHang {
private:
    vector<KhachHang*> danhSachKH;

public:
    ~QuanLyMuaHang();
    void xuLyDuLieu(string fileIn, string fileOut);
};

#endif
