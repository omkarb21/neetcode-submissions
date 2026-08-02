class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        vector<int> result(n1 + n2, 0);

        // Multiply each digit pair and add to the correct position
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;       // higher digit position
                int p2 = i + j + 1;   // lower digit position

                int sum = mul + result[p2];

                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }

        // Convert result array to string, skipping leading zeros
        string res;
        for (int num : result) {
            if (!(res.empty() && num == 0)) {
                res.push_back(num + '0');
            }
        }

        return res.empty() ? "0" : res;
    }
};