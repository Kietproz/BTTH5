#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class GiaoDich {
protected:
    string maGiaoDich;
    string ngayGiaoDich;
    double donGia;
    double dienTich;
public:
    GiaoDich(string maGiaoDich, string ngayGiaoDich, double donGia, double dienTich);
    virtual double thanhTien() = 0;
    virtual void in() = 0;
    virtual ~GiaoDich() {} 
};


class GiaoDichDat : public GiaoDich {
private:
    char type;
public:
    GiaoDichDat(string maGiaoDich, string ngayGiaoDich, double donGia, double dienTich, char type);
    double thanhTien() override;
    void in() override;
};

class GiaoDichNhaPho : public GiaoDich {
private:
    string loai;
    string diaChi;
public:
    GiaoDichNhaPho(string maGiaoDich, string ngayGiaoDich, double donGia, double dienTich, string loai, string diaChi);
    double thanhTien() override;
    void in() override;
};


class GiaoDichChungCu : public GiaoDich {
private:
    string maCan;
    int tang;
public:
    GiaoDichChungCu(string maGiaoDich, string ngayGiaoDich, double donGia, double dienTich, string maCan, int tang);
    double thanhTien() override;
    void in() override;
};