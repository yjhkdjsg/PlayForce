#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <iterator>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <sstream>

using namespace std;

class Game
{
    private:
    string name;
    double price;
    int quantity;
    public:
    static int total_games;
    Game(string name, double price, int quantity)
    {
        this-> name = name;
        this-> price = price;
        this-> quantity = quantity;
        total_games++;
    }
    // Getter functions
    string getName()
    {
        return name;
    }
    double getPrice()
    {
        return price;
    }
    int getQuantity()
    {
        return quantity;
    }
    void setQuantity(int q)
    {
        quantity=q;
    }
    // Decreases the total number of games
    void decreaseQuantity()
    {
        quantity = quantity - 1;
    }
    // Sets new price
    void setPrice(double new_price)
    {
        price = new_price;
    }
};

//Static variable for total number of games
int Game :: total_games=0;

//Global variable for total games in Cart
int games_in_cart=0;

//Vector for Games in Store
vector <Game> games;
//Vector for Games in Cart
vector <Game> cart;

void intro()
{
    cout << "\t\t////////////////////////////////////////////////" << endl;
    cout << "\t\t//// Welcome to Playstore Management System ////" << endl;
    cout << "\t\t////////////////////////////////////////////////" << endl;
}

class Store
{
    public:
    virtual void menu()=0;
    virtual void addGame()=0;
    virtual void removeGame()=0;
    // Views games in store
    void viewGamesInStore()
    {
        system("CLS");
        Sleep(200);

        cout <<  endl;
        Sleep(200);
        cout << "\t*********************************GAMES IN STORE*********************************" << endl;
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        cout << endl;
        // Checks if there are no games in store
        if(games.size() == 0)
        {
            cout << "\tCURRENTLY THE STORE DOES NOT HAVE ANY GAMES..." << endl;
            Sleep(200);
            cout <<  endl;
            Sleep(200);
            cout << "\tKINDLY ASK THE OWNER TO ADD GAMES TO THE STORE..." << endl;
            Sleep(200);
            cout <<  endl;
            Sleep(200);
            return;
        }
        else
        {
            int i;
            for(i=0; i<games.size(); i++)
            {
                cout <<  endl;
                Sleep(100);
                cout << "\tGAME NAME: " << games[i].getName() << endl;
                Sleep(100);
                cout << "\tPRICE: " << games[i].getPrice() << endl;
                Sleep(100);
                cout << "\tQUANTITY: " << games[i].getQuantity() << endl;
                Sleep(100);
            }
            cout <<  endl;
            Sleep(200);
        }
        cout << endl;
    }
    // Loads games from file to vector
    void loadGamesFromFile()
    {
        ifstream main_file1("D://Arya//C Programs//SDF LAB 2 PROJECT//games.txt");
        string name, p, q;
        double price;
        int quantity;
        int i;
        int c=0;
        while(getline(main_file1, p))
        {
            c++;
        }
        c=c/3;
        main_file1.close();
        ifstream main_file("D://Arya//C Programs//SDF LAB 2 PROJECT//games.txt");
        for(i=0; i<c; i++)
        {
            getline(main_file, name);
            getline(main_file, p);
            getline(main_file, q);
            price=stoi(p);
            quantity=stod(q);
            games.push_back(Game(name, price, quantity));
        }
        cout <<  endl;
        Sleep(100);
        cout << "\t*********************************GAMES LOADED IN THE SERVER...*********************************" << endl;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        main_file.close();
    }
    // Saves games from vector to file
    void saveGamesToFile()
    {
        ofstream main_file2("D://Arya//C Programs//SDF LAB 2 PROJECT//games.txt");
        int i;
        for(i=0; i< games.size(); i++)
        {
            main_file2 << games[i].getName() << endl;
            main_file2 << games[i].getPrice() << endl;
            main_file2 << games[i].getQuantity() << endl;
        }
        system("CLS");
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        cout << "\tSAVING GAMES FROM THE SERVER TO THE DATABASE..." << endl;
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        main_file2.close();
    }

