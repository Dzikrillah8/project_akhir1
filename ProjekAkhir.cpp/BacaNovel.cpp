#include <iostream>
#include <fstream>
using namespace std;

struct Akun
{
    string username;
    string password;
};

void autentikasi(bool &isValidUser)
{
    const string filename = "akun.txt";
    ofstream fileWriter;
    ifstream fileReader;
    string linetext;
    string credentials[2];
    int pil;
    int i = 0;
    int rating;
    Akun akun;

    cout<< "\n=========================================="
            << "\n::                                      ::" 
            << "\n::      WELCOME TO BACA NOVEL.ID!       ::"
            << "\n::                                      ::"
            << "\n==========================================\n"
            << "1. Log in"
            << "\n2. Sign up\n"
            << "\nEnter choice (num): ";
    cin >> pil;

    switch (pil)
    {
    case 1:
        cout << "\nLog in, please input username and password!";
        cout << "\n------------------------------------------";
        cout << "\nUsername\n";
        cout << ":> ";
        cin >> akun.username;
        cout << "Password\n";
        cout << ":> ";
        cin >> akun.password;

        fileReader.open(filename);

        while (getline(fileReader, linetext))
        {
            credentials[i] = linetext;
            i++;
        }
        fileReader.close();

        if (credentials[0] == akun.username && credentials[1] == akun.password)
        {
            isValidUser = true;

            cout << "\nLogin Succsess! Welcome " << akun.username << "! \n"
                 << endl;
        }
        else
        {
            isValidUser = false;
            cout << "Incorrect Username or Password!";
        }

        break;
    case 2:
        cout << "\nSign up, please input username and password!";
        cout << "\n------------------------------------------";
        cout << "\nUsername\n";
        cout << ":> ";
        cin >> akun.username;
        cout << "Password\n";
        cout << ":> ";
        cin >> akun.password;

        fileWriter.open(filename);
        fileWriter << akun.username << endl;
        fileWriter << akun.password << endl;
        fileWriter.close();

        isValidUser = true;

        break;

    default:
        cout << "Invalid choice." << endl;
        autentikasi(isValidUser);
        break;
    }
}

void homePage(int &pilihan)
{
    cout << "\nWhat would you like to do?" << endl;
    cout << "1. Explore Novels\n2. View Bookmarks" << endl;
    cout << "Enter choice (num): ";
    cin >> pilihan;

    if (pilihan != 1 && pilihan != 2)
    {
        cout << "\nInvalid choice, Try again!" << endl;
        homePage(pilihan);
    }
}

void readNovel(ifstream &file, string &title)
{
    string line;
    int index = 0;

    file.open(title + ".txt");
    while (getline(file, line))
    {
        if (index > 2)
        {
            cout << line << endl;
        }
        index++;
    }
    file.close();
}

