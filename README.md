#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkedList;

class Nguoi {
protected:
    string id, name, password;
public:
    Nguoi();
    Nguoi(string id, string name, string password);
    void nhap();
    void xuat();
    string getID();
    string getName();
    string getPassword();
    void setName(string newName);
    void setID(string newID);
	void setPassword(string pw);
    void doiMatKhau();
    template <typename T>
    void nhapIDKhongTrung(LinkedList<T*>& ds);
};

Nguoi::Nguoi() { 
	id = ""; 
	name = ""; 
	password = "";
}
Nguoi::Nguoi(string id, string name, string password) {
	this->id = id;
	this->name = name; 
	this->password = password;
}
string Nguoi::getID(){ 
    return id; 
}
string Nguoi::getName() { 
    return name; 
}
string Nguoi::getPassword() { 
    return password; 
}
void Nguoi::setName(string newName) { 
    this->name = newName; 
}
void Nguoi::setID(string newID) { 
    this->id = newID; 
}
void Nguoi::setPassword(string pw) { 
    this->password = pw; 
}
void Nguoi::doiMatKhau() {
    string mkcu, mkmoi;
    cout << "Nhap mat khau cu: "; 
	getline(cin, mkcu);
    if (mkcu == password) {  
        cout << "Nhap mat khau moi: "; 
		getline(cin, mkmoi);
        password = mkmoi;
        cout << "Mat khau da duoc cap nhat.\n";
    } else {
        cout << "Sai mat khau cu.\n";
    }
}

void Nguoi::nhap() {
    //cout << "Nhap ID: "; 
	//getline(cin, id);
    cout << "Nhap ten: ";
	getline(cin, name);
	cout << "Nhap mat khau: "; 
	getline(cin, password);
}
void Nguoi::xuat() {
    cout << "ID: " << id << ", Ten: " << name;
}

template <typename T>
void Nguoi::nhapIDKhongTrung(LinkedList<T*>& ds) {
    while (true) {
        cout << "Nhap ID: ";
        getline(cin, id);
        if (ds.kiemTraTrungID(id)) {
            cout << "ID da ton tai.Nhap ID khac.\n";
        } else {
            break;
        }
    }
}

class GVHD : public Nguoi {
private:
    string email, boMon, hocVi;
public:
    GVHD();
    GVHD(string id, string name,string password, string email, string boMon, string hocVi);
    void nhap(LinkedList<GVHD*>& dsGV);
    void xuat();
    void setEmail(string email);
    void setBoMon(string boMon);
    void setHocVi(string hocVi);
    string getemail();
    string getBoMon();
    string getHocVi();
};

GVHD::GVHD() : Nguoi() { 
	email = ""; 
	boMon = ""; 
	hocVi = ""; 
}
GVHD::GVHD(string id, string name,string password, string email, string boMon, string hocVi): Nguoi(id, name, password) {
    this->email = email;
    this->boMon = boMon;
    this->hocVi = hocVi;
}
void GVHD::setEmail(string email) { this->email = email; }
void GVHD::setBoMon(string boMon) { this->boMon = boMon; }
void GVHD::setHocVi(string hocVi) { this->hocVi = hocVi; }
string GVHD::getemail() { return email; }
string GVHD::getBoMon() { return boMon; }
string GVHD::getHocVi() { return hocVi; }
void GVHD::nhap(LinkedList<GVHD*>& dsGV) {
    nhapIDKhongTrung(dsGV);
    Nguoi::nhap();
    //cout << "Nhap ten: "; getline(cin, name);
    //cout << "Nhap mat khau: "; getline(cin, password);
    cout << "Nhap email: "; getline(cin, email);
    cout << "Nhap bo mon: "; getline(cin, boMon);
    cout << "Nhap hoc vi: "; getline(cin, hocVi);
}
void GVHD::xuat() {
    Nguoi::xuat();
    cout << ", Email: " << email << ", Bo mon: " << boMon << ", Hoc vi: " << hocVi << endl;
}

class SVTT : public Nguoi {
private:
    string deTai, nhanXet;
    float diem;
    string idGVHD, nameGV;
    GVHD* gvhd;
public:
    SVTT();
    SVTT(string id, string name,string password, string deTai, string nhanXet, float diem);
    void setGVHD(GVHD* gv);
    void nhapDeTai();
    void setDeTai(string& detai);
    void setNhanXet(string nhanXet);
    float setGPA(float diem);
    string getDeTai();
    string getNhanXet();
    float getGPA();
    void nhap(LinkedList<SVTT*>& dsSV);
    void xuat();
    void capNhatDiem(float d);
    void capNhatNhanXet(string nx);
    string getIDGVHD();
    string getnameGV();
    void setGVHD(string id, string name);
};

