//BOJO5430 AC
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    string p, x, tempS;
    char tempC;
    bool isFront = true, isError = false;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        isFront = true; 
        isError = false; 
        deque<int> dq;
        cin >> p;
        cin >> n;
        cin >> x;

        for (int i = 0; i < x.size(); i++) // 1.
        {
            if (isdigit(x[i]))
            {
                tempS += x[i]; 
            }
            else
            {
                if (!tempS.empty())
                {
                    dq.push_back(stoi(tempS));
                    tempS.clear();
                }
            }
        }
        for (int i = 0; i < p.size(); i++)
        {
            tempC = p[i];
            if (tempC == 'R')
            {
                isFront = !isFront;
            }
            else if (tempC == 'D')
            {
                if (dq.empty())
                {
                    cout << "error\n";
                    isError = true;
                    break;
                }
                else
                {
                    if (isFront)
                    {
                        dq.pop_front();
                    }
                    else
                    {
                        dq.pop_back();
                    }
                }
            }
        }
        if (!isError)
        {
            cout << "[";
            while (!dq.empty())
            {
                if (isFront)
                {
                    cout << dq.front();
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back();
                    dq.pop_back();
                }
                if (!dq.empty())
                {
                    cout << ',';
                }
            }
            cout << "]" << '\n';
        }
    }

    return 0;
}