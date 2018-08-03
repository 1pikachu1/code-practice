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
    // type remove(type);
    binary_tree<type>* search(type);
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
type remove(binary_tree<type>** tree, type a, binary_tree<type>* parent = nullptr){
    if((*(tree))->value == a){
        if((*(tree))->left != nullptr){
            (*(tree))->value = ((*tree)->left)->value;  
            remove(&((*(tree))->left), ((*(tree))->left)->value, (*(tree)));
        }
        else if((*(tree))->right != nullptr){
            (*(tree))->value = ((*tree)->right)->value;
            remove(&((*(tree))->right), ((*(tree))->right)->value, (*(tree)));
        }
        else{
            type ret = (*(tree))->value;
            if(parent->left != nullptr && parent->left->value == a)
                    parent->left = nullptr;
            else if(parent->right->value == a)
                    parent->right = nullptr;
            delete (*(tree));
            return ret;
        }
    }
    else if((*(tree))->value < a){
        if((*(tree))->right != nullptr)
            remove(&((*(tree))->right), a, (*(tree)));
    }
    else if((*(tree))->value > a){
        if((*(tree))->left != nullptr)
            remove(&((*(tree))->left), a, (*(tree)));
    }

    return type{};
}

template <typename type>
binary_tree<type>* binary_tree<type>::search(type a){
    if(empty)
        return nullptr;
    else{
        if(value == a)
            return this;
        else if(value > a){
            if(left == nullptr)
                return nullptr;
            return left->search(a);
        }
        else if(value < a){
            if(right == nullptr)
                return nullptr;
            return right->search(a);    
        }
    }
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
    binary_tree<int>* a = new binary_tree<int>(30);
    a->insert(15);
    a->insert(35);
    a->insert(10);
    apply_preorder<int, void(int, int)>(*a, print);

    if(a->search(15) != nullptr)
        std::cout << "here:" << (a->search(15))->value <<"\n";

    remove(&a , 35);
    apply_preorder<int, void(int, int)>(*a, print);
    
}