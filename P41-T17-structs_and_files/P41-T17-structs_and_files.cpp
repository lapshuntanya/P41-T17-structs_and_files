#include "Card.h"
#define LOAD_OR_CREATE 0 //1-load, 0-create

int main()
{
    srand(time(0));
    FILE* file_bank;

    /*
    Card Yehor; //"undefined", 0, 0

#if LOAD_OR_CREATE == 0
    Yehor.createCard();
#else
    fopen_s(&file_bank, "bank.bin", "rb");
    if (file_bank == nullptr) cout << "Error: not loaded!\n";
    else {
        Yehor.loadFromBinFile(file_bank);
        fclose(file_bank);
        cout << "Loaded!\n";
    }
#endif // LOAD_OR_CREATE == 0
   //---------------------------------------------------------- 
    Yehor.showCard();
    Yehor.cash += 0.99;

    //----------------------------------------------------------
    // Save to file
    fopen_s(&file_bank, "bank.bin", "wb");
    if (file_bank == nullptr) cout << "Error: not saved!\n";
    else {
        Yehor.saveToBinFile(file_bank);
        fclose(file_bank);
        cout << "Saved!\n";
    }
    */

    int NClients = 0;               //Кількість кліентів = розмір масиву
    Card* arrClients = nullptr;     //Масив карток

   //------------------------------------------------
   // load or create
#if LOAD_OR_CREATE == 0
    NClients = 3;
    arrClients = new Card[3]{
        {"Romushkevych Daniil", 12345678, 4500},
        {"Artemov Vladyslav", 98765323, 6000.50},
        {"Kovalenko Yehor", 5556667, 1000}
    };
#else
    //load
#endif

    //------------------------------------------------
    // menu
    int menu = 0;
    do
    {
        cout << "================================\n";
        cout << "\t\t MENU:\n";
        cout << "================================\n";
        cout << "|\t 1. Show all clients.\n";
        cout << "|\t 2. Add a new client.\n";
        cout << "================================\n";
        cout << "|\t 0. Save and Exit.\n";
        cout << "================================\n";
        cin >> menu;


    } while (menu != 0);

    //------------------------------------------------
    // save

}
