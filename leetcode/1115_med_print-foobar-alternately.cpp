#include <unistd.h>
class FooBar {
private:
    int n;

public:
    bool flag = true;
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while(!flag)
                usleep(1000);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            flag = false;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            while(flag)
                usleep(1000);
        	printBar();
            flag = true;
        }
    }
};