    // Views games present in cart
    void viewGamesInCart()
    {
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << "\t*********************************GAMES IN CART*********************************" << endl;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << endl;
        // Checks if there are no games in cart
        if(cart.size() == 0)
        {
            cout <<  endl;
            Sleep(100);
            cout << "\tYOUR CART IS EMPTY..." << endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
            cout << "\tKINDLY ADD GAMES TO YOUR CART..." << endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);

            return;
        }
        else
        {
            int i;

            for(i=0; i<cart.size(); i++)
            {
                cout <<  endl;
                Sleep(100);
                cout << "\tGAME NAME: " << cart[i].getName() << endl;
                Sleep(100);
                cout << "\tPRICE: " << cart[i].getPrice() << endl;
                Sleep(100);
                cout << "\tQUANTITY: " << cart[i].getQuantity() << endl;
                Sleep(100);
            }
            cout <<  endl;
            Sleep(100);
            cout << endl;
        }
    }

    void printBill()
    {
        Sleep(200);
        if(cart.size() == 0)
        {
            cout <<  endl;
            Sleep(200);
            cout << "\tYOUR CART IS EMPTY..." << endl;
            Sleep(200);
            cout <<  endl;
            Sleep(200);
            cout << "\tKINDLY ADD GAMES IN YOUR CART TO PURCHASE THEM..." << endl;
            Sleep(200);
            cout <<  endl;
            Sleep(200);
            cout << "\tRETURNING TO PREVIOUS MENU..." << endl;
            Sleep(200);
            cout <<  endl;
            Sleep(200);
            return;
        }
        // Prints the bill
        else
        {
            cout <<  endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
            cout << "\t*********************************BILL*********************************" << endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
            cout << endl;
            cout << "\t-------------------------------------------------------------------" << endl;
            cout << endl;
            time_t now = time(0);
            char *date_time = ctime(&now);
            cout << "\tBILL DATE AND TIME: " << date_time << endl;
            Sleep(100);
            cout << "\t-------------------------------------------------------------------" << endl;
            Sleep(100);
            ifstream cust_file("D://Arya//C Programs//SDF LAB 2 PROJECT//customer.txt");
            string cust_name;
            string cust_phone;
            string cust_email;
            getline(cust_file, cust_name);
            getline(cust_file, cust_phone);
            getline(cust_file, cust_email);
            cust_file.close();
            cout << endl;
            cout << "\tCUSTOMER NAME: " << cust_name << endl;
            Sleep(100);
            cout << "\tCUSTOMER PHONE NUMBER: " << cust_phone << endl;
            Sleep(100);
            cout << "\tCUSTOMER EMAIL ID: " << cust_email << endl;
            Sleep(100);
            cout << endl;
            cout << "\t-------------------------------------------------------------------" << endl;
            cout << "\tGAMES PURCHASED: " << games_in_cart<<endl;
            viewGamesInCart();
            double total_price=0;
            // Traverses cart and adds price of all games to total_price
            vector <Game> :: iterator itr;
            for(itr=cart.begin(); itr!=cart.end(); itr++)
            {
                total_price += itr->getPrice();
            }
            cout << "\t-------------------------------------------------------------------" << endl;
            Sleep(100);
            cout << "\tTOTAL PRICE: " << total_price << endl;
            Sleep(100);
            cout << "\t-------------------------------------------------------------------" << endl;
            Sleep(100);
            for(int i=0; i<cart.size(); i++)
            {
                cart.pop_back();
            }
            cout << endl;
        }
    }
    void getCustomerDetails()
    {
        // Opens customer file to add customer details
        ofstream cust("D://Arya//C Programs//SDF LAB 2 PROJECT//customer.txt");
        string cust_name;
        long long int cust_phone_no;
        string cust_email;
        cout <<  endl;
        Sleep(100);
        cout << "\tENTER CUSTOMER NAME: ";
        cin >> cust_name;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << "\tENTER CUSTOMER PHONE NUMBER: ";
        cin >> cust_phone_no;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << "\tENTER CUSTOMER EMAIL ID: ";
        Sleep(100);
        cin >> cust_email;
        cout <<  endl;
        Sleep(100);
        cust << cust_name << endl;
        cust << cust_phone_no << endl;
        cust << cust_email << endl;
        cout << endl;
        cust.close();
    }
};
class Owner : public Store {
    public:
    void ownerLogin()
    {
        string owner_name;
        char password[10]="ASKS";
        char pass[10];
        int i=0,p=0;
        system("CLS");
        cout <<  endl;
        Sleep(500);
        cout << "\t*********************************OWNER LOGIN PAGE*********************************" << endl;
        Sleep(500);
        cout <<  endl;
        Sleep(500);
        cout << "\tENTER OWNER NAME: ";
        cin >> owner_name;
        Sleep(500);
        cout <<  endl;
        Sleep(500);
        cout << "\tENTER OWNER PASSWORD: ";
        while(1)
        {
            pass[p]=getch();
            if(pass[p]==8)
            {
                p--;
                cout<<"\b \b";
            }
            else
            {
                if(pass[p]!='\r')
                {
                    cout<<"*";
                }
                else
                {
                    break;
                }
                p++;
            }
        }
        pass[p]='\0';
        cout <<  endl;
        Sleep(1000);
        if((owner_name=="ARYA" || owner_name=="arya" || owner_name=="sneha"|| owner_name=="SNEHA"|| owner_name=="KRITIKA"|| owner_name=="kritika") && (strcmp(pass,password)==0) )
        {
            system("CLS");
            cout <<  endl;
            Sleep(500);
            cout << "\tYOU HAVE ENTERED CORRECT USER NAME AND PASSWORD" << endl;
            Sleep(500);
            cout <<  endl;
            Sleep(1000);
            system("CLS");
            cout <<  endl;
            Sleep(500);
            cout << "\tLOGGING IN AS OWNER..." << endl;
            Sleep(500);
            cout <<  endl;
            Sleep(1000);
            system("CLS");
            cout <<  endl;
            Sleep(500);
            cout << "\tYOU ARE BEING REDIRECTED TO OWNER MENU..." << endl;
            Sleep(500);
            cout <<  endl;
            Sleep(1000);
            Owner::menu();
        }
        else
        {
            system("CLS");
            cout <<  endl;
            Sleep(500);
            cout << "\tYOU HAVE ENTERED WRONG USER NAME AND PASSWORD" << endl;
            Sleep(500);
            cout <<  endl;
            Sleep(1000);
            system("CLS");
            cout <<  endl;
            Sleep(500);
            cout << "\tRETURNING TO THE PREVIOUS MENU..." << endl;
            Sleep(500);
            cout <<  endl;
            Sleep(1000);
            return;
        }
    }

