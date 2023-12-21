#include "convo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void talking() {
    char *name[500] = {"Albert_Weskerson", "Emily Bathory", "Tom Halloran"};
    char *proffession[500] = {"Sorcerer", "Bard", "Mercenary", "Potion Maker", "Book Seller"};

    srand(static_cast<unsigned int>(time(NULL)));

    bool convo = true;
    cout << "You see a person" << endl;

    while (convo) {
        cout << "Do you want to talk to this person? (1 for Yes / 0 for Exit)" << endl;
        cin >> convo;

        if (!convo) {
            cout << "The person " << name[rand() % 3] << " vanished in crowd of people." << endl;
            break;
        }

        cout << "Choose: \n(1) Who are you\n(2) Where are you heading\n(0) Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "I am " << name[rand() % 3] << ". I work as " << proffession[rand() % 5] << ". Nice to meet you." << endl;
                break;
            case 2:
                cout << "Where do you want to go?" << endl;
                cout << "(1) Nearest Shop\n(2) Nearest Tavern\n(3) Castle\n(0) Exit" << endl;

                int locationChoice;
                cin >> locationChoice;

                switch (static_cast<Locations>(locationChoice - 1)) {
                    case Nearest_Shop:
                        cout << "The nearest shop is located nearby." << endl;
                        break;
                    case Nearest_Tavern:
                        cout << "The nearest tavern is just down the road." << endl;
                        break;
                    case Castle:
                        cout << "The castle is at the top of the hill." << endl;
                        break;
                    case Location_Count:
                        cout << "The person " << name[rand() % 3] << " vanished around the corner." << endl;
                        convo = false;
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
                break;
            case 0:
                cout << "The person " << name[rand() % 3] << " vanished thin air." << endl;
                convo = false;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
}
