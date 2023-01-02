#include "iostream"
using namespace std;
class NHANVIEN{
    private:
        string manv;
        string tennv;
        int tuoi;
    public:
        NHANVIEN();
        void nhap();
        void xuat();
        int vehuu();
};
NHANVIEN::NHANVIEN(){
    manv="";
    tennv="";
    tuoi=0;
}
void NHANVIEN::nhap(){
    cout<<"Nhap ma nhan vien:";
    cin.ignore();
    getline(cin,manv);
    cout<<"Nhap ho ten nhan vien:";
    getline(cin,tennv);
    cout<<"Nhap tuoi:";
    cin>>tuoi;
}
void NHANVIEN::xuat(){
    cout<<"\n "<<manv<<"\t "<<tennv<<"\t "<<tuoi<< "\t";
    if (vehuu()==1)
        cout<<"Ve huu";
    else     cout<<"chua ve huu";
}
int NHANVIEN::vehuu(){
    if (tuoi>=60)
        return 1;
    return 0;
}
class CANBO:public NHANVIEN{
    private:
        float hsl;
        float phucap;
        string trinhdo;
    public:
        void nhap();
        void xuat();
        float tinhluong();
};
void CANBO::nhap(){
    NHANVIEN::nhap();
    cout<<"Nhap he so luong:";
    cin>>hsl;
    cout<<"Nhap phucap: ";
    cin>>phucap;
    cout<<"Trinh do: ";
    cin.ignore();
    getline(cin,trinhdo);
   
}
void CANBO::xuat(){
    NHANVIEN::xuat();
cout<<"\t "<<hsl<<"\t "<<phucap<<"\t "<<trinhdo<<"\t"<<tinhluong();
}
float CANBO::tinhluong(){
    if (vehuu()==0)
        return hsl*1550+phucap;
    return (hsl*1550+phucap)*0.7;
}
main(){
    NHANVIEN nv;
    int n;
    nv.nhap();
    cout<<"\n In thong tin nhan vien \n";
    nv.xuat();
    cout<<"\n Nhap so can bo:";
    cin>>n;
    CANBO *cb = new CANBO[n];
    cout<<"Nhap thong tin tung can bo:";
    for (int i=0;i<n;i++)
        cb[i].nhap();
   return 0;
}