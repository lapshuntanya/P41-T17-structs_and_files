#include "Card.h"
#include "ArrayTemplate.h"
#define LOAD_OR_CREATE 1 //1-load, 0-create

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
    fopen_s(&file_bank, "all_clients.bin", "rb");
    if (file_bank == nullptr) cout << "Error: not loaded!\n";
    else {
        fread(&NClients, sizeof(int), 1, file_bank);
        arrClients = new Card[NClients];

        for (int i = 0; i < NClients; i++)
        {
            arrClients[i].loadFromBinFile(file_bank);
        }
        fclose(file_bank);
        cout << "Loaded!\n";
    }

#endif

    //------------------------------------------------
    // menu
    int menu = 0;
    int numCard = 0;
    int id = -1;

    do
    {
        cout << "================================\n";
        cout << "\t\t MENU:\n";
        cout << "================================\n";
        cout << "|\t 1. Show all clients.\n";
        cout << "|\t 2. Add a new client.\n";
        cout << "|\t 3. Delete client by card.\n";
        cout << "================================\n";
        cout << "|\t 0. Save and Exit.\n";
        cout << "================================\n";
        cin >> menu;

        switch (menu)
        {
        case 1: for (int i = 0; i < NClients; i++)
                {
                    arrClients[i].showCard();
                }
              break;
        case 2:
        {
            Card temp; //"undefined", 0, 0
            cin.ignore();
            temp.createCard();
            addItemBack(arrClients, NClients, temp);            
        }break;

        case 3:
            cout << "Input number of card: ";
            cin >> numCard;
            id = -1;
            for (int i = 0; i < NClients; i++)
            {
                if (arrClients[i].number == numCard) {
                    id = i;                   
                    break;
                }
            }
            if (id != -1) {
                cout << "Delete: " << arrClients[id].name << endl;
                deleteItem(arrClients, NClients, id);
            }
            else {
                cout << "Not found: " << numCard << endl;
            }
            break;
        }

    } while (menu != 0);

    //------------------------------------------------
    // save
    fopen_s(&file_bank, "all_clients.bin", "wb");
    if (file_bank == nullptr) cout << "Error: not saved!\n";
    else {
        fwrite(&NClients, sizeof(int), 1, file_bank);
        for (int i = 0; i < NClients; i++)
        {
            arrClients[i].saveToBinFile(file_bank);
        }
        fclose(file_bank);
        cout << "Saved!\n";
    }
}
