#include<iostream>
#include<vector>

// find all subsets that sum up to s
void subset_sum(std::vector<int>& a,
    int sum,
    std::vector<int> partial = std::vector<int> {},
    int cursum = 0,
    int k = 0
){
    // pruning the tree when sum exceeds
    if(cursum > sum || k >= a.size())
        return;

    if(cursum == sum){
        for(int &i: partial)
            std::cout << i << ", ";
        std::cout << "\n";
    }
    else{
        subset_sum(a, sum, partial, cursum, k+1);
        partial.push_back(a[k]);
        subset_sum(a, sum, partial, cursum + a[k], k+1);
    }
}


int main(){
    std::vector<int> a{1,2,3,4,12,5,6,7,11,10};

    subset_sum(a, 10);

    return 0;
}