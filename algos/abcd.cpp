// this is incomplete
#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <math.h>

using namespace std;

const int n = 1000;

int main()
{
    unordered_map<int, list<int>> map;
    int result;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            result = (int) pow(i, 3) + (int) pow(j, 3) // i^3 + j^3
            list<int> newList;
            newList.push_back(i);
            newList.push_back(j);
            map[result] = newList; // map result back to original numbers
        }

    for (auto entry : map) {
        list<int> list = entry.second;
        for(auto pair1 : list)
            for(auto pair2 : list)
                cout << pair1 << " | " << pair2;
    }
}
