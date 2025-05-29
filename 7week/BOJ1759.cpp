//BOJ1759 암호 만들기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;

void dfs(vector<char> v, int now, string str, int conso, int vowel){
    str.push_back(v[now]);
    if(v[now] == 'a' || v[now] == 'e' || v[now] == 'i' || v[now] == 'o' || v[now] == 'u')
        vowel++;
    else
        conso++;
    
    if(str.length() == L){
        if(vowel >=1 && conso >= 2)
            cout << str << '\n';
        return;
    }
    for(int i=now+1; i < C; i++)
        dfs(v, i, str, conso, vowel);
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    vector<char> v(C);

    for(int i=0; i<C; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    for(int i=0; i<=C-L; i++)
    {
        dfs(v,i,"",0,0);
    }
    
    return 0;
}