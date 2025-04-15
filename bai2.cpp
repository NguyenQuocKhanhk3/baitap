// entropy_vietnamese.cpp
#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

// Hàm tính entropy (mức độ ngẫu nhiên)
double tinh_entropy(const string& van_ban) {
    map<char, int> tan_so_ky_tu;

    // Đếm số lần xuất hiện của từng ký tự
    for (char ky_tu : van_ban) tan_so_ky_tu[ky_tu]++;

    double entropy = 0.0;

    // Tính xác suất xuất hiện và áp dụng công thức entropy
    for (auto& cap : tan_so_ky_tu) {
        double xac_suat = (double)cap.second / van_ban.size();
        entropy -= xac_suat * log2(xac_suat);
    }

    return entropy;
}

int main() {
    string chuoi_nhap;
    cout << "Nhập vào một chuỗi ký tự: ";
    getline(cin, chuoi_nhap);

    // Tính entropy thực tế của chuỗi
    double H = tinh_entropy(chuoi_nhap);

    // Giả sử sử dụng bảng mã ASCII (256 ký tự có thể có)
    const int N = 256;
    double entropy_toi_da = log2(N);

    // Tính độ dư thừa thông tin
    double R = entropy_toi_da - H;

    // Xuất kết quả ra màn hình
    cout << "Entropy (H): " << H << " bit/ký tự" << endl;
    cout << "Entropy tối đa: " << entropy_toi_da << " bit/ký tự" << endl;
    cout << "Độ dư thừa (R): " << R << " bit/ký tự" << endl;

    return 0;
}
