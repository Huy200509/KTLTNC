#include<iostream>
#include<string.h>
#include <fstream>
using namespace std;
bool ktra (int ngay, int thang, int nam){	
    int a;
    switch (thang){
    	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    		a = 31;
    		break;
    	case 4: case 6: case 9: case 11:
    		a = 30;
    		break;
    	case 2:
    		if((nam%4 == 0 && nam % 100 != 0) || (nam % 400 ==0 )){
    			a = 29;
    		}else {
    			a=28;
    		}
    		break;
    	default :
    		return false;
    }
    if (ngay >= 1 && ngay <= a) 
	return true;
}
class Nguoi {
	protected:
		string ID;
		string hoTen;
		int Ngay, Thang, Nam;
		string gioiTinh;
		//string diaChi;
		string sDT;
		string email;
	public:
		string getID();
		string getHoTen();
		int getngay(), getthang(), getnam();
		string getGioiTinh();
		//string getDiaChi();
		string getSDT();
		string getEmail();
		void setID(string ID);
		void setHoTen(string hoTen);
		void setNgay(int Ngay);
		void setThang(int Thang);
		void setNam(int Nam);
		void setGioiTinh(string gioiTinh);
		//void setDiaChi(string diaChi);
		void setSDT(string sDT);
		void setEmail(string email);
		Nguoi();
		Nguoi(string ID, string hoTen, int Ngay, int Thang, int Nam, string gioiTinh, string sDT, string email);
        ~Nguoi();
        //void Nhap();
        //void Xuat();
        virtual void NhapDiaChi() {}  
	    virtual void XuatDiaChi() {}
        virtual void Nhap();
	    virtual void Xuat();
	   // virtual bool isSVTT() { return false; }  
       // virtual bool isGVHD() { return false; }
        
};
string Nguoi::getID(){
	return ID;
}
string Nguoi::getHoTen(){
	return hoTen;
}
int Nguoi::getngay(){
	return Ngay;
}
int Nguoi::getthang(){
	return Thang;
}
int Nguoi::getnam(){
	return Nam;
}
string Nguoi::getGioiTinh(){
	return gioiTinh;
}
//string Nguoi::getDiaChi(){
//	return diaChi;
//}
string Nguoi::getSDT(){
	return sDT;
}
string Nguoi::getEmail(){
	return email;
}
void Nguoi::setID(string ID){
	this->ID = ID;
}
void Nguoi::setHoTen(string hoTen){
	this->hoTen = hoTen;
}
void Nguoi::setNgay(int Ngay){
	this->Ngay = Ngay;
}
void Nguoi::setThang(int Thang){
	this->Thang = Thang;
}
void Nguoi::setNam(int Nam){
	this->Nam = Nam;
}
void Nguoi::setGioiTinh(string gioiTinh){
	this->gioiTinh = gioiTinh;
}
//void Nguoi::setDiaChi(string diaChi){
//	this->diaChi = diaChi;
//}
void Nguoi::setSDT(string sDT){
	this->sDT = sDT;
}
void Nguoi::setEmail(string email){
	this->email = email;
}
Nguoi::Nguoi() {
	ID = "";
    hoTen = "";
    Ngay = 0;
    Thang = 0;
    Nam = 0;
    gioiTinh = "";
   // diaChi = "";
    sDT = "";
    email = "";
}
Nguoi::Nguoi(string ID, string hoTen, int Ngay, int Thang, int Nam, string gioiTinh, string sDT, string email){
	this->ID = ID;
	this->hoTen = hoTen;
	this->Ngay = Ngay;
	this->Thang = Thang;
	this->Nam = Nam;
	this->gioiTinh = gioiTinh;
	//this->diaChi = diaChi;
	this->sDT = sDT;
	this->email = email;
}
Nguoi::~Nguoi() { }
void Nguoi::Nhap(){
	    cin.ignore();
	cout << "Nhap ID(SV/GV): "; 
	getline(cin, ID);
    cout << "Nhap ho ten: "; 
	getline(cin, hoTen);
    do {
        cout << "Nhap ngay/thang/nam sinh: ";
        cin >> Ngay >> Thang >> Nam;
        cin.ignore();
    } while (!ktra(Ngay, Thang, Nam));
    cout << "Nhap gioi tinh: "; 
	getline(cin, gioiTinh);
    //cout << "Nhap dia chi: "; 
//	getline(cin, diaChi);
    cout << "Nhap SDT: "; 
	getline(cin, sDT);
    cout << "Nhap email: "; 
	getline(cin, email);	
}
void Nguoi::Xuat(){
	 cout <<"ID: " << ID<< "- Ho ten: " << hoTen << "- Ngay sinh: " << Ngay << "/" << Thang << "/" << Nam<< "- Gioi tinh: " << gioiTinh << "- SDT: " << sDT << "- Email: " << email << endl;
}
class GVHD : public Nguoi {
protected:
    string BoMon;
    string HocVi;
public:
	string getboMon();
	string gethocVi();
	void setboMon(string BoMon);
	void sethocVi(string HocVi);
    GVHD();
    GVHD(string ID, string hoTen, int Ngay, int Thang, int Nam, string gioiTinh, string sDT, string email, string MaGV, string BoMon, string HocVi);
	void Nhap();
	void Xuat();
//	bool isGVHD() { return true; }
};
string GVHD::getboMon(){
	return BoMon;
}
string GVHD::gethocVi(){
	return HocVi;
}	
void GVHD::setboMon(string BoMon){
	this->BoMon = BoMon;
}
void GVHD::sethocVi(string HocVi){
	this->HocVi = HocVi;
}

