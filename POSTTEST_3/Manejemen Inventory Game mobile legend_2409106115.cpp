#include <iostream>
#include <string>
using namespace std;

struct Item {
    int id;
    string namaItem;
    string tipe;
    int jumlah;
    Item* prev;
    Item* next;
};

Item* head = nullptr;
Item* tail = nullptr;

const int JUMLAH_AWAL = 15;
const int POSISI_SISIP = 6;
int autoID = 1; 

Item* buatItem(string nama, string tipe) {
    Item* baru = new Item;
    baru->id = autoID++;
    baru->namaItem = nama;
    baru->tipe = tipe;
    baru->jumlah = JUMLAH_AWAL;
    baru->prev = nullptr;
    baru->next = nullptr;
    return baru;
}

void tambahItem(string nama, string tipe) {
    Item* baru = buatItem(nama, tipe);
    if (!head) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan (jumlah " << JUMLAH_AWAL << ").\n";
}

void sisipItem(string nama, string tipe) {
    Item* baru = buatItem(nama, tipe);

    if (!head || POSISI_SISIP <= 1) {
        baru->next = head;
        if (head) head->prev = baru;
        head = baru;
        if (!tail) tail = baru;
        cout << "Item \"" << nama << "\" berhasil disisipkan di posisi awal.\n";
        return;
    }

    Item* temp = head;
    int count = 1;
    while (temp->next && count < POSISI_SISIP - 1) {
        temp = temp->next;
        count++;
    }

    baru->next = temp->next;
    if (temp->next) temp->next->prev = baru;
    temp->next = baru;
    baru->prev = temp;
    if (baru->next == nullptr) tail = baru;

    cout << "Item \"" << nama << "\" berhasil disisipkan di posisi " << POSISI_SISIP << ".\n";
}

