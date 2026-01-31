/*
A girl has Input1 distinct ideas.
She wants to form different combinations of ideas.
She can choose at most Input2 ideas to form a combination.
Each combination must contain at least one idea.
The order of ideas does not matter, and no idea can be repeated within a combination.
Your task is to determine the total number of distinct combinations of ideas she can form.

Input
Input1: An integer representing the total number of distinct ideas.
Input2: An integer representing the maximum number of ideas allowed in a combination.

Output
An integer representing the total number of possible combinations.

Example 1
Input
Input1 = 4  
Input2 = 2
Output 10

Example 2
Input
Input1 = 5  
Input2 = 3
Output 25

*/
#include <bits/stdc++.h>
using namespace std;

long long optimizedCount(int n, int k) {
    long long ans = 0;
    long long comb = 1; // C(n,0)

    for (int i = 1; i <= k; i++) {
        comb = comb * (n - i + 1) / i; // C(n,i)
        ans += comb;
    }

    return ans;
}

int main() {
    int input1, input2;
    cin >> input1 >> input2;

    cout << optimizedCount(input1, input2);
    return 0;
}