GVHD::GVHD(){
	Nguoi();
	BoMon = "";
	HocVi = "";
}
GVHD::GVHD(string ID, string hoTen, int Ngay, int Thang, int Nam, string gioiTinh, string sDT, string email, string MaGV, string BoMon, string HocVi){
    Nguoi(ID, hoTen, Ngay, Thang, Nam, gioiTinh, sDT, email);
    this->BoMon = BoMon;
    this->HocVi = HocVi;
}
void GVHD::Nhap(){
	Nguoi::Nhap();
    cout << "Nhap bo mon: "; 
	getline(cin, BoMon);
    cout << "Nhap hoc vi: "; 
	getline(cin, HocVi);
}
void GVHD::Xuat(){
	Nguoi::Xuat();
    cout <<"- Bo mon: " << BoMon << "- Hoc vi: " << HocVi << endl;
}
class SVTT : public Nguoi{
	protected:
		string diaChi;
		string Truong;
		string Nganh;
		float GPA;
		string Cty;
		string vtri;
		string phong;
		int NgayBD, ThangBD, NamBD;
	    int NgayKT, ThangKT, NamKT;
		string danhgia;
		
	public:
		string gettruong();
		string getnganh();
		float getgpa();
		string getCty();
		string getViTri();
		string getPhong();
		int getNgayBD(), getThangBD(), getNamBD();
		int getNgayKT(), getThangKT(), getNamKT();
		string getDanhGia();
		
		void settruong(string Truong);
		void setnganh(string Nganh);
		void setgpa(float GPA);
		void setCty(string Cty);
		void setViTri(string vtri);
		void setPhong(string phong);
		void setNgayBD(int NgayBD), setThangBD( int ThangBD), setNamBD(int NamBD);
		void setNgayKT(int NgayKT), setThangKT(int ThangKT), setNamKT(int NamKT);
		void setDanhGia(string danhgia);
		
		SVTT();
		SVTT(string ID, string hoTen, int Ngay, int Thang, int Nam, string gioiTinh, string diaChi, string sDT, string email, string MSSV, string Truong, string Nganh, float GPA);
		void Nhap();
        void Xuat();
        virtual void NhapDiaChi() {
		cout << "Nhap dia chi: ";
		getline(cin, diaChi);
	    }
        virtual void XuatDiaChi() {
		cout << "Dia chi: " << diaChi << endl;
	    }
	    //bool isSVTT() { return true; } 
};
string SVTT::gettruong(){
	return Truong;
}
string SVTT::getnganh(){
	return Nganh;
}
float SVTT::getgpa(){
	return GPA;
}
string SVTT::getCty(){ 
    return Cty; 
}
string SVTT::getViTri(){ 
    return vtri; 
}
string SVTT::getPhong(){ 
    return phong; 
}
int SVTT::getNgayBD(){ 
    return NgayBD; 
}
int SVTT::getThangBD(){
    return ThangBD;
}
int SVTT::getNamBD(){ 
    return NamBD; 
}
int SVTT::getNgayKT(){ 
    return NgayKT; 
}
int SVTT::getThangKT(){ 
    return ThangKT; 
}
int SVTT::getNamKT(){ 
    return NamKT; 
}
string SVTT::getDanhGia(){ 
    return danhgia; 
}

