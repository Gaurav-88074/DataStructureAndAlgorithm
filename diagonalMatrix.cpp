#include<iostream>
using namespace std;

class Matrix{
    private:
        int* array;
        int size;
    public:
        Matrix(int size){
            this->size = size;
            this->array= new int[size];
            this->initialize();
        }
        void initialize(){
            for (int i = 0; i < this->size; i++){
                this->array[i]=0;
            }
            
        }
        void set(int data,int i,int j){
            if(i==j){
                this->array[i-1] = data;
            }
        }
        int get(int i,int j){
            if (i==j){
                return this->array[i-1];
            }
            return 0;
        }
        void display(){
            for (int i = 0; i < this->size; i++){
                for (int j = 0; j < this->size; j++){
                    if(i==j){
                        cout<<this->array[j]<<" ";
                        continue;
                    }
                    cout<<0<<" ";
                }
                cout<<endl;
            }
            
        }
};
int main(int argc, char const *argv[]){
    Matrix* matrix = new Matrix(4);

    matrix->set(6,1,1);
    matrix->set(8,2,2);
    matrix->set(9,3,3);
    matrix->set(5,4,4);

    matrix->display();

    // cout<<matrix->get(1,1)<<endl;
    // cout<<matrix->get(2,2)<<endl;

    return 0;
}