    void menu()
    {
        int owner_choice=0;
        system("CLS");
        Sleep(100);
        while(owner_choice!=5)
        {
            Sleep(200);
            cout <<  endl;
            Sleep(200);
            cout << "\t*********************************Owner Menu*********************************" << endl;
            Sleep(200);
            cout <<  endl;
            Sleep(200);
            cout << "\t1. ADD GAMES" << endl;
            Sleep(200);
            cout << "\t2. REMOVE GAMES" << endl;
            Sleep(200);
            cout << "\t3. VIEW GAMES IN STORE" << endl;
            Sleep(200);
            cout << "\t4. UPDATE INFORMATION" << endl;
            Sleep(200);
            cout << "\t5. VIEW TOTAL INCOME" << endl;
            Sleep(200);
            cout << "\t6. LOGOUT" << endl << endl;
            Sleep(200);
            cout << "\tENTER CHOICE: ";
            cin >> owner_choice;
            Sleep(200);
            cout <<  endl;
            Sleep(500);
            if(owner_choice == 1)
            {
                addGame();
            }
            else if(owner_choice == 2)
            {
                removeGame();
            }
            else if(owner_choice == 3)
            {
                viewGamesInStore();
            }
            else if (owner_choice == 4)
            {
                updateGame();
            }
            else if(owner_choice == 5)
            {
                viewTotalIncome();
            }
            else if(owner_choice == 6)
            {
                system("CLS");
                Sleep(200);
                cout <<  endl;
                Sleep(200);
                cout << "\tLOGGING OUT OF OWNER PAGE..." << endl;
                Sleep(200);
                cout <<  endl;
                Sleep(200);
                cout << "\tRETURNING TO LOG IN MENU...\n" << endl;
                Sleep(200);
                cout <<  endl;
                Sleep(200);
                break;
            }
            else
            {
                cout << "\nINVALID INPUT..." << endl;
            }
        }
    }
    void addGame()
    {
        string name;
        double price;
        int quantity;
        system("CLS");
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        cout << "\tENTER GAME NAME: ";
        cin >> name;
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        cout << "\tENTER GAME PRICE: ";
        cin >> price;
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        cout << "\tENTER GAME QUANTITY: ";
        cin >> quantity;
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        cout << endl;
        int flag=0;
        // Traverses vector games to check if game already exists
        vector <Game> :: iterator itr;
        for(itr=games.begin(); itr!=games.end(); itr++)
        {
            if(name==itr->getName())
            {
                flag++;
                break;
            }
        }
        if(flag>0)
        {
            cout <<  endl;
            Sleep(200);
            cout << "\tTHIS GAME ALREADY EXISTS IN STORE..." << endl;
            Sleep(500);
            cout <<  endl;
            Sleep(200);
            cout << "\tKINDLY ENTER A NEW GAME..." << endl;
            Sleep(500);
            cout <<  endl;
            Sleep(200);
            cout << "\tRETURNING TO PREVIOUS MENU..." << endl;
            Sleep(200);
            cout <<  endl;
            Sleep(500);
            return;
        }
        else
        {
            games.push_back(Game(name, price, quantity));

            fstream MyFile("D://Arya//C Programs//SDF LAB 2 PROJECT//games.txt", ios :: app);

            MyFile << name << endl;
            MyFile << price << endl;
            MyFile << quantity << endl;

            MyFile.close();

            cout <<  endl;
            Sleep(200);
            cout << "\tGAME ADDED SUCCESSFULLY TO THE STORE..." << endl;
            Sleep(200);
            cout <<  endl;
        }
    }
    void updateGame()
    {
        string game_name;
        double new_price;
        int new_quantity;
        system("CLS");
        Sleep(200);
        cout <<  endl;
        Sleep(100);
        cout << "\t*********************************UPDATE GAME DETAILS*********************************" << endl;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        // Displays games present in store
        viewGamesInStore();
        cout <<  endl;
        Sleep(100);
        cout << "\tENTER NAME OF THE GAME YOU WISH TO UPDATE: ";
        cin >> game_name;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        int flag = 0;
        // Checks if game is present in store
        vector <Game> :: iterator g;
        for(g=games.begin(); g!=games.end(); g++)
        {
            if(game_name == g->getName())
            {
                flag = 1;

                cout <<  endl;
                Sleep(100);
                cout << "\tENTER NEW PRICE OF THE GAME: ";
                cin >> new_price;
                Sleep(100);
                cout <<  endl;
                Sleep(100);

                cout <<  endl;
                Sleep(100);
                cout << "\tENTER NEW QUANTITY OF THE GAME: ";
                cin >> new_quantity;
                Sleep(100);
                cout <<  endl;
                Sleep(100);

                g->setPrice(new_price);
                g->setQuantity(new_quantity);

                cout <<  endl;
                Sleep(100);
                cout << "\tGAME DETAILS UPDATED SUCCESSFULLY..." << endl;
                Sleep(100);
                cout <<  endl;
                Sleep(100);

                break;
            }
        }
        if(flag == 0)
        {
            cout <<  endl;
            Sleep(100);
            cout << "\tGAME NOT FOUND..." << endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
        }
        //Update the file with the new game details
        ofstream MyFile("D://Arya//C Programs//SDF LAB 2 PROJECT//games.txt");
        for(g=games.begin(); g!=games.end(); g++)
        {
            MyFile << g->getName() << endl;
            MyFile << g->getPrice() << endl;
            MyFile << g->getQuantity() << endl;
        }
        MyFile.close();
    }
    void removeGame()
    {
        string game_name_to_remove;
        system("CLS");
        viewGamesInStore();
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        cout << "\tENTER NAME OF THE GAME TO REMOVE: ";
        cin >> game_name_to_remove;
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        cout << endl;
        int flag=-1;
        int i;
        int j;
        for(i=0; i<games.size(); i++)
        {
            if(games[i].getName() == game_name_to_remove)
            {
                cout <<  endl;
                Sleep(200);
                cout << "\tGAME FOUND..." << endl;
                Sleep(200);
                cout <<  endl;
                Sleep(200);
                cout << "\tREMOVING GAME: " << game_name_to_remove << endl;
                Sleep(200);

                flag=i;
                break;
            }
        }
        if(flag==-1)
        {
            cout <<  endl;
            Sleep(200);
            cout << "\tGAME NOT FOUND..." << endl;
            Sleep(200);
            cout <<  endl;
            Sleep(200);
            cout << "\tRETURNING TO PREVIOUS MENU..." << endl;
            Sleep(200);
            cout <<  endl;
            Sleep(500);

            return;
        }
        for(j=flag; j<games.size()-1; j++)
        {
            games[j]=games[j+1];
        }
        // Reduces total distinct games
        Game :: total_games--;
        // Removes last extra game
        games.pop_back();
        cout <<  endl;
        Sleep(200);
        cout << "\tGAME SUCCESSFULLY REMOVED..." << endl;
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        cout << "\tRETURNING TO PREVIOUS MENU..." << endl;
        Sleep(200);
        cout <<  endl;
        Sleep(200);
        cout << endl;
        return;
    }
    void viewTotalIncome()
    {
        ifstream owner_file("D://Arya//C Programs//SDF LAB 2 PROJECT//owner.txt");
        string income;
        getline(owner_file, income);
        system("CLS");
        Sleep(500);
        char pin[10]="ASKS";
        char pinn[10];
        int i=0,p=0;
        system("CLS");
        Sleep(500);
        cout <<  endl;
        Sleep(500);
        cout << "\tENTER OWNER PASSWORD: ";
        while(1)
        {
            pinn[p]=getch();
            if(pinn[p]==8)
            {
                p--;
                cout<<"\b \b";
            }
            else
            {
                if(pinn[p]!='\r')
                {
                    cout<<"*";
                }
                else
                {
                    break;
                }
                p++;
            }
        }
        pinn[p]='\0';
        cout <<  endl;
        Sleep(1000);
        cout <<  endl;
        if(strcmp(pinn,pin)==0)
        {
            cout <<  endl;
            Sleep(200);
            cout << "\tTOTAL INCOME: " << income << endl;
            Sleep(500);
            cout <<  endl;
            Sleep(500);
        }
        else
        {
            cout <<  endl;
            Sleep(200);
            cout << "\tINCORRECT PIN..." << endl;
            Sleep(200);
            cout <<  endl;
            Sleep(200);
        }
        cout << endl;
        owner_file.close();
    }

};

