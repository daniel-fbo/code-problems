#include <iostream>
#include <iomanip>
using namespace std;

double power(int a, int b){
    if (!b) {
        return 1;
    }
    else{
        return a * power(a,b-1);
    }
}

int main(void) {
    int a,b;
    cin >> a >> b;

    if (!a && b<=0){
        cout << "indefinido" << endl;
    } else if (b < 0) {
        cout << 1/power(a,-b) << endl;
    } else {
        cout << power(a,b) << endl;
    }
    return 0;
}
