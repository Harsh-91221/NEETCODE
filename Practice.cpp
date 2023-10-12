#include <iostream>
#include <vector>

using namespace std;

// Function to find prime factors of a number
vector<int> primeFactors(int num)
{
    vector<int> factors;
    for (int i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            factors.push_back(i);
            num /= i;
        }
    }
    if (num > 1)
    {
        factors.push_back(num);
    }
    return factors;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> primeCounts(n);

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vector<int> factors = primeFactors(num);
        for (int factor : factors)
        {
            primeCounts[i].push_back(factor);
        }
    }

    // Count the occurrences of each prime factor
    vector<int> primeFrequency(1001, 0); // Assuming maximum prime factor is 1000
    for (int i = 0; i < n; i++)
    {
        for (int factor : primeCounts[i])
        {
            primeFrequency[factor]++;
        }
    }

    // Check if the count of each prime factor is divisible by n
    for (int i = 2; i < primeFrequency.size(); i++)
    {
        if (primeFrequency[i] % n != 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