class Customer : public Store {
    public:
    void addGame()
    {
        int cart_sub_menu;
        system("CLS");
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << "\t*********************************ADD GAME TO CART*********************************" << endl;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << endl;
        cout <<  endl;
        Sleep(100);
        cout << "\t1. SEARCH BY GAME NAME" << endl;
        Sleep(100);
        cout << "\t2. RETURNING TO PREVIOUS MENU...\n" << endl;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << "\tENTER CHOICE: ";
        cin >> cart_sub_menu;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        fstream MyFile("D://Arya//C Programs//SDF LAB 2 PROJECT//customer.txt", ios :: app);
        while(cart_sub_menu!=2)
        {
            system("CLS");
            Sleep(100);
            if(cart_sub_menu == 1)
            {
                games_in_cart++;
                viewGamesInStore();
                string game_to_add_to_cart;
                int flag1 = 0;
                double game_price=0;
                int game_quantity=1;
                cout <<  endl;
                Sleep(100);
                cout << "\tENTER GAME NAME TO ADD TO CART: ";
                cin >> game_to_add_to_cart;
                Sleep(100);
                cout <<  endl;
                Sleep(100);
                vector <Game> :: iterator itr;
                for(itr=games.begin(); itr!=games.end(); itr++)
                {
                    if(game_to_add_to_cart == itr->getName())
                    {
                        flag1++;
                        game_price = itr->getPrice();

                        vector <Game> :: iterator itr2;

                        for(itr2=cart.begin(); itr2!=cart.end(); itr2++)
                        {
                            if(game_to_add_to_cart == itr2->getName())
                            {
                                flag1++;
                                game_quantity++;
                                break;
                            }
                        }

                        break;
                    }
                }
                if(flag1 == 1)
                {
                    cart.push_back(Game(itr->getName(), itr->getPrice(), game_quantity));
                    MyFile << game_to_add_to_cart << endl;
                    MyFile << game_price << endl;
                    MyFile << game_quantity << endl;
                    cout <<  endl;
                    Sleep(100);
                    cout << "\tGAME ADDED TO CART SUCCESSFULLY..." << endl;
                    Sleep(100);
                    cout <<  endl;
                    Sleep(100);
                }
                else if(flag1 == 2)
                {
                    cout <<  endl;
                    Sleep(100);
                    cout << "\tGAME ALREADY IN CART..." << endl;
                    Sleep(100);
                    cout <<  endl;
                    Sleep(100);
                }
                else
                {
                    cout <<  endl;
                    Sleep(100);
                    cout << "\tINCORRECT GAME NAME..." << endl;
                    Sleep(100);
                    cout <<  endl;
                    Sleep(100);
                }
            }
            else if(cart_sub_menu == 2)
            {
                cout <<  endl;
                Sleep(100);
                cout << "\tRETURNING TO PREVIOUS MENU..." << endl;
                Sleep(100);
                cout <<  endl;
                Sleep(100);

                return;
            }
            else
            {
                cout << "\tINVALID INPUT..." << endl;
            }
            cout <<  endl;
            Sleep(100);
            cout << "\t*********************************ADD GAME TO CART*********************************" << endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
            cout << endl;
            cout <<  endl;
            Sleep(100);
            cout << "\t1. SEARCH BY GAME NAME" << endl;
            Sleep(100);
            cout << "\t2. RETURN TO PREVIOUS MENU" << endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
            cout << "\tENTER CHOICE: ";
            cin >> cart_sub_menu;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
        }
        MyFile.close();
    }
    void menu()
    {
        getCustomerDetails();
        int cust_choice=0;
        system("CLS");
        Sleep(100);
        while(cust_choice!=6)
        {
            Sleep(100);
            cout <<  endl;
            Sleep(100);
            cout << "\t*********************************CUSTOMER MENU*********************************" << endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
            cout << "\t1. ADD GAME TO CART" << endl;
            Sleep(100);
            cout << "\t2. REMOVE GAME FROM CART" << endl;
            Sleep(100);
            cout << "\t3. VIEW GAMES IN STORE" << endl;
            Sleep(100);
            cout << "\t4. VIEW GAMES IN CART" << endl;
            Sleep(100);
            cout << "\t5. PURCHASE GAMES" << endl;
            Sleep(100);
            cout << "\t6. LOGOUT" << endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
            cout << endl;
            cout << "\tENTER CHOICE: ";
            cin >> cust_choice;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
            if(cust_choice == 1)
            {
                Customer::addGame();
                system("CLS");
            }
            else if(cust_choice == 2)
            {
                removeGame();
                system("CLS");
            }
            else if(cust_choice == 3)
            {
                system("CLS");
                Sleep(100);
                viewGamesInStore();
                Sleep(100);
            }
            else if(cust_choice == 4)
            {
                system("CLS");
                Sleep(100);
                viewGamesInCart();
                Sleep(100);
                cout << endl;
            }
            else if(cust_choice == 5)
            {
                string sub_choice;
                system("CLS");
                Sleep(200);
                viewGamesInCart();
                cout <<  endl;
                Sleep(100);
                cout << "\tDO YOU WISH TO PROCEED WITH THE PURCHASE?(Y/N): ";
                cin >> sub_choice;
                Sleep(100);
                cout <<  endl;
                Sleep(100);
                if(sub_choice=="y" || sub_choice=="Y" || sub_choice=="YES" || sub_choice=="yes" || sub_choice=="Yes")
                {
                    system("CLS");
                    Sleep(200);
                    purchaseGames();
                    printBill();
                }
                else
                {
                    system("CLS");
                    Sleep(200);

                    cout <<  endl;
                    Sleep(100);
                    cout << "\tRETURNING TO PREVIOUS MENU..." << endl;
                    Sleep(100);
                    cout <<  endl;
                    Sleep(200);
                }
            }
            else if(cust_choice == 6)
            {
                Sleep(200);
                cout << "\tLOGGING OUT OF CUSTOMER PAGE..." << endl;
                Sleep(200);
                cout << "\tRETURNING TO LOGIN MENU...\n" << endl;
                break;
            }
            else
            {
                cout << "\tINVALID INPUT..." << endl;
            }
        }
    }
    void removeGame()
    {
        string game_to_remove_from_cart;
        int cart_remove_menu;
        cout <<  endl;
        Sleep(100);
        cout << "\t*********************************REMOVE GAME FROM CART*********************************" << endl;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << endl;
        cout <<  endl;
        Sleep(100);
        cout << "\t1. SEARCH GAME BY NAME" << endl;
        Sleep(100);
        cout << "\t2. RETURNING TO PREVIOUS MENU..." << endl;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << "\tENTER CHOICE: ";
        cin >> cart_remove_menu;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        while(cart_remove_menu!=2)
        {
            if(cart_remove_menu == 1)
            {
                viewGamesInCart();

                cout <<  endl;
                Sleep(100);
                cout << "\tENTER GAME NAME TO REMOVE FROM CART: ";
                cin >> game_to_remove_from_cart;
                Sleep(100);
                cout <<  endl;
                Sleep(100);

                int flag2 = 0;

                int i;

                for(i=0; i<games.size(); i++)
                {
                    if(game_to_remove_from_cart == games[i].getName())
                    {
                        int game_count=0;
                        int index_of_game_in_cart;

                        int j;

                        for(j=0; j<games_in_cart; j++)
                        {
                            if(cart[j].getName() == game_to_remove_from_cart)
                            {
                                game_count = cart[j].getQuantity() -1;
                                index_of_game_in_cart = j;
                                break;
                            }
                        }

                        int k;

                        for(int k=index_of_game_in_cart; k<cart.size()-1; k++)
                        {
                            cart[k]=cart[k+1];
                        }

                        cart.pop_back();

                        flag2=1;
                        break;
                    }
                }

                if(flag2 == 1)
                {
                    cout <<  endl;
                    Sleep(100);
                    cout << "\tGAME REMOVED FROM CART SUCCESSFULLY..." << endl;
                    Sleep(100);
                    cout <<  endl;
                    Sleep(100);
                }
                else
                {
                    cout <<  endl;
                    Sleep(100);
                    cout << "\tINCORRECT GAME NAME" << endl;
                    Sleep(100);
                    cout <<  endl;
                    Sleep(100);
                    cout << endl;
                }
            }
            else if(cart_remove_menu == 2)
            {
                cout <<  endl;
                Sleep(100);
                cout << "\tRETURNING TO PREVIOUS MENU..." << endl;
                Sleep(100);
                cout <<  endl;
                Sleep(100);
                break;
            }
            else
            {
                cout <<  endl;
                Sleep(100);
                cout << "\tINVALID INPUT..." << endl;
                Sleep(100);
                cout <<  endl;
                Sleep(100);
                cout << endl;
            }

            cout <<  endl;
            Sleep(100);
            cout << "\t*********************************REMOVE GAME FROM CART*********************************" << endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
            cout << endl;
            cout <<  endl;
            Sleep(100);
            cout << "\t1. SEARCH BY GAME NAME" << endl;
            Sleep(100);
            cout << "\t2. RETURNING TO PREVIOUS MENU..." << endl;
            Sleep(100);
            cout <<  endl;
            Sleep(100);

            cout << "\tENTER CHOICE: ";
            cin >> cart_remove_menu;
            Sleep(100);
            cout <<  endl;
            Sleep(100);
        }
    }
    void purchaseGames()
    {
        int i, j;
        for(i=0; i<games.size(); i++)
        {
            for(j=0; j<cart.size(); j++)
            {
                if(games[i].getName() == cart[j].getName())
                {
                    games.at(i)=(Game(games[i].getName(), games[i].getPrice(), games[i].getQuantity()-1));
                    // Adds income of owner
                    ifstream owner_file("D://Arya//C Programs//SDF LAB 2 PROJECT//owner.txt");
                    string income;
                    getline(owner_file, income);
                    owner_file.close();
                    // Uses string stream to convert string to integer
                    stringstream ss(income);
                    int int_income;
                    ss >> int_income;
                    int_income += cart[j].getPrice();
                    // Updates data into File
                    ofstream owner_file1("D://Arya//C Programs//SDF LAB 2 PROJECT//owner.txt");
                    owner_file1 << int_income;
                    owner_file1.close();
                }
            }
        }
    }
};

