class ProductOfNumbers {
    vector<long long> products;
    long long currentProduct = 1;
    long long totalProduct = 1;
public:
    void add(int num) {
        if(num == 0){
            products.erase(products.begin(), products.end());
            currentProduct = 1;
        }
        else{
            currentProduct*=1LL*num;
            products.push_back(currentProduct);
        }
    }
    
    int getProduct(int k) {
        if(k>products.size())
            return 0;
        else if(k == products.size())
            return currentProduct;
        long long productBeforeKNumbers = products[products.size() - k - 1];
        return currentProduct / productBeforeKNumbers;
    }
};