void hapusItemTerakhir() {
    if (!head) {
        cout << "Inventory kosong.\n";
        return;
    }
    if (!head->next) {
        cout << "Item \"" << head->namaItem << "\" dihapus.\n";
        delete head;
        head = tail = nullptr;
        return;
    }
    cout << "Item \"" << tail->namaItem << "\" dihapus.\n";
    Item* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

void gunakanItem(string nama) {
    if (!head) {
        cout << "Inventory kosong.\n";
        return;
    }

    Item* temp = head;
    while (temp) {
        if (temp->namaItem == nama) {
            temp->jumlah -= 1;
            cout << "⚔️  Item \"" << nama << "\" digunakan! Sisa: " << temp->jumlah << "\n";
            if (temp->jumlah <= 0) {
                cout << "❌ Item \"" << nama << "\" habis dan dihapus dari inventory!\n";
                if (temp == head) {
                    head = head->next;
                    if (head) head->prev = nullptr;
                    else tail = nullptr;
                } else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
            }
            return;
        }
        temp = temp->next;
    }
    cout << "Item \"" << nama << "\" tidak ditemukan di inventory.\n";
}

void tampilkanInventory() {
    if (!head) {
        cout << "Inventory kosong.\n";
        return;
    }
    cout << "\n===== 📦 INVENTORY MOBILE LEGEND (DEPAN→BELAKANG) =====\n";
    Item* temp = head;
    int i = 1;
    while (temp) {
        string icon;
        if (temp->tipe == "Hero") icon = "🗡";
        else if (temp->tipe == "Skin") icon = "🎭";
        else if (temp->tipe == "Potion") icon = "🧪";
        else if (temp->tipe == "Equipment") icon = "🛡";
        else icon = "📦";

        cout << i++ << ". ID: " << temp->id
             << " | " << icon << " " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
    }
    cout << "======================================================\n";
}

void tampilkanInventoryReverse() {
    if (!tail) {
        cout << "Inventory kosong.\n";
        return;
    }
    cout << "\n===== 📦 INVENTORY MOBILE LEGEND (BELAKANG→DEPAN) =====\n";
    Item* temp = tail;
    int i = 1;
    while (temp) {
        string icon;
        if (temp->tipe == "Hero") icon = "🗡";
        else if (temp->tipe == "Skin") icon = "🎭";
        else if (temp->tipe == "Potion") icon = "🧪";
        else if (temp->tipe == "Equipment") icon = "🛡";
        else icon = "📦";

        cout << i++ << ". ID: " << temp->id
             << " | " << icon << " " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->prev;
    }
    cout << "======================================================\n";
}

void cariDetail() {
    if (!head) {
        cout << "Inventory kosong.\n";
        return;
    }
    cout << "Cari berdasarkan:\n1. ID\n2. Nama\nPilih: ";
    int pilih;
    cin >> pilih;
    cin.ignore();

    if (pilih == 1) {
        int idCari;
        cout << "Masukkan ID: ";
        cin >> idCari;
        Item* temp = head;
        while (temp) {
            if (temp->id == idCari) {
                cout << "\n=== DETAIL ITEM ===\n";
                cout << "ID: " << temp->id << "\nNama: " << temp->namaItem 
                     << "\nTipe: " << temp->tipe << "\nJumlah: " << temp->jumlah << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item dengan ID " << idCari << " tidak ditemukan.\n";
    } else if (pilih == 2) {
        string namaCari;
        cout << "Masukkan Nama: ";
        getline(cin, namaCari);
        Item* temp = head;
        while (temp) {
            if (temp->namaItem == namaCari) {
                cout << "\n=== DETAIL ITEM ===\n";
                cout << "ID: " << temp->id << "\nNama: " << temp->namaItem 
                     << "\nTipe: " << temp->tipe << "\nJumlah: " << temp->jumlah << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item dengan nama \"" << namaCari << "\" tidak ditemukan.\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
}

void initInventory() {
    tambahItem("Miya", "Hero");
    tambahItem("Alucard", "Hero");
    tambahItem("Layla", "Hero");
    tambahItem("Tigreal", "Hero");

    tambahItem("EpicSkin_Miya", "Skin");
    tambahItem("LegendSkin_Alucard", "Skin");

    tambahItem("HealthPotion", "Potion");
    tambahItem("ManaPotion", "Potion");

    tambahItem("BladeOfDespair", "Equipment");
    tambahItem("Immortality", "Equipment");
    tambahItem("SwiftBoots", "Equipment");
}

int main() {
    int pilihan;
    string nama, tipe;

    initInventory();

    do {
        cout << "\n+--------------------------------------------------+\n";
        cout << "|        GAME INVENTORY MOBILE LEGEND              |\n";
        cout << "|        [ Ramadhan Riyan Pratama - 2409106115 ]   |\n";
        cout << "+--------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                              |\n";
        cout << "| 2. Sisipkan Item                                 |\n";
        cout << "| 3. Hapus Item Terakhir                           |\n";
        cout << "| 4. Gunakan Item                                  |\n";
        cout << "| 5. Tampilkan Inventory Depan→Belakang            |\n";
        cout << "| 6. Tampilkan Inventory Belakang→Depan            |\n";
        cout << "| 7. Cari Detail Item (ID/Nama)                    |\n";
        cout << "| 0. Keluar                                        |\n";
        cout << "+--------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan nama item: ";
            cin >> nama;
            cout << "Masukkan tipe item (Hero/Skin/Potion/Equipment): ";
            cin >> tipe;
            tambahItem(nama, tipe);
            break;
        case 2:
            cout << "Masukkan nama item: ";
            cin >> nama;
            cout << "Masukkan tipe item (Hero/Skin/Potion/Equipment): ";
            cin >> tipe;
            sisipItem(nama, tipe);
            break;
        case 3:
            hapusItemTerakhir();
            break;
        case 4:
            cout << "Masukkan nama item yang ingin digunakan: ";
            cin >> nama;
            gunakanItem(nama);
            break;
        case 5:
            tampilkanInventory();
            break;
        case 6:
            tampilkanInventoryReverse();
            break;
        case 7:
            cariDetail();
            break;
        case 0:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