void exploreNovels()
{
    string line;
    char pil;
    string title;
    char add;
    int rating;

    // explore (list)
    cout << "\n------------------------------------------";
    cout << "\n               - NOVEL LIST -              ";
    cout << "\n------------------------------------------\n";

    ifstream fileReader("listbuku.txt");

    int index = 1;

    // show only 5 stories (if next, lanjut)
    while (getline(fileReader, line))
    {

        cout << index << ". " << line << endl;

        if (index % 5 == 0)
        {
            cout << "------------------------------------------";
            cout << "\nShow more? (y/n) : ";
            cin >> pil;
            cout << "\n";

            if (pil == 'n')
            {
                break;
            }
        }

        index++;
    }
    fileReader.close();

    cin.get();
    cout << "------------------------------------------";

    cout  << "\nChoose story you want to read! (input title)\n";
    cout << ":> ";
    getline(cin, title);

    // untuk dapetin detail [author, genre]
    fileReader.open(title + ".txt");
    string detail[2];
    int i = 0;
    while (getline(fileReader, line))
    {
        detail[i] = line;
        i++;
        if (i >= 2)
        {
            break;
        }
    }
    fileReader.close();

    // book detail
    cout << "\n------------------------------------------";
    cout << "\n               " << title << "            ";
    cout << "\n------------------------------------------\n";
    // book detail 
    cout << "Story by: " << detail[0] << endl;
    cout << "Genres  : " << detail[1] << endl;
    cout << "\n------------------------------------------";

    // add to bookmark
    cout << "\nAdd to Bookmark? (y/n): ";
    cin >> add;

    if (tolower(add) == 'y')
    {
        string bookmark[100];

        // untuk cek apakah bookmark sudah ditambah (sudah ada)
        fileReader.open("bookmark.txt");
        int i = 0;
        bool isExist = false;
        while (getline(fileReader, line))
        {
            if (title == line)
            {
                cout << title << "\nStory already added to bookmark." << endl;
                isExist = true;
                break;
            }

            bookmark[i] = line;
            i++;
        }

        // kalau belum ada tambah ke bookmark
        if (!isExist)
        {
            ofstream fileWriter("bookmark.txt");

            // tulis judul yg lama
            for (int j = 0; j < i; j++)
            {
                fileWriter << bookmark[j] << endl;
            }

            // tulis judul baru
            fileWriter << title;

            fileWriter.close();
            cout << "Story added to bookmark.\n";
        }
        fileReader.close();

        cout << "\nHappy Reading!";
        cout << "\n------------------------------------------";
        cout << "\n               " << title << "            ";
        cout << "\n------------------------------------------";
        cout << "\n\n";

        readNovel(fileReader, title);

        cout << "\n------------------------------------------";
        cout << "\n------------------------------------------";
        cout << "\nGive rating (1-5) :> ";
        cin >> rating;

        cout << "\nThank you for reading!";
    }
    else
    {

        cout << "\n------------------------------------------";
        cout << "\n               " << title << "            ";
        cout << "\n------------------------------------------";
        cout << "\n\n";

        readNovel(fileReader, title);

        cout << "\n------------------------------------------";
        cout << "\nGive rating (1-5) :> ";
        cin >> rating;

        cout << "\nThank you for reading!";
    }
}

int main()
{
    bool isValidUser = false;
    int pilihan;
    ifstream fileReader;
    ofstream fileWriter;
    string line;
    string title;
    Akun akun;
    int rating;

    do
    {
    
    autentikasi(isValidUser);

    } while (!isValidUser);

    homePage(pilihan);
    cin.get();
    switch (pilihan)
    {
    case 1:
        exploreNovels();
        break;
    case 2:

        int pil;
        fileReader.open("akun.txt");
        string akun[2];
        int a = 0;
        while (getline(fileReader, line))
        {
            akun[a] = line;
            a++;
            if (a >= 2)
            {
                break;
            }
        }
        fileReader.close();

        cout << "\n------------------------------------------\n";
        cout << akun[0] << "'s BOOKMARK LIST Page \n\n";
        cout << "------------------------------------------\n"; 

        int i = 1;

        fileReader.open("bookmark.txt");
        while (getline(fileReader, line))
        {
            cout << i << ". " << line << endl;
            i++;
        }
        fileReader.close();

        cout << "\n------------------------------------------\n";

        cout << "Choose story (input title)\n";
        cout << ":> ";
        getline(cin, title);
        cout << " " << endl;

        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Read story\n2. Delete story from bookmark" << endl;
        cout << "Enter choice (num): ";
        cin >> pil;

        switch (pil)
        {
        case 1:
            cout << "\nReading" << " " << title << " " << "in progress.\n" << endl;
            cout << "\nHappy Reading!";
            cout << "\n------------------------------------------";
            cout << "\n               " << title << "            ";
            cout << "\n------------------------------------------";
            cout << "\n\n";

            readNovel(fileReader, title);

            cout << "\n------------------------------------------";
            cout << "\nGive rating /5 :> ";
            cin >> rating;

            cout << "\nThank you for reading!";

            break;
        case 2:
            string juduls[999];
            int i = 0;
            // ambil semua judul yang bukan == title terpilih
            fileReader.open("bookmark.txt");
            while (getline(fileReader, line))
            {
                if (title != line)
                {
                    juduls[i] = line;
                    i++;
                }
            }
            fileReader.close();

            // tulis judul kembali
            fileWriter.open("bookmark.txt");
            for (int j = 0; j < i; j++)
            {
                fileWriter << juduls[j] << endl;
            }
            fileWriter.close();

            cout <<"\n";
            cout << title << " " << "deleted from bookmark.";

            break;
        }

        break;
    }

    return 0;
}