int main()
{

    //Choice variable for Main Menu Options
    int choice=0;

    //Object of Owner Class
    Owner owner;

    //Object of Customer Class
    Customer customer;

    Sleep(500);
    cout << "\n" << endl;
    Sleep(200);
    cout << "\t*********************************LOADING GAMES IN THE SERVER*********************************" << endl;
    Sleep(200);
    cout <<  endl;
    Sleep(200);
    cout << endl;

    //Loads Games from File
    owner.loadGamesFromFile();

    Sleep(100);
    system("CLS");
    while(choice!=3)
    {
        system("CLS");
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        intro();
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << endl;
        Sleep(100);
        cout << endl;
        cout << "\tWHICH TYPE OF ACCOUNT DO YOU WANT TO LOG IN?" << endl;
        Sleep(100);
        cout << "\t1. OWNER" << endl;
        Sleep(100);
        cout << "\t2. CUSTOMER" << endl;
        Sleep(100);
        cout << "\t3. EXIT THE STORE" << endl;
        Sleep(100);
        cout <<  endl;
        Sleep(100);
        cout << "\tENTER CHOICE: ";
        cin >> choice;
        Sleep(100);
        cout <<  endl;
        Sleep(500);
        switch(choice)
        {
            case 1:
            {
                system("CLS");

                Sleep(200);
                cout <<  endl;
                Sleep(100);
                cout << "\t*********************************REDIRECTING TO OWNER LOGIN PAGE...*********************************" << endl;
                Sleep(100);
                cout <<  endl;
                Sleep(200);

                owner.ownerLogin();

                owner.saveGamesToFile();
                break;
            }
            case 2:
            {
                system("CLS");
                Sleep(200);
                cout <<  endl;
                Sleep(100);
                cout << "\t**********************************REDIRECTING TO CUSTOMER MENU...*********************************" << endl;
                Sleep(100);
                cout <<  endl;
                Sleep(200);

                customer.menu();
                break;
            }

            case 3:
            {
                system("CLS");
                Sleep(200);
                cout <<  endl;
                Sleep(100);
                cout << "\tEXITING THE STORE..." << endl;
                Sleep(100);
                cout <<  endl;
                Sleep(600);

                system("CLS");
                Sleep(200);

                cout << "THIS PROJECT WAS MADE BY THE FOLLOWING STUDENTS OF JIIT: " << endl;
                Sleep(100);
                cout << "ENROLL NO:         NAME:                BATCH:" << endl;
                cout << "23103310           Sneha Srijaya        B11" << endl;
                Sleep(100);
                cout << "23103327           Sneha Gusain         B11" << endl;
                Sleep(100);
                cout << "23103329           Kritika Bhatt        B11" << endl;
                Sleep(100);
                cout << "23103330           Arya Dhawan          B11" << endl;
                Sleep(200);
                break;
            }
            default:
            {
                system("CLS");
                Sleep(200);
                cout <<  endl;
                Sleep(100);
                cout << "INCORRECT INPUT..." << endl;
                Sleep(100);
                cout <<  endl;
                Sleep(100);
                Sleep(200);
                system("CLS");
            }
        }
        cout << endl;
    }
}