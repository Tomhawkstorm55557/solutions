class ProductOfNumbers {
public:
    vector<long long>ans;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        int index = ans.size()-k;
        int prd = 1;
        for(int i =index;i<ans.size();i++){
            prd = prd*ans[i];
        }
        return prd;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */