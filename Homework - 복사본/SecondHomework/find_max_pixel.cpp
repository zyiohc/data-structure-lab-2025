#include <opencv2/opencv.hpp>
#include <iostream>

int main() {

    cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

    if (img.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다." << std::endl;
        return -1;
    }

    double minVal, maxVal;
    cv::minMaxLoc(img, &minVal, &maxVal);

    std::cout << "최대 밝기값: " << maxVal << std::endl;

    return 0;
}