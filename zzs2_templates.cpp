#include <iostream>
using namespace std;
template <typename T>
void input(T* arr, int n){
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
}

template <typename T>
bool ordered(T arr, int n){
    for(int i = 0; i < n-1; i++){
        if(arr[i] >= arr[i+1]){
            return false;
        }
    }
    return true;
}

template <typename T>
bool member(T* arr, int n, T x){
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            return true;
        }
    }
    return false;
}

typedef double (*func) (double);



double f1(double a){
    return a+1;
}
double f2(double a){
    return a/2;
}
double f3(double a){
    return a*3;
}
double f4(double a){
    return a-88;
}
double f5(double a){
    return a+4;
}

double fmax(double (*f) (double a), double (*g) (double a), double x){
    if(f(x) > g(x)){
        return f(x);
    }
    return g(x);
}

template <typename T>
double maxarrayA (T arr, int n, double x){
    double m = arr[0](x);
    for(int i = 1; i < n; i++){
        if(arr[i](x) > m){
            m = arr[i](x);
        }
    }
    return m;
}


template <typename T>
double maxarrayB(T arr, int n, double x){
    double m = arr[0](x);
    for(int i = 1; i < n-1; i++){
        if(fmax(arr[i+1], arr[i], x) > m){
            m = fmax(arr[i+1], arr[i], x);
        }
    }
    return m;
}

template <typename T>
void _map(double arr[], int n, T f){
    for(int i = 0; i < n; i++){
        arr[i] = f(arr[i]);
    }
}


struct S{
    int a, b, c;
};

typedef bool (*compare) (S, S);

template <typename T, typename S>
void Sort(T arr, int n, bool (*compare) (S, S)){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(compare(arr[i],arr[j])){
                S swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        }
    }
}

bool compareA(S x, S y){
    return x.a > y.a;
}

bool compareB(S x, S y){
    return x.b > y.b;
}

bool compareC(S x, S y){
    return x.c > y.c;
}

bool compareTriple(S x, S y){
    if(x.a != y.a){
        return compareA(x,y);
    }
    if(x.b != y.b){
        return compareB(x,y);
    }
    if(x.c != y.c){
        return compareC(x,y);
    }

}

void task1(){
    int n, a[10];char b[10]; double c[10];
    cin>>n;
    input<int>(a,n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }cout<<endl;
    input(b,n);
    for(int i = 0; i < n; i++){
        cout<<b[i]<<" ";
    }cout<<endl;
    input(c,n);
    for(int i = 0; i < n; i++){
        cout<<c[i]<<" ";
    }cout<<endl;
}

void task2(){
    int n, a[10];char b[10]; double c[10];
    cin>>n;
    input(a,n);
    cout<<ordered(a,n);
    cout<<endl;
    input(b,n);
    cout<<ordered(b,n);
    cout<<endl;
    input(c,n);
    cout<<ordered(c,n);
    cout<<endl;
}

void task3(){
    int n, a[10],x;char b[10],y; double c[10],z;
    cin>>n>>x;
    input(a,n);
    cout<<member(a,n,x);
    cout<<endl;
    cin>>y;
    input(b,n);
    cout<<member(b,n,y);
    cout<<endl;
    cin>>z;
    input(c,n);
    cout<<member(c,n,z);
    cout<<endl;
}

void task4(){
    double x;
    int idx;
    cin>>x;
    func functions[] = {f1,f2,f3,f4,f5};
    double m = functions[0](x);
    for( int i = 1; i < 5; i++){
        if(functions[i](x) > m){
            m = functions[i](x);
            idx = i;
        }
    }
    cout<<idx<<endl;
}

void task5(){
    double x;
    cin>>x;
    cout<<fmax(f1,f2,x)<<endl;
}

void task6(){
    func functions[] = {f1,f2,f3,f4,f5};
    int n;
    double x;
    cin>>n>>x;
    cout<<maxarrayA(functions, n, x)<<endl;
    cout<<maxarrayB(functions, n, x)<<endl;
}

void task7(){
    int n;
    double arr[10];
    cin>>n;
    input(arr, n);
    _map(arr, n, f1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void task8(){
    S structures[10];
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>structures[i].a>>structures[i].b>>structures[i].c;
    }
    Sort(structures, n, compareTriple);
    for(int i = 0; i < n; i++){
        cout<<structures[i].a<<" "<<structures[i].b<<" "<<structures[i].c<<endl;
    }
}

int main(){
    int choice;
    for(;;){
        cin>>choice;
        switch(choice){
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
        }
    }

return 0;
}
