#include <iostream>
#include <string>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

Item* head = nullptr;

const int JUMLAH_AWAL = 15; 
const int POSISI_SISIP = 6;   

Item* buatItem(string nama, string tipe) {
    Item* baru = new Item;
    baru->namaItem = nama;
    baru->tipe = tipe;
    baru->jumlah = JUMLAH_AWAL;
    baru->next = nullptr;
    return baru;
}

void tambahItem(string nama, string tipe) {
    Item* baru = buatItem(nama, tipe);
    if (!head) {
        head = baru;
    } else {
        Item* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " << JUMLAH_AWAL << ".\n";
}

void sisipItem(string nama, string tipe) {
    Item* baru = buatItem(nama, tipe);

    if (!head || POSISI_SISIP <= 1) {
        baru->next = head;
        head = baru;
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
    temp->next = baru;
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
        head = nullptr;
        return;
    }
    Item* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    cout << "Item \"" << temp->next->namaItem << "\" dihapus.\n";
    delete temp->next;
    temp->next = nullptr;
}

void gunakanItem(string nama) {
    if (!head) {
        cout << "Inventory kosong.\n";
        return;
    }

    Item* temp = head;
    Item* prev = nullptr;

    while (temp) {
        if (temp->namaItem == nama) {
            temp->jumlah -= 1;
            cout << "⚔️  Item \"" << nama << "\" digunakan! Sisa: " << temp->jumlah << "\n";
            if (temp->jumlah <= 0) {
                cout << "❌ Item \"" << nama << "\" habis dan dihapus dari inventory!\n";
                if (!prev) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Item \"" << nama << "\" tidak ditemukan di inventory.\n";
}

void tampilkanInventory() {
    if (!head) {
        cout << "Inventory kosong.\n";
        return;
    }
    cout << "\n===== 📦 INVENTORY MOBILE LEGEND =====\n";
    Item* temp = head;
    int i = 1;
    while (temp) {
        string icon;
        if (temp->tipe == "Hero") icon = "🗡";
        else if (temp->tipe == "Skin") icon = "🎭";
        else if (temp->tipe == "Potion") icon = "🧪";
        else if (temp->tipe == "Equipment") icon = "🛡";
        else icon = "📦";

        cout << i++ << ". " << icon << " " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
    }
    cout << "======================================\n";
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
        cout << "|        [ Ramadhan Riyan Pratama - 2409106115 ]    |\n";
        cout << "+--------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                              |\n";
        cout << "| 2. Sisipkan Item                                 |\n";
        cout << "| 3. Hapus Item Terakhir                           |\n";
        cout << "| 4. Gunakan Item                                  |\n";
        cout << "| 5. Tampilkan Inventory                           |\n";
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
        case 0:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
