#include <iostream>
#include <vector>
#include <dirent.h>
#include <string.h>
#include <fstream>

using namespace std;

int main() {
    DIR *dir; struct dirent *diread;
    vector<char *> files;
    
    if ((dir = opendir("./data/")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            string str(diread->d_name);
            if ((str.find(".xml")!=string::npos) || (str.find(".txt")!=string::npos)){
                files.push_back(diread->d_name);
            }
            }
    }

    for (auto file : files) {
        //cout << file << endl;
        string line;
        string str(file);
        //printf("//data//&s", str);
        //cout << "/data/" << file << endl;
        str="data/"+str;
        cout << str << endl;
        ifstream myfile (str);
        if (myfile.is_open()){
            while ( getline (myfile,line) ){
                cout << line << '\n';
            }
        myfile.close();
        }else cout << "Unable to open file\n";
    }

    return EXIT_SUCCESS;
}
