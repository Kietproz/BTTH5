#include "GiaoDichBDS.h"


GiaoDich::GiaoDich(string maGiaoDich, string ngayGiaoDich, double donGia, double dienTich) {
    this->maGiaoDich = maGiaoDich;
    this->ngayGiaoDich = ngayGiaoDich;
    this->donGia = donGia;
    this->dienTich = dienTich;
}


GiaoDichDat::GiaoDichDat(string maGiaoDich, string ngayGiaoDich, double donGia, double dienTich, char type) :
    GiaoDich(maGiaoDich, ngayGiaoDich, donGia, dienTich) {
    this->type = type;
}

double GiaoDichDat::thanhTien() {
    if (type == 'A') {
        return dienTich * donGia * 1.5;
    } else {
        return dienTich * donGia;
    }
}

void GiaoDichDat::in() {
    cout << "Ma giao dich: " << maGiaoDich << '\n';
    cout << "Ngay giao dich: " << ngayGiaoDich << '\n';
    cout << "Don gia: " << donGia << '\n';
    cout << "Dien tich: " << dienTich << '\n';
    cout << "Loai dat: " << type << '\n';
}


GiaoDichNhaPho::GiaoDichNhaPho(string maGiaoDich, string ngayGiaoDich, double donGia, double dienTich, string loai, string diaChi) :
    GiaoDich(maGiaoDich, ngayGiaoDich, donGia, dienTich) {
    this->loai = loai;   // Sửa lỗi logic thiếu gán thuộc tính 'loai' từ file cũ của bạn
    this->diaChi = diaChi; // Sửa lỗi logic thiếu gán thuộc tính 'diaChi' từ file cũ của bạn
}

double GiaoDichNhaPho::thanhTien() {
    if (loai == "cao cap") {
        return dienTich * donGia;
    } else {
        return dienTich * donGia * 0.9;
    }
}

void GiaoDichNhaPho::in() {
    cout << "Ma giao dich: " << maGiaoDich << '\n';
    cout << "Ngay giao dich: " << ngayGiaoDich << '\n';
    cout << "Don gia: " << donGia << '\n';
    cout << "Dien tich: " << dienTich << '\n';
    cout << "Loai nha: " << loai << '\n';
    cout << "Dia chi: " << diaChi << '\n';
}


GiaoDichChungCu::GiaoDichChungCu(string maGiaoDich, string ngayGiaoDich, double donGia, double dienTich, string maCan, int tang) :
    GiaoDich(maGiaoDich, ngayGiaoDich, donGia, dienTich) {
    this->maCan = maCan;
    this->tang = tang;
}

double GiaoDichChungCu::thanhTien() {
    if (tang == 1) {
        return dienTich * donGia * 2;
    } else if (tang >= 15) {
        return dienTich * donGia * 1.2;
    } else {
        return dienTich * donGia;
    }
}

void GiaoDichChungCu::in() {
    cout << "Ma giao dich: " << maGiaoDich << '\n';
    cout << "Ngay giao dich: " << ngayGiaoDich << '\n';
    cout << "Don gia: " << donGia << '\n';
    cout << "Dien tich: " << dienTich << '\n';
    cout << "Ma can: " << maCan << '\n';
    cout << "Vi tri tang: " << tang << '\n';
}