#include "die.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime> // for time

int main() {
    srand (time(NULL));

    std::vector<Die> dice;
    int faces = 1;
    
    while(faces>0) {
        for(auto d : dice) std::cout << d.faces() << ' ';
        std::cout << "How many faces? ";
        std::cin >> faces;
        if(faces > 0) dice.push_back(Die{faces});
    }

    int rolls;
    std::cout << "Number of rolls? ";
    std::cin >> rolls;

    int total = 0;
    std::vector<int> results;
    for(int i=0; i<rolls; ++i) {
        int sum = 0;
        for(Die& d : dice) {
            int roll = d.roll();
            std::cout << roll << ' ';
            sum += roll;
        }
        std::cout << "= " << sum << std::endl;
        results.push_back(sum);
        total += sum;
    }

    std::sort(results.begin(), results.end());
    for(auto i : results) std::cout << i << ' ';
    std::cout << std::endl;
    
    std::cout << "Sum =    " << total << std::endl;
    std::cout << "Mean =   " << (double)total / (double)rolls << std::endl;
    
    std::cout << "Median = ";
    if (rolls % 2) std::cout <<  results[results.size()/2] << std::endl;
    else std::cout << double(results[results.size()/2] + results[results.size()/2-1])/2.0 << std::endl;

    int mode = 0;
    int mode_count = 0;
    int count = 0;
    for(int i=1; i<results.size(); ++i) {
        if (results[i] == results[i-1]) count++;
        if ((results[i] != results[i-1]) || (i == (results.size()-1))) {
            if (count > mode_count) {
                mode = results[i-1];
                mode_count = count;
            }
            count = 1;
        }
    }
    std::cout << "Mode =   " << mode << " (appeared " << mode_count << " times)" << std::endl;
}
