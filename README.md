#include <iostream>
#include <fstream>
using namespace std;

//--lili start

int main() {

string line;
char pil;
string filename;
string title;
char add;

//explore

    cout << "\n------------------------------------------";
    cout << "\n               - BOOK LIST -              ";
    cout << "\n------------------------------------------";
    cout << "\n------------------------------------------\n";

    ifstream file("listbuku.txt");

    int index = 1;

    while (getline (file, line)) {
        cout << index << ". " << line << endl;
        index++;

}
    file.close();

    cout << "------------------------------------------";

    cout << "\nChoose book you want to read! (input title)\n";
    cout << ":> ";
    cin >> title;

    //book detail
    cout << "\n------------------------------------------";    
    cout << "\n               " << title << "            ";
    cout << "\n------------------------------------------";
    cout << "\n Add to Bookmark? (y/n): ";
    cin >> add;

    if (tolower(add) == 'y')
    {
        ofstream file("bookmark.txt");

        file << "" << title;

        file.close();
    } else {
        cout << "\n input title one more time to read!\n";
        cout << ":> ";

        cin >> filename;
        filename += ".txt";

        cout << "\n------------------------------------------";    
        cout << "\n               " << title << "            ";
        cout << "\n------------------------------------------";
        cout << "\n\n";

        ifstream readfile(filename);

        while (getline (readfile, filename)) {
        cout << filename;

        cout << "\n";
        cout << "\n------------------------------------------";
        }

        readfile.close();

        }

    // --lili end

return 0;

}
