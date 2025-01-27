#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
class Contact{
public:
    string nama;
    string alamat;
    string tempat_tinggal;
    string kekuatan;

    Contact(string xnama, string xalamat, string xdomisili, string xkekuatan) {
        nama = xnama;
        alamat = xalamat;
        tempat_tinggal = xdomisili;
        kekuatan = xkekuatan;
    }
    void printdata(){
        cout<<"Nama        \t= " << nama << endl;
        cout<<"Alamat     \t= "<<alamat<<endl;
        cout<<"Tempat tinggal\t= "<<tempat_tinggal<<endl;
        cout<<"Kekuatan\t= "<<kekuatan<<endl;
        cout<<""<<endl;
    }
};

class PhoneBook{
    private:
        vector<Contact> ListContact;

    public:
    void Add(string nama, string alamat, string domisili, string kekuatan){
        if (ListContact.size()>=1)
        {
            ListContact.erase(ListContact.begin());
        }
        ListContact.push_back(Contact(nama, alamat, domisili, kekuatan ));
        }

    void inputcontact(){
        string nama, alamat, domisili, kekuatan;
        cout<<"---Menambahkan contact baru---"<<endl;
        cout<<"Masukkan nama contact: ";
        getline(cin>>ws, nama);
        cout<<"Masukkan alamat contact: ";
        getline(cin>>ws, alamat);
        cout<<"Masukkan tempat tinggal contact: ";
        getline(cin>>ws, domisili);
        cout<<"Masukkan kekuatan contact: ";
        getline(cin>>ws, kekuatan);

        Add(nama, alamat, domisili, kekuatan);
    }

    void Search(string nama){
        bool ada=false;
        for(auto& Contact: ListContact){
            if (Contact.nama==nama)
            {
                Contact.printdata();
                ada=true;
            }
        if (!ada)
        {
            cout<<"Contact "<<nama<<" tidak ada, silakan tambahkan kontak baru"<<endl;
            cout<<""<<endl;
        }
            
        return;
        }
    }
    void show() {
        if (ListContact.empty()) {
            cout<<"PhoneBook kosong, silakan Add terlebih dahulu"<<endl;
            return ;
        }
        else{
            int i = 1;
            cout<<""<<endl;
            cout<<"---PhoneBook Pak Bell---"<<endl;
            for (auto& contact : ListContact) {
                cout<<i++<<". "<<contact.nama<<endl;
            }
        }
        cout<<""<<endl;
    }
};
 
int main (){
    PhoneBook pb; 
    while (true) {   
        cout<<"---PhoneBook Pak Bell---"<<endl;
        int pilihan;
        cout<<"1. Add"<<endl;
        cout<<"2. Search"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Masukkan pilihan (1/2/3)= ";
        cin>>pilihan;
        if (pilihan==3){
            cout<<"PhoneBook Pak Bell ditutup";
            break;
            }
        else if (pilihan==1){
            pb.inputcontact();
            cout<<"Contact berhasil ditambahkan!!"<<endl;
            cout<<""<<endl;
            }
        else if (pilihan==2){            
            pb.show();
            cout<<"Masukkan nama kontak yang ingin dicari: ";
            string orang;
            getline(cin>>ws, orang);
            cout<<""<<endl;
            pb.Search(orang);
            }
        else{
            cout<<""<<endl;
            cout<<"Silakan masukkan input yang valid"<<endl;
            }
            
        }
   return 0;
    
}
