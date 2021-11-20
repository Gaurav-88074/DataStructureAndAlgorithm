#include<iostream>
using namespace std;

class Matrix{
    private:
        int* array;
        int size;
        int mSize;
    public:
        Matrix(int size){
            this->mSize =size;
            this->size = (size*(size+1))/2;
            this->array= new int[this->size];
            this->initialize();
        }
        void initialize(){
            for (int i = 0; i < this->size; i++){
                this->array[i]=0;
            }
        }
        int getIndex(int i,int j){
            int index = ((i*(i-1))/2)+(j-1);
            return index;
        }
        void set(int data,int i,int j){
            int index = this->getIndex(i,j);
            this->array[index] = data;
        }
        int get(int i,int j){

            int index;
            if(i<j){
                int k = i;
                i=j;
                j=k;
            }
            index = this->getIndex(i,j);
            return this->array[index];            
        }
        void display(){
            cout<<"Displaying Your Matrix..."<<endl;
            for (int i = 1; i <= this->mSize; i++){
                for (int j = 1; j <= this->mSize; j++){
                        cout<<this->get(i,j)<<" ";
                }
                cout<<endl;
            } 
        }
};
int main(int argc, char const *argv[]){
    Matrix* matrix = new Matrix(4);

    matrix->set(6,1,1);
    matrix->set(2,2,1);
    matrix->set(9,1,2);
    matrix->set(8,2,2);
    matrix->set(5,4,4);

    matrix->display();
    


    return 0;
}