SVTT::SVTT() : Nguoi() { 
	deTai = ""; 
	nhanXet = ""; 
	diem = 0; 
	gvhd = NULL; 
}
SVTT::SVTT(string id, string name,string password, string deTai, string nhanXet, float diem)
    : Nguoi(id, name, password) {
    this->deTai = deTai;
    this->nhanXet = nhanXet;
    this->diem = diem;
    gvhd = NULL;
}
void SVTT::setGVHD(GVHD* gv) {
    gvhd = gv;
    idGVHD = gv->getID();
    nameGV = gv->getName();
}
void SVTT::setDeTai(string& detai){ 
    this->deTai = detai;
}
void SVTT::setNhanXet(string nhanXet) { 
    this->nhanXet = nhanXet; 
}
string SVTT::getDeTai(){
    return deTai; 
}
string SVTT::getNhanXet(){ 
    return nhanXet; 
}
float SVTT::getGPA(){ 
    return diem; 
}
void SVTT::nhap(LinkedList<SVTT*>& dsSV) {
    nhapIDKhongTrung(dsSV);
    Nguoi::nhap();
    //cout << "Nhap ten: "; getline(cin, name);
    //cout << "Nhap mat khau: "; getline(cin, password);
}

void SVTT::nhapDeTai() {
    cout << "Nhap ten de tai: ";
    getline(cin, deTai);
}
void SVTT::xuat() {
    Nguoi::xuat();
    if (gvhd != NULL) {
        cout << ", De tai: " << deTai << ", GVHD: " << gvhd->getID() << "-" << gvhd->getName()
             << ", Diem: " << diem << ", Nhan xet: " << nhanXet << endl;
    } else {
        cout << ", De tai: " << deTai << ", Chua co giang vien huong dan, Diem: " << diem
             << ", Nhan xet: " << nhanXet << endl;
    }
}
void SVTT::capNhatDiem(float d) { diem = d; }
void SVTT::capNhatNhanXet(string nx) { nhanXet = nx; }
string SVTT::getIDGVHD() { return idGVHD; }
string SVTT::getnameGV() { return nameGV; }
void SVTT::setGVHD(string id, string name) { 
	idGVHD = id; 
	nameGV = name; 
}
bool soSanhTenNguoi(Nguoi* a, Nguoi* b) {
    string sa = a->getName() + " "; 
    string sb = b->getName() + " ";
    int ia = sa.length() - 1;
    int ib = sb.length() - 1;
    while (ia >= 0 || ib >= 0) {
        string wa = "", wb = "";
        while (ia >= 0 && sa[ia] == ' ') ia--;
        while (ia >= 0 && sa[ia] != ' ') wa = sa[ia--] + wa;
        while (ib >= 0 && sb[ib] == ' ') ib--;
        while (ib >= 0 && sb[ib] != ' ') wb = sb[ib--] + wb;
        if (wa != wb)
            return wa < wb;
    }
    if (ia < 0 && ib >= 0) return true;   
    if (ib < 0 && ia >= 0) return false;  
    return false;                         
}
template <class T>
struct Node {
    T data;
    Node<T>* next;
};

