#include<iostream>
#include<string>
using namespace std;
class media{
private:
    string tengoi;
    int giaban;
public:
    media():tengoi(""),giaban(0){}
    ~media(){}
    void nhap();
    void xuat();
};
void media::nhap(){
    cout<<"Ten goi: ";
    getline(cin,tengoi);
    cout<<"Gia ban: ";
    cin>>giaban;
}
void media::xuat(){
    cout<<"Ten goi: "<<tengoi<<"\n";
    cout<<"Gia ban: "<<giaban<<"\n";
}
class book: public media
{
private:
    int sotrang;
    string tacgia;
public:
    book():sotrang(0),tacgia(""){}
    ~book(){}
    friend istream& operator>>(istream&, book&);
    friend ostream& operator<<(ostream&, book);
};
istream& operator>>(istream&is, book &s){
    s.nhap();
    cout<<"Sotrang: ";
    is>>s.sotrang;
    cout<<"tacgia: ";
    is.ignore();
    getline(is,s.tacgia);
    return is;
}
ostream& operator<<(ostream&os, book s){
    s.xuat();
    os<<"So trang: "<<s.sotrang<<"\n";
    os<<"Tac gia: "<<s.tacgia<<"\n";
    cout<<"-------------------------\n";
    return os;
}
int main(){
    media a;
    a.nhap();
    cout<<"thong tin vua nhap la:\n";
    a.xuat();
    return 0;
}
