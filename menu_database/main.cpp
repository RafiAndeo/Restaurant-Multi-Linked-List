#include <iostream>

using namespace std;

#define info(m) (m)->info
#define next(m) (m)->next
#define info(f) (f)->info
#define next(f) (f)->next
#define next_makanan(m) (m)->next_makanan
#define first(list_menu) ((list_menu).first)
#define nil NULL

typedef struct elm_menu *adr_menu;
typedef struct elm_makanan *adr_makanan;

struct menu{
    string nama_menu;
    int harga_menu;
};

struct makanan{
    string nama_makanan;
    int jumlah_makanan;
};

struct elm_makanan{
    makanan info;
    adr_makanan next;
};

struct elm_menu{
    menu info;
    adr_menu next;
    adr_makanan next_makanan;
};

struct Multi_Linked_List{
    adr_menu first;
};

void create_list(Multi_Linked_List &list_menu){ //benar
    first(list_menu) = nil;
}

void new_elm_menu(menu info, adr_menu &m){ //benar
    m = new elm_menu;
    next(m) = nil;
    next_makanan(m) = nil;
    info(m).nama_menu = info.nama_menu;
    info(m).harga_menu = info.harga_menu;
}

void new_elm_makanan(makanan info, adr_makanan &f){ //benar
    f = new elm_makanan;
    next(f) = nil;
    info(f).nama_makanan = info.nama_makanan;
    info(f).jumlah_makanan = info.jumlah_makanan;
}

void show_data_menu(Multi_Linked_List list_menu){ //benar
    adr_menu m;
    m = first(list_menu);
    while (m != nil){
        cout << "[Menu: " << info(m).nama_menu << " dengan" << " ";
        cout << "Harga: " << info(m).harga_menu << "]" << endl;
        cout << endl;
        m = next(m);
    }
}

void delete_last_menu(Multi_Linked_List &list_menu, adr_menu &m){ //benar
    if(first(list_menu) == nil){
        m = nil;
    }else if(next(first(list_menu)) == nil){
        m = first(list_menu);
        first(list_menu) = nil;
    }else{
        adr_menu q = first(list_menu);
        m = first(list_menu);
        while (next(m) != nil){
            q = m;
            m = next(m);
        }
        next(q) = nil;
    }
}

void insert_last_menu(Multi_Linked_List &list_menu, adr_menu m){ //benar
    if(first(list_menu) == nil){
        first(list_menu) = m;
    }else{
        adr_menu p = first(list_menu);
        while (next(p) != nil){
            p = next(p);
        }
        next(p) = m;
    }
}

void insert_new_makanan(Multi_Linked_List &list_menu, adr_menu m, adr_makanan f){ //benar
    adr_makanan q;
    if(next_makanan(m) == nil){
        next_makanan(m) = f;
    }else{
        q = next_makanan(m);
        while(next(q) != nil){
            q = next(q);
        }
        next(q) = f;
    }
}

void show_makanan(Multi_Linked_List list_menu){ //benar
    adr_makanan f;
    adr_menu m;
    m = first(list_menu);
    while (m != nil){
        f = next_makanan(m);
        while (f != nil){
            cout << " " << endl;
            cout << "[Makanan: " << info(f).nama_makanan << " dengan" << " ";
            cout << "Jumlah makanan: " << info(f).jumlah_makanan << "]" << endl;
            f = next(f);
            cout << endl;
        }
        m = next(m);
    }
}

int main()
{
    Multi_Linked_List L;
    adr_makanan f;
    adr_menu m;
    menu menus;
    makanan foods;
    int choice;
    bool userActivity = true;

    create_list(L);

    cout << "Aplikasi Makanan" << endl;
    cout << " " << endl;
    cout << "1. Menu" << endl;
    cout << "2. Pesan Makanan" << endl;
    cout << "3. Lihat Daftar Pesanan" << endl;
    cout << "4. Keluar" << endl;
    cout << " " << endl;
    cout << "Masukkan pilihan nomor: ";
    cin >> choice;
    while(userActivity == true){
        if(choice == 1){
            cout << " " << endl;
            cout << "6. Lihat Menu" << endl;
            cout << "7. Tambah Menu" << endl;
            cout << "8. Hapus Menu" << endl;
            cout << " " << endl;
            cout << "Masukkan pilihan nomor: ";
            cin >> choice;
            if(choice == 6){
                cout << " " << endl;
                show_data_menu(L);
            }else if(choice == 7){
                string name;
                int price;
                cout << " " << endl;
                cout << "Masukkan nama menu: ";
                cin >> name;
                cout << " " << endl;
                cout << "Masukkan harga menu: ";
                cin >> price;
                menus.nama_menu = name;
                menus.harga_menu = price;
                new_elm_menu(menus, m);
                insert_last_menu(L, m);
                cout << " " << endl;
                cout << "Menu sudah ditambahkan" << endl;
            }else if(choice == 8){
                delete_last_menu(L, m);
                cout << " " << endl;
                cout << "Menu terakhir sudah dihapus" << endl;
                cout << " " << endl;
            }
        }else if (choice == 2){
            string name;
            int counts;
            cout << " " << endl;
            cout << "Masukkan pesanan: ";
            cin >> name;
            cout << " " << endl;
            cout << "Masukkan jumlah pemesanan: ";
            cin >> counts;
            foods.nama_makanan = name;
            foods.jumlah_makanan = counts;
            new_elm_makanan(foods, f);
            insert_new_makanan(L, m, f);
            cout << " " << endl;
            cout << "Pesanan sudah ditambahkan" << endl;
        }else if (choice == 3){
            show_makanan(L);
        }else if (choice == 4){
            cout << " " << endl;
            cout << "Anda sudah keluar dari aplikasi" << endl;
            break;
        }else{
            cout << "Pilihan nomor tidak tepat, silahkan pilih ulang" << endl;
        }
        cout << "Masukkan pilihan nomor: ";
        cin >> choice;
    }
}
