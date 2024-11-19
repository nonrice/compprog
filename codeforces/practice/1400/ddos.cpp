#include <iostream>

int main(){
    int len;
    int nums[5000];
    std::cin >> len;
    for (int i=0; i<len; ++i)
        std::cin >> nums[i];

    int longest = 0;
    int sum;
    for (int i=0; i<len; ++i){
        sum = 0;
        for (int j=i; j<len; ++j){
            sum += nums[j];
            if (j-i+1 > longest && sum > 100*(j-i+1))
                longest = j-i+1;
        }
    }

    std::cout << longest;
}
