#include <iostream>
#include <string>

using namespace std;
void checkvpr(string str){
    int cnt = 0;
    while(str.length() > 0){
        if(str.at(cnt) == ')'){
            str.erase(cnt-1,2);
            cnt=0;
            continue;
        }
        cnt++;
    }
    if(str.length() == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
     
}

int main(void) {
    int t = 0;
    string str;
    cin >> t;
    for(int i = 0; i<t; i++){
        cin >> str;
        checkvpr(str);
    }
    
    

    return 0;
}