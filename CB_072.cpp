#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm kiểm tra xem số có chứa chữ số 3, 5 hoặc 7 không
bool contains357(int n) {
    while (n > 0) {
        int digit = n % 10;  // Lấy chữ số cuối
        if (digit == 3 || digit == 5 || digit == 7) {
            return true;  // Ngay lập tức trả về true nếu tìm thấy 3, 5 hoặc 7
        }
        n /= 10;  // Loại bỏ chữ số cuối
    }
    return false;
}

// Hàm sàng Eratosthenes để tìm tất cả các số nguyên tố từ 1 đến n
void sieveOfEratosthenes(int n, vector<bool>& isPrime) {
    isPrime[0] = isPrime[1] = false;  // 0 và 1 không phải là số nguyên tố
    for (int i = 2; i <= sqrt(n); ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;  // Đánh dấu các số không phải là số nguyên tố
            }
        }
    }
}

// Hàm đếm số nguyên tố đẹp từ 1 đến n
int countBeautifulPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    sieveOfEratosthenes(n, isPrime);

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i] && contains357(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int result = countBeautifulPrimes(n);
    cout << result << endl;

    return 0;
}
