#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool canArrangeTrains(int n, vector<int> trainOrder) {
    stack<int> s;
    int currCar = 1; // Expected next car number
    
    for (int i = 0; i < n; i++) {
        if (trainOrder[i] == currCar) {
            currCar++;
        } else {
            while (!s.empty() && s.top() == currCar) {
                s.pop();
                currCar++;
            }
            s.push(trainOrder[i]);
        }
    }
    
    while (!s.empty() && s.top() == currCar) {
        s.pop();
        currCar++;
    }
    
    return (currCar == n + 1);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> trainOrder(n);
    for (int i = 0; i < n; i++)
        cin >> trainOrder[i];
    
    if (canArrangeTrains(n, trainOrder))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}
