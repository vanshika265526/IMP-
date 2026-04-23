#include <iostream>
using namespace std;

string addStrings(string num1, string num2) {
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;

    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;

        result += (sum % 10) + '0';  // convert back to char
        carry = sum / 10;

        i--;
        j--;
    }

    // reverse the result
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string num1 = "456";
    string num2 = "789";

    cout << addStrings(num1, num2);
    return 0;
}
