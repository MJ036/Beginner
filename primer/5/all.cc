#include "mai.h"

using namespace std;

void test_12(){
    //用switch统计元音字母，含大小写
    //也能统计空格、换行、制表符的数量
    //也能统计字符序列：ff, fi , f1
    int na,ne,ni,no,nu;
    na = ne = ni = no = nu = 0;

    int ntab ,nsp , nline;
    ntab = nsp = nline =0;

    int nfi,nff,nfl;
    nfi = nff = nfl =0;

    char c,prev = '\0';
    while(cin.get(c)){
            switch(c){
            case 'a':
            case 'A':
                ++na;
                break;
            case 'e':
            case 'E':
                ne++;
                break;
            case 'i':
                if(prev == 'f'){
                    ++nfi;
                    break;
                }
            case 'I':
                ni++;
                break;
            case 'o':
            case 'O':
                no++;
                break;
            case 'u':
            case 'U':
                nu++;
                break;

            case '\t':
                ++ntab;
                break;
            case '\n':
                ++nline;
                break;
            case ' ':
                ++nsp;
                break;

            case 'f':
                    if(prev == 'f'){
                        ++nff;
                    }
                break;
            case 'l':
                    if(prev == 'f'){
                        ++nfl;
                    }
                break;
            default:
                ;
            }
            prev = c;
        }
    cout << "Number of vowel a(A): \t" << na << '\n'
        << "Number of vowel e(E): \t" << ne << '\n'
        << "Number of vowel i(I): \t" << ni << '\n'
        << "Number of vowel o(O): \t" << no << '\n'
        << "Number of vowel u(U): \t" << nu<< '\n'
        << "Number of newline: \t" << nline << '\n'
        << "Number of tab: \t" << ntab << '\n'
        << "Number of fi: \t" << nfi << '\n'
        << "Number of ff: \t" << nff << '\n'
        << "Number of fl: \t" << nfl << endl;

}

void test_14(){
    string str,pre;
    string word;
    int word_cnt;
    int temp_cnt = 1;
    while(cin >> str){
        if(str == pre){
            temp_cnt++;
        }else{
            if(temp_cnt > word_cnt){
                word = pre;
                word_cnt = temp_cnt;
            }
            temp_cnt = 1;
        }
        pre = str;
    }
    //自己的劣质写法：
    //cout << (word_cnt > 1 ? word : "not words") << endl;
    word_cnt > 1 ? (cout << "word = " << word << " counts = " << word_cnt << endl) : (cout << "no words" << endl);
}

bool test_17(){
    vector<int> vec1 = {0,1,2,2};
    vector<int> vec2 = {0,1,1,2,3,6,8};

    size_t minLenth = min(vec1.size(),vec2.size());
    for(size_t i = 0; i < minLenth; ++i){
        if(vec1[i] != vec2[i]){
            return false;
        }
    }
    return true;
}

void test_19(){
    do{
        cout << "Please enter two string:" ;
        string str1,str2;
        cin >> str1 >> str2 ;
        cout << "shorter string : ";
        str1.size() > str2.size() ? (cout << str2 << endl) : (cout << str1 << endl);

    }
    while(cin);
}

void test_20(){
    string str,pre;
    bool conti = false;
    while(cin >> str){
        if(str == pre){
            cout << "str = " << str << endl;
            conti = true;
            break;
        }
        pre = str;
    }
    if(!conti){
        cout << "no words is continuous" << endl;
    }
}
void test_21(){
    string str,pre;
    bool conti = false;
    while(cin >> str){
        if(!isupper(str[0])) continue;
        if(str == pre){
            cout << "str = " << str << endl;
            conti = true;
            break;
        }
        pre = str;
    }
    if(!conti){
        cout << "no words is continuous" << endl;
    }
}

void test_23(){
    int a,b;
    while( cin >> a >> b){
        try {
            if(b == 0){
                throw runtime_error("divide 0");
            }
            cout << a/b << endl;
        }
        catch(runtime_error err){
            cout << err.what() << "\nenter again ?(y/n) " << endl;
            char c;
            cin >> c;
            if(!cin || c == 'n') break;
        }
    }
}

int main()
{
    test_23();
}

