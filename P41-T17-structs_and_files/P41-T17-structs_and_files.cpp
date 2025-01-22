#include "Card.h"
#define LOAD_OR_CREATE 0 //1-load, 0-create

int main()
{
    srand(time(0));
    FILE* file_bank;

    Card Yehor; //"undefined", 0, 0

#if LOAD_OR_CREATE == 0
    Yehor.createCard();
#else
    //load
#endif // LOAD_OR_CREATE == 0
  
    Yehor.showCard();
    Yehor.cash += 0.99;

    //Save to file
    fopen_s(&file_bank, "bank.bin", "wb");
    if (file_bank == nullptr) cout << "Error: not saved!\n";
    else {
        Yehor.saveToBinFile(file_bank);
        fclose(file_bank);
        cout << "Saved!\n";
    }
}
