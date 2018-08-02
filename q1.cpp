#include<iostream>
#include<vector>

template <typename T>
void read_array(int n, std::vector<T>& input){
    T temp{};
    // auto inn{new std::vector<int>};
    for(int i=0; i<n; i++){
        std::cin >> temp;
        input.push_back(temp);
    }
}


int main(){

    std::vector<int> input{};
    int len{}, sum{};

    std::cin >> len >> sum;

    // debug
    // std::cout << len << sum;

    read_array(len, input);

    for(int i=0; i<len; i++){
        int one{input[i]};
        for(int j=i+1; j<len; j++){
            if(one + input[j] == sum)
                std::cout << one << ", " << input[j] << "\n";
        }
    }
    std::cout << std::endl;
    return 0;
}