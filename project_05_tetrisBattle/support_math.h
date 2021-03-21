#ifndef SUPPORT_MATH_H
#define SUPPORT_MATH_H

#include <stdint.h>

int sumInt(int *pdata, uint32_t length);
std::vector<std::vector<int>> matmul(std::vector<std::vector<int>> vect1, 
                                    std::vector<std::vector<int>> vect2);


#endif /* SUPPORT_MATH_H */
