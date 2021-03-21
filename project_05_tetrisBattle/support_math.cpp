#include <vector>

#include "support_math.h"


int sumInt(int *pdata, uint32_t length) {
    int temp = 0;
    for(uint32_t i=0;i<length;i++) {
        temp += pdata[i];
    }
    return temp;
}

std::vector<std::vector<int>> matmul(std::vector<std::vector<int>> vect1, 
                                    std::vector<std::vector<int>> vect2) {
    std::vector<std::vector<int>> rotateCor (vect1.size(), std::vector<int>(vect2[0].size(), 0));
    for(std::vector<int>::size_type i=0;i<vect1.size();i++) {
        for(std::vector<int>::size_type j=0;j<vect2.size();j++) {
            int sum = 0;
            for(std::vector<int>::size_type k=0;k<vect2[0].size();k++) {
                sum += vect1[i][k] * vect2[k][j];
            }
            rotateCor[i][j] = sum;
        }
    }
    return rotateCor;
}
