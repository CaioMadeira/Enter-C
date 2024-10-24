#include<iostream>
#include <vector>

extern "C"
{
    #include<stdio.h>
    #include<stdlib.h>
}

using namespace std;

void printvector(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
        printf("|%d", v[i]);
    printf("\n\n");
}

vector<int> createL3(vector<int> L1, vector<int> L2)
{
    vector<int> L3;
    for(int i = 0; i < L1.size(); i++)
    {
        for(int j = 0; j < L2.size(); j++)
        {
            if (L1[i] == L2[j])
            {
                L3.push_back(L2[j]);
            }
        }
    }

    return L3;
}

int maxValue(vector<int> L3)
{
    int maxNum = L3[0];
    for(int k = 0; k < L3.size(); k++)
    {
        if (L3[k] > maxNum)
        {
            maxNum = L3[k];
        }
    }
    return maxNum;
}

int main(int argc, char* argv[])
{
    vector<int> L1 = { 04, 12, 07, 30, 20, 59, 28};
    vector<int> L2 = {50, 07, 04, 21, 33};

    cout << "L1: " << endl;
    printvector(L1);

    cout << "L2: " << endl;
    printvector(L2);

    cout << "L3: " << endl;
    vector<int> L3 = createL3(L1, L2);
    printvector(L3);

    int r = maxValue(L3);
    printf("O maior valor armazenado nas duas listas simultaneamente é %d\n", r);
}