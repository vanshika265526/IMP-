#include <iostream>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {
    // Edge case: if any number is "0"
    if (num1 == "0" || num2 == "0") return "0";

    int m = num1.size();
    int n = num2.size();

    // Result array can have at most m + n digits
    vector<int> result(m + n, 0);

    // Traverse both numbers from right to left
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {

            // Convert characters to integers
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';

            // Multiply current digits
            int mul = digit1 * digit2;

            // Positions in result array
            int pos1 = i + j;       // position for carry
            int pos2 = i + j + 1;   // position for current digit

            // Add multiplication result to existing value at pos2
            int sum = mul + result[pos2];

            // Store unit digit at pos2
            result[pos2] = sum % 10;

            // Add carry to pos1
            result[pos1] += sum / 10;
        }
    }

    // Convert result array to string
    string ans = "";

    for (int num : result) {
        // Skip leading zeros
        if (!(ans.empty() && num == 0)) {
            ans += (num + '0');  // convert digit to char
        }
    }

    // If all digits were zero
    return ans.empty() ? "0" : ans;
}

int main() {
    string num1 = "123";
    string num2 = "45";

    cout << multiply(num1, num2);
    return 0;
}
