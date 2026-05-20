#include "GiaoDichBDS.h"
#include <iomanip>

using namespace std;

bool cmp(string s) {
    auto toInt = [&](int &i) {
        int k = 0;
        while (i < s.size() && s[i] != '/') {
            k = k * 10 + (int)(s[i] - '0');
            i++;
        }
        return k;
    };
    int i = 0;
    int dx = toInt(i); i++;
    int mx = toInt(i); i++;
    int yx = toInt(i); i++;
    if (yx == 2024 && mx == 12) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cout << "Nhap so luong giao dich: "; cin >> n;
    vector<GiaoDich*> v(n);
    vector<GiaoDich*> t1224;
    int a = 0, b = 0, c = 0;
    double s = 0, mx = 0;
    GiaoDich* best = nullptr;

    for (int i = 0; i < n; i++) {
        int d;
        cout << "(0:giao dich dat, 1: giao dich nha pho, 2: giao dich chung cu): "; cin >> d;
        string maGiaoDich, ngayGiaoDich;
        double donGia, dienTich, giaTri;
        cout << "Nhap ma giao dich: "; cin >> maGiaoDich;
        cout << "Nhap ngay giao dich: "; cin >> ngayGiaoDich;
        cout << "Nhap don gia: "; cin >> donGia;
        cout << "Nhap dien tich: "; cin >> dienTich;

        if (d == 0) {
            a++;
            char type;
            cout << "Nhap loai dat: "; cin >> type;
            v[i] = new GiaoDichDat(maGiaoDich, ngayGiaoDich, donGia, dienTich, type);
            giaTri = v[i]->thanhTien();
        }
        else if (d == 1) {
            b++;
            string loai, diaChi;
            cin.ignore();
            cout << "Nhap loai nha: "; getline(cin, loai);
            cout << "Nhap dia chi: "; getline(cin, diaChi);
            v[i] = new GiaoDichNhaPho(maGiaoDich, ngayGiaoDich, donGia, dienTich, loai, diaChi);
            giaTri = v[i]->thanhTien();
            if (giaTri > mx) {
                mx = giaTri;
                best = v[i];
            }
            s += giaTri;
        }
        else {
            c++;
            string maCan; int tang;
            cout << "Nhap ma can: "; cin >> maCan;
            cout << "Nhap so tang: "; cin >> tang;
            v[i] = new GiaoDichChungCu(maGiaoDich, ngayGiaoDich, donGia, dienTich, maCan, tang);
            giaTri = v[i]->thanhTien();
        }

        if (cmp(ngayGiaoDich)) {
            t1224.push_back(v[i]);
        }
    }


    cout << "So giao dich dat: " << a << '\n';
    cout << "So giao dich nha pho: " << b << '\n';
    cout << "So giao dich chung cu: " << c << '\n';
    cout << "Trung binh thanh tien cua giao dich nha pho: " << fixed << setprecision(2) << (b > 0 ? (double)s / b : 0) << '\n';
    cout << "Giao dich nha pho co gia tri cao nhat: " << mx << '\n';

    if (t1224.size() != 0) {
        cout << "Giao dich vao thang 12 nam 2024: " << '\n';
        for (GiaoDich* i : t1224) {
            i->in();
            cout << '\n';
        }
    }
    else {
        cout << "Khong co giao dich vao thang 12 nam 2024: " << '\n';
    }

    for (GiaoDich* i : v) {
        delete i;
    }

    return 0;
}