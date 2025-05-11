class A{
    private:
        int a_ka_private;  // can't accessed and inherited 
    protected:
        int a_ka_protected; // inherited but bot accessed 
    public:
        int a_ka_public;  // inherited as well as accessed 
};


class B: private A{  // a se jo bhi aayeha bo protected rhega
    public:
        int b_ka_public;
    
    void show(){
        //  a_ka_private;
        
    }
};