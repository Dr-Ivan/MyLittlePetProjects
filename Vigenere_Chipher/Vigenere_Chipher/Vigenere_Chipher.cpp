#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Chipher {
private:
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char encode_letter(char text, char key) {
        char code = (text + key) % 26 + 'a';
        return code;
    };

    char decode_letter(char code, char key) {
        char text;
        if (code >= key) {
            text = (code - key) % 26 + 'a';
        } else {
            text = 'z' + 1 + (code - key) % 26;
        };
        //std::cout << code << ' ' << key << " -> " << text << endl;
        return text;
    };

public:
    string encode_string(string text, string key) {
        string coded;
        int len_text = text.size();
        int len_key = key.size();
        transform(text.begin(), text.end(), text.begin(), toupper);
        transform(key.begin(), key.end(), key.begin(), toupper);
        for (int i = 0; i < len_text; i++) {
            if (find(this->letters.begin(), this->letters.end(), text[i]) != this->letters.end()) {
                coded.push_back(this->encode_letter(text[i], key[i % len_key]));
            } else {
                coded.push_back(text[i]);
            };
        };
        return coded;
    };

    string decode_string(string code, string key) {
        string decoded;
        int len_code = code.size();
        int len_key = key.size();
        transform(code.begin(), code.end(), code.begin(), toupper);
        transform(key.begin(), key.end(), key.begin(), toupper);
        for (int i = 0; i < len_code; i++) {
            if (find(this->letters.begin(), this->letters.end(), code[i]) != this->letters.end()) {
                decoded.push_back(this->decode_letter(code[i], key[i % len_key]));
            } else {
                decoded.push_back(code[i]);
            };
        };
        return decoded;
    };

    bool check_key(string key) {
        transform(key.begin(), key.end(), key.begin(), tolower);
        return all_of(key.begin(), key.end(), [](int x) {return ( 97 <= x ) && ( x <= 122 ); });
    };
};

int main()
{
    Chipher* cryptographer = new Chipher();

    bool running = true;
    char op_num;
    string key_word;
    string user_text;
    string result;

    while (running)
    {
        std::cout << "Choose operation: " << endl;
        std::cout << "\t1 - encrypt text" << endl;
        std::cout << "\t2 - decrypt text" << endl;
        std::cout << "\t3 - exit program" << endl;
        std::cout << "Operation number: ";
        cin >> op_num;
        std::cout << endl;

        if (op_num == '1') {
            std::cout << "Enter your key word: ";
            std::getline(std::cin, key_word);
            std::getline(std::cin, key_word);
            std::cout << endl;
            if (!cryptographer->check_key(key_word)) {
                std::cout << "Wrong key word! \nKey word can have only English letters. " << endl;
                std::cout << "Restarting program...  " << endl;
                std::cout << endl;
                continue;
            };
            std::cout << "Enter text you want to encrypt. " << endl;
            std::getline(std::cin, user_text);
            std::cout << endl;
            result = cryptographer->encode_string(user_text, key_word);
            std::cout << "Your text was encrypted. " << endl;
            std::cout << result << endl;
            std::cout << endl;
        }
        else if (op_num == '2') {
            std::cout << "Enter your key word: ";
            std::getline(std::cin, key_word);
            std::getline(std::cin, key_word);
            std::cout << endl;
            if (!cryptographer->check_key(key_word)) {
                std::cout << "Wrong key word! \nKey word can have only English letters. " << endl;
                std::cout << "Restarting program...  " << endl;
                std::cout << endl;
                continue;
            };
            std::cout << "Enter text you want to decrypt. " << endl;
            std::getline(std::cin, user_text);
            std::cout << endl;
            result = cryptographer->decode_string(user_text, key_word);
            std::cout << "Your text was decrypted. " << endl;
            std::cout << result << endl;
            std::cout << endl;
        }
        else if (op_num == '3') {
            std::cout << "Exiting..." << endl;
            running = false;
        }
        else {
            std::cout << "Wrong operation number! " << endl;
            std::cout << "Restarting program...  " << endl;
            std::cout << endl;
            continue;
        };
        std::cout << endl << endl;
    };

    return 0;
};