void SVTT::settruong(string Truong){
	this->Truong = Truong;
}
void SVTT::setnganh(string Nganh){
	this->Nganh = Nganh;
}
void SVTT::setgpa(float GPA){
	this->GPA = GPA;
}
void SVTT::setCty(string Cty){ 
    this->Cty = Cty;
}
void SVTT::setViTri(string vtri){ 
    this->vtri = vtri; 
}
void SVTT::setPhong(string phong){ 
    this->phong = phong; 
}
void SVTT::setNgayBD(int NgayBD){ 
    this->NgayBD = NgayBD; 
}
void SVTT::setThangBD(int ThangBD){ 
   this->ThangBD = ThangBD; 
}
void SVTT::setNamBD(int NamBD){ 
   this->NamBD = NamBD; 
}
void SVTT::setNgayKT(int NgayKT){ 
   this->NgayKT = NgayKT; 
}
void SVTT::setThangKT(int ThangKT){ 
   this->ThangKT = ThangKT; 
}
void SVTT::setNamKT(int NamKT){ 
   this->NamKT = NamKT; 
}
void SVTT::setDanhGia(string danhgia){ 
   this->danhgia = danhgia; 
}

SVTT::SVTT(){
	Nguoi();
	Truong = "";
	Nganh = "";
	GPA = 0;
	Cty = "";
	vtri = "";
	phong = "";
	NgayBD = 0 , ThangBD = 0, NamBD = 0;
	NgayKT = 0, ThangKT = 0, NamKT = 0;
	danhgia = "";
}
SVTT::SVTT(string ID, string hoTen, int Ngay, int Thang, int Nam, string gioiTinh, string diaChi, string sDT, string email, string MSSV, string Truong, string Nganh, float GPA){
	Nguoi(ID, hoTen, Ngay, Thang, Nam, gioiTinh, sDT, email);
	this->Truong = Truong;
	this->Nganh = Nganh;
	this->GPA = GPA;
	this->Cty = Cty;
    this->vtri = vtri;
    this->phong = phong;
    this->NgayBD = NgayBD;
    this->ThangBD = ThangBD;
    this->NamBD = NamBD;
    this->NgayKT = NgayKT;
    this->ThangKT = ThangKT;
    this->NamKT = NamKT;
    this->danhgia = danhgia;
}
void SVTT::Nhap(){
	Nguoi::Nhap();
	NhapDiaChi();
    cout << "Nhap truong: "; 
	getline(cin, Truong);
    cout << "Nhap nganh: "; 
	getline(cin, Nganh);
    while (true) {
        cout << "Nhap GPA (0.0 - 4.0): ";
        cin >> GPA;
        if (GPA >= 0.0 && GPA <= 4.0) {
            break;
        } else {
            cout << "GPA phai trong khoang 0.0 - 4.0. Vui long nhap lai.\n";
        }
    }
    cin.ignore();
    cout << "Nhap cong ty: "; 
	getline(cin, Cty);
    cout << "Nhap vi tri: "; 
	getline(cin, vtri);
    cout << "Nhap phong ban: "; 
	getline(cin, phong);
    do {
    cout << "Nhap ngay bat dau (ngay thang nam): ";
    cin >> NgayBD >> ThangBD >> NamBD;
    cin.ignore();
    } while (!ktra(NgayBD, ThangBD, NamBD));

    do {
    cout << "Nhap ngay ket thuc (ngay thang nam): ";
    cin >> NgayKT >> ThangKT >> NamKT;
    cin.ignore();
    } while (!ktra(NgayKT, ThangKT, NamKT));
    cout << "Nhap danh gia: "; 
	getline(cin, danhgia);
	
}
void SVTT::Xuat(){
	Nguoi::Xuat();
	XuatDiaChi();
    cout <<"Truong: " << Truong << "- Nganh: " << Nganh << "- GPA: " << GPA << endl;
	cout << "Cong ty: " << Cty << " - Vi tri: " << vtri << " - Phong: " << phong << endl;
    cout << "Thoi gian: " << NgayBD << "/" << ThangBD << "/" << NamBD << " den "<< NgayKT << "/" << ThangKT << "/" << NamKT << endl;
	cout << "Danh gia: " << danhgia << endl;
	
}

