#ifndef SPARSEPOLY_HPP
#define SPARSEPOLY_HPP

#include <stdio.h>
#include <vector>

#define MAX_DEGREE 101  

class SparsePoly {
    int numTerms = 0;
    std::vector<int> exponents;
    std::vector<float> coefficients;

public:
    SparsePoly() = default;

    void read() {
        printf("항의 개수를 입력하세요: ");
        if (scanf_s("%d", &numTerms) != 1 || numTerms < 1) {
            printf(" 입력 오류 .\n");
            return;
        }

        for (int i = 0; i < numTerms; ++i) {
            float coeff = 0.0f;
            int exp = 0;
            printf("%d번째 항의 계수와 차수를 입력하세요 (예: 계수 차수): ", i + 1);
            if (scanf_s("%f %d", &coeff, &exp) != 2) {
                printf("입력 오류.\n");
                return;
            }

            if (coeff != 0) {
                coefficients.push_back(coeff);
                exponents.push_back(exp);
            }
        }
    }
    void display(const char* str) {
        printf("%s", str);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            printf("%.1fx^%d", coefficients[i], exponents[i]);
            if (i != coefficients.size() - 1) {
                printf(" + ");
            }
        }
        printf("\n");
    }


    void add(SparsePoly a, SparsePoly b) {
        size_t i = 0, j = 0;
        while (i < a.coefficients.size() && j < b.coefficients.size()) {
            if (a.exponents[i] > b.exponents[j]) {
                coefficients.push_back(a.coefficients[i]);
                exponents.push_back(a.exponents[i]);
                ++i;
            }
            else if (a.exponents[i] < b.exponents[j]) {
                coefficients.push_back(b.coefficients[j]);
                exponents.push_back(b.exponents[j]);
                ++j;
            }
            else {
                float sum = a.coefficients[i] + b.coefficients[j];
                if (sum != 0) {
                    coefficients.push_back(sum);
                    exponents.push_back(a.exponents[i]);
                }
                ++i;
                ++j;
            }
        }


        while (i < a.coefficients.size()) {
            coefficients.push_back(a.coefficients[i]);
            exponents.push_back(a.exponents[i]);
            ++i;
        }

        while (j < b.coefficients.size()) {
            coefficients.push_back(b.coefficients[j]);
            exponents.push_back(b.exponents[j]);
            ++j;
        }
    }
};

#endif