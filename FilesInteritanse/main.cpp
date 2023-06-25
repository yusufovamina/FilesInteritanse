#include<iostream>
using namespace std;

int decToBin(int num)
{
    int bin = 0, k = 1;

    while (num != 0)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}


class File {
public:
    FILE* file;
    virtual void Display(const char* path) {
        fopen_s(&file, path, "r");
        if (file == nullptr) {
            cout << "Couldn't open the file" << endl;
            return;
        }

        char buffer[256];
        while (fscanf_s(file, "%s", buffer, sizeof(buffer)) != EOF) {
            cout << buffer << " ";
        }

        fclose(file);
    }

    void fill_file(const char* str, const char* path) {
        fopen_s(&file, path, "w");

        if (file != NULL) {
            fputs(str, file);
            fclose(file);
        }
    }
};


class ASCIIDisplay : public File {
public:
    void Display(const char* path) {
        fopen_s(&file, path, "r");
        if (file == nullptr) {
            cout << "Couldn't open the file" << endl;
            return;
        }

        int ch;
        while ((ch = fgetc(file)) != EOF) {
            cout << int(ch) << " ";
        }

        fclose(file);
    }
};

class BinaryDisplay : public File {
public:
    void Display(const char* path) {
        fopen_s(&file, path, "r");
        if (file == nullptr) {
            cout << "Couldn't open the file" << endl;
            return;
        }

        int ch;
        while ((ch = fgetc(file)) != EOF) {
            cout << decToBin(int(ch)) << " ";
        }

        fclose(file);
    }
};

int main() {
    BinaryDisplay file;
    file.fill_file("hello mir", "TEST");
    file.Display("TEST");
}