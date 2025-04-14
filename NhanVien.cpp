#include "NhanVien.h"

NhanVien::NhanVien()
{
	this->ID = 0;
	this->HoTen = "";
	this->NgayLam = "";
	this->ChucVu = "";
	this->NgayLamViec = 0;
	this->NgayPhepTichLuy = 0;
	this->NgayNghiKhongPhep = 0;
}

NhanVien::NhanVien(int ID, string HoTen, string NgayLam, string ChucVu, int NgayLamViec, int NgayPhepTichLuy, int NgayNghiKhongPhep)
{
	setID(ID);
	setHoTen(HoTen);
	setChucVu(ChucVu);
	setNgayLam(NgayLam);
	setNgayLamViec(NgayLamViec);
	setNgayPhepTichLuy(NgayPhepTichLuy);
	setNgayNghiKhongPhep(NgayNghiKhongPhep);
}

NhanVien::~NhanVien() {}

void NhanVien::setID(int ID)
{
	this->ID = ID;
}
int NhanVien::getID() const
{
	return this->ID;
}

void NhanVien::setHoTen(string HoTen)
{
	this->HoTen = HoTen;
}
string NhanVien::getHoTen() const
{
	return this->HoTen;
}

void NhanVien::setNgayLam(string NgayLam)
{
	this->NgayLam = NgayLam;
}
string NhanVien::getNgayLam() const
{
	return this->NgayLam;
}

void NhanVien::setNgayLamViec(int NgayLamViec)
{
	this->NgayLamViec = NgayLamViec;
}
int NhanVien::getNgayLamViec() const
{
	return this->NgayLamViec;
}

void NhanVien::setNgayPhepTichLuy(int NgayPhepTichLuy)
{
	this->NgayPhepTichLuy = NgayPhepTichLuy;
}
int NhanVien::getNgayPhepTichLuy() const
{
	return this->NgayPhepTichLuy;
}

void NhanVien::setNgayNghiKhongPhep(int NgayNghiKhongPhep)
{
	this->NgayNghiKhongPhep = NgayNghiKhongPhep;
}
int NhanVien::getNgayNghiKhongPhep() const
{
	return this->NgayNghiKhongPhep;
}

string NhanVien::DanhGia()
{
	if (this->NgayLamViec >= 20)
		return "Tot";
	else if (this->NgayLamViec >= 15)
		return "TrungBinh";
	else
		return "Yeu";
}

float NhanVien::HeSoLuong()
{
	float result = 0.0f;
	if (this->NgayLamViec / 260 > 10)
		result = 2.0f;
	else if (this->NgayLamViec / 260 > 5)
		result = 1.5f;
	else
		result = 1.0f;
	return result;
}

TruongPhong::TruongPhong()
{
	this->LuongCoBan = 0;
}

TruongPhong::TruongPhong(int ID, string HoTen, string NgayLam, string ChucVu, int NgayLamViec, int NgayPhepTichLuy, int NgayNghiKhongPhep, int LuongCoBan)
	: NhanVien(ID, HoTen, NgayLam, ChucVu, NgayLamViec, NgayPhepTichLuy, NgayNghiKhongPhep)
{
	this->LuongCoBan = LuongCoBan;
}

TruongPhong::~TruongPhong() {}

PhoPhong::PhoPhong()
{
	this->LuongCoBan = 0;
}

PhoPhong::PhoPhong(int ID, string HoTen, string NgayLam, string ChucVu, int NgayLamViec, int NgayPhepTichLuy, int NgayNghiKhongPhep, int LuongCoBan)
	: NhanVien(ID, HoTen, NgayLam, ChucVu, NgayLamViec, NgayPhepTichLuy, NgayNghiKhongPhep)
{
	this->LuongCoBan = LuongCoBan;
}

PhoPhong::~PhoPhong() {}

NhanVienVanPhong::NhanVienVanPhong()
{
	this->LuongCoBan = 0;
}

NhanVienVanPhong::NhanVienVanPhong(int ID, string HoTen, string NgayLam, string ChucVu, int NgayLamViec, int NgayPhepTichLuy, int NgayNghiKhongPhep, int LuongCoBan)
	: NhanVien(ID, HoTen, NgayLam, ChucVu, NgayLamViec, NgayPhepTichLuy, NgayNghiKhongPhep)
{
	this->LuongCoBan = LuongCoBan;
}

NhanVienVanPhong::~NhanVienVanPhong() {}

float TruongPhong::TinhLuong()
{
	float Luong = 0.0f;
	Luong = LuongCoBan * HeSoLuong();

	if (this->NgayNghiKhongPhep > 5)
		Luong -= 0.1f * LuongCoBan;
	else if (this->NgayNghiKhongPhep > 3)
		Luong -= 0.05f * LuongCoBan;
	else if (this->NgayNghiKhongPhep > 1)
		Luong -= 0.02f * LuongCoBan;
	return Luong;
}

float PhoPhong::TinhLuong()
{
	float Luong = 0.0f;
	Luong = LuongCoBan * HeSoLuong();
	if (this->NgayNghiKhongPhep > 5)
		Luong -= 0.1f * LuongCoBan;
	else if (this->NgayNghiKhongPhep > 3)
		Luong -= 0.05f * LuongCoBan;
	else if (this->NgayNghiKhongPhep > 1)
		Luong -= 0.02f * LuongCoBan;
	return Luong;
}

float NhanVienVanPhong::TinhLuong()
{
	float Luong = 0.0f;
	Luong = LuongCoBan * HeSoLuong();
	if (this->NgayNghiKhongPhep > 5)
		Luong -= 0.1f * LuongCoBan;
	else if (this->NgayNghiKhongPhep > 3)
		Luong -= 0.05f * LuongCoBan;
	else if (this->NgayNghiKhongPhep > 1)
		Luong -= 0.02f * LuongCoBan;
	return Luong;
}
