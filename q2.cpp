#include<iostream>
#include<functional>

template <typename type>
class binary_tree{
public:
    type value{};
    binary_tree<type> *left{}, *right{};
    bool empty{};

    // parameterized constructor
    binary_tree(type a){
        value = a;
        empty = false;
    }
    // default constructor
    binary_tree(){
        empty = true;
    }
    void insert(type);
    void remove(type);
};

template <typename type>
void binary_tree<type>::insert(type a){
    if(empty)
        value = a;
    else{
        if(value >= a){
            if(left == nullptr)
                left = new binary_tree<type>(a);
            else
                left->insert(a);
        }
        else{    
            if(right == nullptr)
                right = new binary_tree<type>(a);
            else
                right->insert(a);
        }
    }
}

template <typename type>
void binary_tree<type>::remove(type a){

}

template <typename type, typename func_type>
void apply_inorder(binary_tree<type> a, std::function<func_type> foo, int depth=0){
    if(a.empty)
        return;
    else{
        if(a.left != nullptr)
            apply_inorder(*(a.left), foo, depth+1);
        foo(a.value, depth);
        if(a.right != nullptr)
            apply_inorder(*(a.right), foo, depth+1);
    }
}

template <typename type, typename func_type>
void apply_preorder(binary_tree<type> a, std::function<func_type> foo, int depth=0){
    if(a.empty)
        return;
    else{
        foo(a.value, depth);
        if(a.left != nullptr)
            apply_preorder(*(a.left), foo, depth+1);
        if(a.right != nullptr)
            apply_preorder(*(a.right), foo, depth+1);
    }
}

template <typename type, typename func_type>
void apply_postorder(binary_tree<type> a, std::function<func_type> foo, int depth=0){
    if(a.empty)
        return;
    else{
        if(a.left != nullptr)
            apply_postorder(*(a.left), foo, depth+1);
        if(a.right != nullptr)
            apply_postorder(*(a.right), foo, depth+1);
        foo(a.value, depth);
    }
}


void print(int t, int tabs){
    for(int i=0; i<tabs; i++)
        std::cout << "  " ;
    std::cout << t << std::endl;
}

int main(){
    binary_tree<int> a(30);
    a.insert(15);
    a.insert(35);
    a.insert(10);
    apply_preorder<int, void(int, int)>(a, print);
}