struct Node {
    Nguoi* data;
    Node* next;
};
class List {
private:
    Node* head; 
    Node* tail; 
    int size;  

public: 
    List(); 
    Node* createNode(Nguoi* x); 
    bool Empty();
    void Themsvdauds(Nguoi* x);
    void Themsvcuoids(Nguoi* x);
    void Themsvbatki(Nguoi* x, int pos);
    void deleteFirst(); 
    void deleteLast(); 
    void xoabatki(int pos);
    void print();
    bool check(const string& ID);
    void SapxepID();
    void saveToFile(const char* filename);
    void loadFromFile(const char* filename);
};

List::List() {
    head = tail = NULL;
    size = 0;
}

bool List::Empty() {
    return head == NULL; 
}

Node* List::createNode(Nguoi* x) {
    Node* p = new Node();
    p->data = x;
    p->next = NULL;
    return p;
}

void List::Themsvcuoids(Nguoi* x) {
    Node* p = createNode(x);
    if (head == NULL) {
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
    size++;
}

void List::Themsvdauds(Nguoi* x) {
    Node* p = createNode(x);
    if (head == NULL) {
        head = tail = p;
    } else {
        p->next = head;
        head = p;
    }
    size++;
}

void List::Themsvbatki(Nguoi* x, int pos) {
    if (pos < 1 || pos > size + 1) {
        printf("Vi tri khong hop le\n");
        return;
    }
    
    Node* p = createNode(x);
    if (Empty()) {
        head = tail = p;
    } else if (pos == 1) {
        Themsvdauds(x);
    } else if (pos == size + 1) {
        Themsvcuoids(x);
    } else {
        Node* a = head;
        for (int i = 1; i < pos - 1; i++) {
            a = a->next;
        }
        p->next = a->next;
        a->next = p;
        size++;
    }
}

bool List::check(const string& ID) {
    for (Node* p = head; p != NULL; p = p->next) {
        if (p->data->getID() == ID) {
            return true; 
        }
    }
    return false;
}

void List::deleteFirst() {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
    size--;
    if (head == NULL) {
        tail = NULL;
    }
}

void List::deleteLast() {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    if (head == tail) {
        deleteFirst();
        return;
    } else {
        Node* a = head;
        for (int i = 1; i < size - 1; i++) {
            a = a->next;
        }
        delete tail;
        a->next = NULL;
        tail = a;
        size--;
    }
}

void List::xoabatki(int pos) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    if (pos < 1 || pos > size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    if (pos == 1) {
        deleteFirst();
        return;
    }
    if (pos == size) {
        deleteLast();
        return;
    }
    Node* a = head;
    for (int i = 1; i < pos - 1; i++) {
        a = a->next;
    }
    Node* temp = a->next;
    a->next = temp->next;
    delete temp;
    size--;
}
void List::SapxepID() { 
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    for (Node* i = head; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data->getID() > j->data->getID()) { 
                Nguoi* temp = i->data; 
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("\n => Danh sach da duoc sap xep theo ID tang dan:\n");
}
void List::print() {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    for (Node* p = head; p != NULL; p = p->next) {
        p->data->Xuat(); 
    }
}
int main() {
    List danhSach; 
    int luaChon;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them sinh vien va giang vien\n";
        cout << "2. Xem danh sach\n";
        cout << "3. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();  

        switch (luaChon) {
            case 1: {
                SVTT* svtt = new SVTT();
                svtt->Nhap();
                danhSach.Themsvcuoids(svtt);  
	            GVHD* gvhd = new GVHD();
                gvhd->Nhap();
                danhSach.Themsvcuoids(gvhd);
                break;
            }
            case 2: {
                cout << "\nDanh sach:\n";
                danhSach.print();  
                break;
            }
            case 3:
                cout << "Thoat chuong trinh\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai!\n";
        }
    } while (luaChon != 3); 
    return 0;
}