template <class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    LinkedList() { head = tail = NULL; size = 0; }
    Node<T>* getHead() { return head; }
    int getSize() { return size; }

    void addLast(T v) {
        Node<T>* newNode = new Node<T>;
        newNode->data = v;
        newNode->next = NULL;
        if (!head) head = tail = newNode;
        else { tail->next = newNode; tail = newNode; }
        size++;
    }

    void duyetds() {
        Node<T>* temp = head;
        while (temp) {
            temp->data->xuat();
            temp = temp->next;
        }
    }

    T TimId(string& id) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data->getID() == id)
                return temp->data;
            temp = temp->next;
        }
        return NULL;
    }

    void XoaId(string& id) {
        if (!head) return;
        if (head->data->getID() == id) {
            Node<T>* d = head;
            head = head->next;
            delete d->data;
            delete d;
            size--;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) {
            if (temp->next->data->getID() == id) {
                Node<T>* d = temp->next;
                temp->next = temp->next->next;
                if (d == tail) tail = temp;
                delete d->data;
                delete d;
                size--;
                return;
            }
            temp = temp->next;
        }
    }
    bool kiemTraTrungID(string& id) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data->getID() == id)
                return true; 
            temp = temp->next;
        }
        return false; 
    }
    void sapXepTheoID() {
        if (!head) return;
        for (Node<T>* i = head; i; i = i->next)
            for (Node<T>* j = i->next; j; j = j->next)
                if (i->data->getID() > j->data->getID()){
                    T temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
    }

    void sapXepTheoTen() {
        if (!head) return;
        for (Node<T>* i = head; i; i = i->next)
            for (Node<T>* j = i->next; j; j = j->next)
                if (!soSanhTenNguoi(i->data, j->data)) {
                    T temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
    }
};

void menuSinhVien_Admin(LinkedList<SVTT*>& svList) {
    int chon;
    do {
        cout << "\n--- Quan ly Sinh vien ---\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xoa sinh vien\n";
        cout << "3. Sua sinh vien\n";
        cout << "4. Hien thi danh sach\n";
        cout << "5. Sap xep danh sach\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> chon; cin.ignore();
        switch (chon) {
            case 1: {
                SVTT* sv = new SVTT();
                sv->nhap(svList);
                svList.addLast(sv);
                cout << "Them sinh vien thanh cong.\n";
                break;
            }
            case 2: {
                string id;
                cout << "Nhap ID sinh vien can xoa: ";
                getline(cin, id);
                svList.XoaId(id);
                cout << "Xoa thanh cong.\n";
                break;
            }
            case 3: {
                string id;
                cout << "Nhap ID sinh vien can sua: ";
                getline(cin, id);
                SVTT* sv = svList.TimId(id);
                if (sv) {
                    int chon1;
                    cout << "1. Sua ten\n2. Sua ID\n3. Sua de tai\n4. Sua diem\n";
                    cout << "Nhap lua chon: ";
                    cin >> chon1; cin.ignore();
                    switch (chon1) {
                        case 1: {
                            string newName;
                            cout << "Nhap ten moi: "; 
							getline(cin, newName);
                            sv->setName(newName);
                            break;
                        }
                        case 2: {
                            string newID;
                            cout << "Nhap ID moi: "; 
							getline(cin, newID);
                            if (svList.kiemTraTrungID(newID)) {
                                cout << "ID da ton tai.\n";
                                break;
                            }
                            sv->setID(newID);
                            break;
                        }
                        case 3: {
                            string dt;
                            cout << "Nhap de tai moi: "; 
							getline(cin, dt);
                            sv->setDeTai(dt);
                            break;
                        }
                        case 4: {
                            float diem;
                            do {
					            cout << "Nhap diem (0 - 10): ";
					            cin >> diem;
					            if (diem < 0 || diem > 10) {
					                cout << "Diem khong hop le. Vui long nhap lai!\n";
					            }
					        } while (diem < 0 || diem > 10); 
							cin.ignore();
                            sv->capNhatDiem(diem);
                            break;
                        }
                        default: cout << "Lua chon khong hop le.\n";
                    }
                } else cout << "Khong tim thay sinh vien.\n";
                break;
            }
            case 4:
                svList.duyetds();
                break;
            case 5: {
                int c;
                cout << "1. Theo ID\n2. Theo ten\nChon: "; 
				cin >> c; 
				cin.ignore();
                if (c == 1) svList.sapXepTheoID();
                else if (c == 2) svList.sapXepTheoTen();
                else cout << "Lua chon khong hop le.\n";
                break;
            }
        }
    } while (chon != 0);
}

void menuGiangVien_Admin(LinkedList<GVHD*>& gvList) {
    int chon;
    do {
        cout << "\n--- Quan ly Giang vien ---\n";
        cout << "1. Them giang vien\n";
        cout << "2. Xoa giang vien\n";
        cout << "3. Sua giang vien\n";
        cout << "4. Hien thi danh sach\n";
        cout << "5. Sap xep danh sach\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> chon; cin.ignore();
        switch (chon) {
            case 1: {
                GVHD* gv = new GVHD();
                gv->nhap(gvList);
                gvList.addLast(gv);
                cout << "Them giang vien thanh cong.\n";
                break;
            }
            case 2: {
                string id;
                cout << "Nhap ID giang vien can xoa: ";
                getline(cin, id);
                gvList.XoaId(id);
                cout << "Xoa thanh cong.\n";
                break;
            }
            case 3: {
                string id;
                cout << "Nhap ID giang vien can sua: ";
                getline(cin, id);
                GVHD* gv = gvList.TimId(id);
                if (gv) {
                    int chon1;
                    cout << "1. Sua ten\n2. Sua email\n3. Sua bo mon\n4. Sua hoc vi\n5. Sua ID\n";
                    cout << "Nhap lua chon: ";
                    cin >> chon1; 
					cin.ignore();
                    switch (chon1) {
                        case 1: {
                            string ten; 
							cout << "Nhap ten moi: "; 
							getline(cin, ten);
                            gv->setName(ten); 
							break;
                        }
                        case 2: {
                            string email; 
							cout << "Nhap email moi: "; 
							getline(cin, email);
                            gv->setEmail(email); 
							break;
                        }
                        case 3: {
                            string bm; 
							cout << "Nhap bo mon moi: "; 
							getline(cin, bm);
                            gv->setBoMon(bm); 
							break;
                        }
                        case 4: {
                            string hv; 
							cout << "Nhap hoc vi moi: "; 
							getline(cin, hv);
                            gv->setHocVi(hv); 
							break;
                        }
                        case 5: {
                            string newID;
                            cout << "Nhap ID moi: "; 
							getline(cin, newID);
                            if (gvList.kiemTraTrungID(newID)) {
                                cout << "ID da ton tai.\n";
                                break;
                            }
                            gv->setID(newID);
                            break;
                        }
                        default: cout << "Lua chon khong hop le.\n";
                    }
                } else cout << "Khong tim thay giang vien.\n";
                break;
            }
            case 5: {
                int c;
                cout << "1. Theo ID\n2. Theo ten\nChon: "; 
				cin >> c; 
				cin.ignore();
                if (c == 1){
			        gvList.sapXepTheoID();
			    }
                else if (c == 2){
				    gvList.sapXepTheoTen();
				}
                else cout << "Lua chon khong hop le.\n";
                break;
            }
            case 4:
                gvList.duyetds();
                break;
        }
    } while (chon != 0);
}

void menuAdmin(LinkedList<SVTT*>& svList, LinkedList<GVHD*>& gvList) {
    int chon;
    do {
        cout << "\n========== MENU ADMIN ==========";
        cout << "\n1. Quan ly sinh vien";
        cout << "\n2. Quan ly giang vien";
        cout << "\n0. Dang xuat";
        cout << "\nNhap lua chon: ";
        cin >> chon; cin.ignore();
        switch (chon) {
            case 1:
                menuSinhVien_Admin(svList);
                break;
            case 2:
                menuGiangVien_Admin(gvList);
                break;
            case 0:
                cout << "Dang xuat Admin.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (chon != 0);
}

void menuSinhVien(SVTT* sv, LinkedList<GVHD*>& gvList) {
    int chon;
    do {
        cout << "\n******************* Menu Sinh Vien *******************\n";
        cout << "1. Nhap de tai\n";
        cout << "2. Chon giang vien huong dan\n";
        cout << "3. Xem thong tin sinh vien\n";
        cout << "4. Doi mat khau\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();
        switch (chon) {
            case 1: {
                string detai;
                cout << "Nhap de tai thuc tap: ";
                getline(cin, detai);
                sv->setDeTai(detai); 
                cout << "De tai da duoc nhap thanh cong.\n";
                break;
            }
            case 2: {
            	cout << "======================================================\n";
                cout << "******************Danh sach giang vien***************\n";
			    gvList.duyetds(); 
			    cout << "======================================================\n";
			    string gvID;
			    cout << "Nhap ID giang vien huong dan: ";
			    getline(cin, gvID);
			
			    GVHD* gv = gvList.TimId(gvID);
			    if (gv) {
			        sv->setGVHD(gv); 
			        cout << "Giang vien " << gv->getName() << " da duoc chon lam huong dan.\n"; 
			    } else {
			        cout << "Khong tim thay giang vien co ID: " << gvID << endl;
			    }
			    break;
            }
            case 3: {
                sv->xuat(); 
                break;
            }
            case 4: {
                sv->doiMatKhau();
                break;
			}
            case 0:
                cout << "Thoat menu sinh vien.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (chon != 0);
}

void menuGiangVien(GVHD* gv, LinkedList<SVTT*>& svList) {
    int chon;
    do {
        cout << "\n******************* MENU GIANG VIEN *******************\n";
        cout << "1. Xem danh sach sinh vien huong dan\n";
        cout << "2. Nhap nhan xet va diem cho sinh vien\n";
        cout << "3. Sua thong tin\n";
        cout << "4. Doi mat khau tk\n";
        cout << "0. Dang xuat\n";
        cout << "Chon: ";
        cin >> chon;

        switch (chon) {
            case 1: {
                cout << "\nDanh sach sinh vien duoc huong dan:\n";
			    Node<SVTT*>* temp = svList.getHead();
			    bool found = false;
			    while (temp != NULL) {
			        if (temp->data->getIDGVHD() == gv->getID()) {
			            temp->data->xuat();
			            found = true;
			        }
			        temp = temp->next;
			    }
			    if (!found) {
			        cout << "Khong co sinh vien nao!\n";
			    }
			    break;
            }
            case 2: {
                string studentID;
                cout << "Nhap ID sinh vien: ";
                cin.ignore();
                getline(cin, studentID);

                SVTT* sv = svList.TimId(studentID);
                if (sv) {
                    string nhanXet;
                    float diem;
                    cout << "Nhap nhan xet: ";
                    getline(cin, nhanXet);
                    do {
			            cout << "Nhap diem (0 - 10): ";
			            cin >> diem;
			            if (diem < 0 || diem > 10) {
			                cout << "Diem khong hop le. Vui long nhap lai!\n";
			            }
			        } while (diem < 0 || diem > 10);
                    sv->capNhatNhanXet(nhanXet);
                    sv->capNhatDiem(diem);
                    cout << "Cap nhat nhan xet va diem thanh cong.\n";
                } else {
                    cout << "Khong tim thay sinh vien.\n";
                }
                break;
            }
            case 3: {
			    string svID;
			    cout << "Nhap ID sinh vien muon sua diem va nhan xet: ";
			    cin.ignore(); 
			    getline(cin, svID);
			    SVTT* sv = svList.TimId(svID);
			    if (sv && sv->getIDGVHD() == gv->getID()) { 
			        float newGPA;
			        string newComment;
			        do {
			            cout << "Nhap diem moi cho sinh vien " << sv->getName() << " (0 - 10): ";
			            cin >> newGPA;
			            if (newGPA < 0 || newGPA > 10) {
			                cout << "Diem khong hop le. Vui long nhap lai!\n";
			            }
			        } while (newGPA < 0 || newGPA > 10);
        			cin.ignore(); 
			        sv->capNhatDiem(newGPA);
			        cout << "Nhap nhan xet cho sinh vien " << sv->getName() << ": ";
			        getline(cin, newComment);
			        sv->capNhatNhanXet(newComment); 
			        cout << "Diem va nhan xet da duoc cap nhat cho sinh vien " << sv->getName() << ".\n";
			    } else {
			        cout << "Khong tim thay sinh vien hoac sinh vien khong thuoc giang vien nay.\n";
			    }
			    break;
			}
			case 4:{
				cin.ignore();
                gv->doiMatKhau();
                break;
			}
            case 0:
                cout << "Dang xuat\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (chon != 0);
}

int main() {
    LinkedList<SVTT*> svList;
    LinkedList<GVHD*> gvList;
    string adminID = "admin";
    string adminPass = "123";
    int lc;
    do {
        cout << "\n===== He thong quan ly thuc tap =====\n";
        cout << "1. Dang nhap Admin\n";
        cout << "2. Dang nhap Sinh vien\n";
        cout << "3. Dang nhap Giang vien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> lc; cin.ignore();
        switch (lc) {
            case 1: {
                string id, pw;
                cout << "Nhap ten dang nhap admin: "; 
				getline(cin, id);
                cout << "Nhap mat khau: "; 
				getline(cin, pw);
                if (id == adminID && pw == adminPass) menuAdmin(svList, gvList);
                else cout << "Thong tin admin sai!\n";
                break;
            }
            case 2: {
                string id, pw;
                cout << "Nhap ID sinh vien: "; 
				getline(cin, id);
                SVTT* sv = svList.TimId(id);
                if (sv) {
                    cout << "Nhap mat khau: "; 
					getline(cin, pw);
                    if (sv->getPassword() == pw) menuSinhVien(sv, gvList);
                    else cout << "Sai mat khau.\n";
                } else cout << "Khong tim thay sinh vien.\n";
                break;
            }
            case 3: {
                string id, pw;
                cout << "Nhap ID giang vien: "; 
				getline(cin, id);
                GVHD* gv = gvList.TimId(id);
                if (gv) {
                    cout << "Nhap mat khau: "; 
					getline(cin, pw);
                    if (gv->getPassword() == pw) menuGiangVien(gv, svList);
                    else cout << "Sai mat khau.\n";
                } else cout << "Khong tim thay giang vien.\n";
                break;
            }
        }
    } while (lc != 0);

    return 0;
}
