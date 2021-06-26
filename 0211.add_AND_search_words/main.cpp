#include <iostream>
#include "Solution.h"
#include <string>

using namespace std;

int main(){
    WordDictionary dic;
    char cmdInput = '\0';
    string word;

    do
    {
        cout << "输入指令(\'a\': add. \'s\': search. \'e\':exit):";
        cin >> cmdInput;
        switch(cmdInput)
        {
        case 'a':
            //cout << "添加单词：";
            cin >> word;
            dic.addWord(word);
            break;
        case 's':
            //cout << "搜索单词：";
            cin >> word;
            printf("%s\n", dic.search(word) ? "true" : "false");
            break;
        case 'e':
            cout << "退出\n";
            break;
        default:
            cout << "错误指令" << cmdInput << "\n";
        }
    } while (cmdInput != 'e');

    return 0;
}

