#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class WordList{
private:
    vector<string> dictionary;
    list<string> wordlist;
public:
    WordList(); // dic.txt�κ��� ��� �ܾ���� �ҷ��� dictionary�� ����
    void CheckDictionary(string str); // str�� dictionary ���� ���� Ȯ��
    void CheckDuplication(string str); // str�� wordlist �ߺ� ���� Ȯ��
    void CheckConfirm(string str); // str�� ù���ڿ� ���� ����Ʈ�� ������ �ܾ��� �� ���� ���� ���� Ȯ��
    void add(string str); // �� 3���� check �� wordlist.push_back
    void startGame(); // ���ӽ���
};

int main(){
    WordList wl;
    wl.startGame();

    return 0;
}

WordList::WordList(){
    ifstream in("dict.txt");
    string tmp;
    if(!in.is_open()){
        cout << "[ERROR] File not Found" << endl;
        exit(0);
    }
    while(in >> tmp)
        dictionary.push_back(tmp);
    in.close();
}

void WordList::CheckDictionary(string str){
    vector<string>::iterator f = find(dictionary.begin(), dictionary.end(), str);
    if(f == dictionary.end())
        throw string("Not exitst word in dictionary");
}

void WordList::CheckDuplication(string str){
    list<string>::iterator f = find(wordlist.begin(), wordlist.end(),str);
    if(f != wordlist.end())
        throw string("It's Duplication");
}

void WordList::CheckConfirm(string str){
    if(!wordlist.empty()){
        string last = *(--wordlist.end()); // ������ �ܾ� ��������
        if(last[last.length()-1] != str[0]) // ������ �ܾ��� ���������ڿ� ���� �ܾ��� ù���� ��ġ����Ȯ��
            throw string("Not same as the previous word alphabet");
    }
}

void WordList::add(string str){
    static ofstream out("result.txt");

    try{
        for(int i=0;i<str.length();i++)
            if(!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
                throw string("It is not English");
        CheckDictionary(str);
        CheckDuplication(str);
        CheckConfirm(str);
    }catch(string err){
        out.close();
        throw err;
    }
    wordlist.push_back(str);
    out << str << " ";
}

void WordList::startGame(){
    string word;
    cout << "Game Start" << endl;
    while(1){
        cout << "Input word : ";
        cin >> word;
        try{
            add(word);
        }catch(string err){
            cout << "You Lose. " + err << endl;
            return;
        }
        for(list<string>::iterator i = wordlist.begin() ; i != wordlist.end() ; i++)
            cout << *i << " ";
        cout << endl;
    }
}