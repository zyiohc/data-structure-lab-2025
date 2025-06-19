#include <opencv2/opencv.hpp>
#include <iostream>

int main() {

    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

    if (img.empty()) {
        std::cerr << "�̹����� �ҷ��� �� �����ϴ�." << std::endl;
        return -1;
    }

    double minVal, maxVal;
    cv::minMaxLoc(img, &minVal, &maxVal);

    std::cout << "�ִ� ��Ⱚ: " << maxVal << std::endl;

    return 0;
}