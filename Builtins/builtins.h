// /*
//     BUILTIN support for CSQ4 provided by the utilities built through C/C++
//     ::::::::::::::::::::::::::::CORE UTILITIES::::::::::::::::::::::::::::
//     (1) DATATYPES
//     (2) INPUT OUTPUT FUNCTIONS
//     (3) AND MANY MORE UTILITIES

//     Source : @anchor https://www.github.com/CsqLang/Csq4
// */
#if !defined(builtins_h)
#define builtins_h
// /*******************************Importing C libraries & Reference counter *********************************/
#include "exceptions.h"
#include <stdio.h>
#include <string.h>
#include "../Memory/Reference_Counter.h"

//Memory manager
template<typename T>
auto allocate(T val){
    return new T(val);
}
template<typename T>
auto deallocate(T* val){
    delete val;
}


//Basic Datatypes such as int, float, bytes etc..

//Providing int data types

class i32 {
public:
int val;
i32(int n){
val = n;
}
i32(const i32& n){
val = n.val;
}
i32(){}
auto op_add(i32 v, i32 v2){
    return i32(v.val + v2.val);
}

ref<i32> op_sub(ref<i32> v, ref<i32> v2){
    ref<i32> __val = new i32(v->val - v2->val);
    return __val;
}

auto op_div(ref<i32> v, ref<i32> v2){
    ref<i32> __val = new i32(v->val / v2->val);
    return __val;
}

ref<i32> op_mul(ref<i32> v, ref<i32> v2) {
    return ref<i32>(new i32(v->val * v2->val));
}

bool op_equal( ref<i32> v1, ref<i32> v2){
    bool state = false;
    if(v1->val == v2->val)
        state = true;
    return state;
}
i32 operator+(i32 v){

    return i32(this->val+v.val);
}
bool op_notEqual( ref<i32> v1, ref<i32> v2){
    bool state = false;
    if(v1->val != v2->val)
        state = true;
    return state;
}

bool op_lesser( ref<i32> v1, ref<i32> v2){
    bool state = false;
    if(v1->val < v2->val)
        state = true;
    return state;
}

bool op_greater( ref<i32> v1, ref<i32> v2){
    bool state = false;
    if(v1->val > v2->val)
        state = true;
    return state;
}

bool op_greaterEqual( ref<i32> v1, ref<i32> v2){
    bool state = false;
    if(v1->val >= v2->val)
        state = true;
    return state;
}

bool op_lesserEqual( ref<i32> v1, ref<i32> v2){
    bool state = false;
    if(v1->val <= v2->val)
        state = true;
    return state;
}
};



class i64{
    public:
        long int val;
        i64(long int n){
            val = n;
        }
        i64(const i64& n){
            val = n.val;
        }
        i64(){}
        auto op_add(ref<i64> v, ref<i64> v2){
            ref<i64> __val = new i64(v->val + v2->val);
            return __val;
        }
        auto op_sub(ref<i64> v, ref<i64> v2){
            ref<i64> __val = new i64(v->val - v2->val);
            return __val;
        }
        auto op_div(ref<i64> v, ref<i64> v2){
            ref<i64> __val = new i64(v->val / v2->val);
            return __val;
        }
        auto op_mul(ref<i64> v, ref<i64> v2){
            ref<i64> __val = new i64(v->val * v2->val);
            return __val;
        }
        auto op_equal( ref<i64> v1, ref<i64> v2){
            bool state = false;
            if(v1->val == v2->val)
                state = true;
            return state;
        }
        auto op_notEqual( ref<i64> v1, ref<i64> v2){
            bool state = false;
            if(v1->val != v2->val)
                state = true;
            return state;
        }
        auto op_lesser( ref<i64> v1, ref<i64> v2){
            bool state = false;
            if(v1->val < v2->val)
                state = true;
            return state;
        }
        auto op_greater( ref<i64> v1, ref<i64> v2){
            bool state = false;
            if(v1->val > v2->val)
                state = true;
            return state;
        }
        auto op_greaterEqual( ref<i64> v1, ref<i64> v2){
            bool state = false;
            if(v1->val >= v2->val)
                state = true;
            return state;
        }
        auto op_lesserEqual( ref<i64> v1, ref<i64> v2){
            bool state = false;
            if(v1->val <= v2->val)
                state = true;
            return state;
        }
};

class i128{
    public:
        long long int val;
        i128(long long int n){
            val = n;
        }
        i128(const i128& n){
            val = n.val;
        }
        i128(){}
        auto op_add(ref<i128> v, ref<i128> v2){
            ref<i128> __val = new i128(v->val + v2->val);
            return __val;
        }
        auto op_sub(ref<i128> v, ref<i128> v2){
            ref<i128> __val = new i128(v->val - v2->val);
            return __val;
        }
        auto op_div(ref<i128> v, ref<i128> v2){
            ref<i128> __val = new i128(v->val / v2->val);
            return __val;
        }
        auto op_mul(ref<i128> v, ref<i128> v2){
            ref<i128> __val = new i128(v->val * v2->val);
            return __val;
        }
        auto op_equal( ref<i128> v1, ref<i128> v2){
            bool state = false;
            if(v1->val == v2->val)
                state = true;
            return state;
        }
        auto op_notEqual( ref<i128> v1, ref<i128> v2){
            bool state = false;
            if(v1->val != v2->val)
                state = true;
            return state;
        }
        auto op_lesser( ref<i128> v1, ref<i128> v2){
            bool state = false;
            if(v1->val < v2->val)
                state = true;
            return state;
        }
        auto op_greater( ref<i128> v1, ref<i128> v2){
            bool state = false;
            if(v1->val > v2->val)
                state = true;
            return state;
        }
        auto op_greaterEqual( ref<i128> v1, ref<i128> v2){
            bool state = false;
            if(v1->val >= v2->val)
                state = true;
            return state;
        }
        auto op_lesserEqual( ref<i128> v1, ref<i128> v2){
            bool state = false;
            if(v1->val <= v2->val)
                state = true;
            return state;
        }
};
//FLoat types

class f32{
    public:
        double val;
        f32(double n){
            val = n;
        }
        f32(const f32& n){
            val = n.val;
        }
        f32(){}
       
        auto op_add(ref<f32> v1, ref<f32> v2){
            return ref<f32>(new f32((v1->val)+(v2->val)));
        }
        auto op_sub( ref<f32> v1, ref<f32> v2){
            return ref<f32>(new f32((v1->val)-(v2->val)));
        }
        auto op_mul( ref<f32> v1, ref<f32> v2){
            return ref<f32>(new f32((v1->val)*(v2->val)));
        }
        auto op_div( ref<f32> v1, ref<f32> v2){
            return ref<f32>(new f32((v1->val)/(v2->val)));
        }
        auto op_equal( ref<f32> v1, ref<f32> v2){
            bool state = false;
            if(v1->val == v2->val)
                state = true;
            return state;
        }
        auto op_notEqual( ref<f32> v1, ref<f32> v2){
            bool state = false;
            if(v1->val != v2->val)
                state = true;
            return state;
        }
        auto op_lesser( ref<f32> v1, ref<f32> v2){
            bool state = false;
            if(v1->val < v2->val)
                state = true;
            return state;
        }
        auto op_greater( ref<f32> v1, ref<f32> v2){
            bool state = false;
            if(v1->val > v2->val)
                state = true;
            return state;
        }
        auto op_greaterEqual( ref<f32> v1, ref<f32> v2){
            bool state = false;
            if(v1->val >= v2->val)
                state = true;
            return state;
        }
        auto op_lesserEqual( ref<f32> v1, ref<f32> v2){
            bool state = false;
            if(v1->val <= v2->val)
                state = true;
            return state;
        }
};

class f64{
    public:
        double val;
        f64(double n){
            val = n;
        }
        f64(const f64& n){
            val = n.val;
        }
        f64(){}
       
        auto op_add( ref<f64> v1, ref<f64> v2){
            return ref<f64>(new f64((v1->val)+(v2->val)));
        }
        auto op_sub( ref<f64> v1, ref<f64> v2){
            return ref<f64>(new f64((v1->val)-(v2->val)));
        }
        auto op_mul( ref<f64> v1, ref<f64> v2){
            return ref<f64>(new f64((v1->val)*(v2->val)));
        }
        auto op_div( ref<f64> v1, ref<f64> v2){
            return ref<f64>(new f64((v1->val)/(v2->val)));
        }
        auto op_equal( ref<f64> v1, ref<f64> v2){
            bool state = false;
            if(v1->val == v2->val)
                state = true;
            return state;
        }
        auto op_notEqual( ref<f64> v1, ref<f64> v2){
            bool state = false;
            if(v1->val != v2->val)
                state = true;
            return state;
        }
        auto op_lesser( ref<f64> v1, ref<f64> v2){
            bool state = false;
            if(v1->val < v2->val)
                state = true;
            return state;
        }
        auto op_greater( ref<f64> v1, ref<f64> v2){
            bool state = false;
            if(v1->val > v2->val)
                state = true;
            return state;
        }
        auto op_greaterEqual( ref<f64> v1, ref<f64> v2){
            bool state = false;
            if(v1->val >= v2->val)
                state = true;
            return state;
        }
        auto op_lesserEqual( ref<f32> v1, ref<f32> v2){
            bool state = false;
            if(v1->val <= v2->val)
                state = true;
            return state;
        }
};
//Defination for [] operator
template<typename T>
auto ref<T>::operator[](int index){
    return ref<T>(new T(this->op_brac(this->get(), new i32(index))));
}

//String class
class str{
    public:
        char* __str__;
        str(){}
        str(const char* __str){
            this->__str__ = new char[strlen(__str) + 1];
            // this->__str = __str;
            for(int i = 0;i<strlen(__str);i++){
                this->__str__[i] = __str[i];
            }
        }
        str(ref<str> str_){
            this->__str__ = new char[strlen(str_->__str__) + 1];
            __str__ = str_->__str__;
        }

        auto operator+(const str &rhs)
        {
            int length = strlen(this->__str__) + strlen(rhs.__str__);

            char *buff = new char[length + 1];

            // Copy the Strings to buff[]
            strcpy(buff, this->__str__);
            strcat(buff, rhs.__str__);
            buff[length] = '\0';

            // String temp
            str temp{buff};

            // delete the buff[]
            delete[] buff;

            // Return the concatenated String
            return temp;
        }
        auto operator+=(const str &rhs)
        {
            int length = strlen(this->__str__) + strlen(rhs.__str__);

            char *buff = new char[length + 1];

            // Copy the Strings to buff[]
            strcpy(buff, this->__str__);
            strcat(buff, rhs.__str__);
            buff[length] = '\0';

            // String temp
            // str temp{ buff };
            delete __str__;
            __str__ = new char[length + 1];
            strcpy(__str__, buff);
        }
        
        //Touppercase
        auto upper(){
            char* st = new char[strlen(__str__)+1];
            st = __str__;
            for(int i=0;i<strlen(__str__);i++){
                if(int(st[i]) >= 97 && int(st[i]) <=122){
                    st[i] = char(int(__str__[i])-32);
                }
                else{}
            }
            return ref<str>(new str(st));
        }

        //Tolowercase
        auto lower(){
            char* st = new char[strlen(__str__)+1];
            st = __str__;
            for(int i=0;i<strlen(__str__);i++){
                if(int(st[i]) >= 65 && int(st[i]) <=90){
                    st[i] = char(int(__str__[i])+32);
                }
                else{}
            }
            return ref<str>(new str(st));
        }
        //Length of the string
        auto len(){
            return ref<i32>(new i32(strlen(__str__)));
        }
        // toint32
        auto toi32(){
            int i = atoi(__str__);
            return ref<i32>(new i32(i));
        }
        //tof32
        auto tof64(){
            return ref<f64>(new f64(atof(__str__)));
        }

        //Operators
        auto op_add(ref<str> self, ref<str> arg){
            char* s = strcat(self->__str__,arg->__str__);
            return ref<str>(new str(s));
        }
        
};
/*-------------------------------------------------------------------------------------------------*/
#include <initializer_list>
/*
This is the class which stores elements in the allocated memory.
*/
template<typename T>
class array{
    private:
        int current;
    public:
        T* arr;
        
        i32 len=(0);
        array(){}
        array(std::initializer_list<T> list_){
            arr = new T[list_.size()];
            int i = 0;
            if(list_.size() < list_.size()){
                MemoryOverflowException();
            }
            len = i32(list_.size());
            for(auto e : list_){
                arr[i] = e;
                i++;
            }
            current = i;
        }
        auto op_brac(ref<array<T>> inst, ref<i32> index){
            return (inst->arr[index->val]);
        }
        auto read(ref<i32> ind){
            if((ind->val)+1 > this->current){
                IndexError();
            }
            return ref<T>(arr[ind->val]);
        }
        auto sum(){
            ref<T> res = T(0);
            for(int i = 0;i<this->current;i++){
                res = res+(ref<T>(T(arr[i])));
            }
            return ref<T>(res);
        }
        auto mean(){
            double sm = double(sum()->val);
            int len = this->len.val;
            f64 mean_ = sm/len;
            return ref<f64>(f64(mean_));
        }
        auto min(){
            ref<T> elem = T(arr[0]);
            for(int i = 0;i<this->current;i++){
                if(arr[i].val < elem->val){
                    elem = arr[i];
                }
            }
            return ref<T>(elem);
        }
        auto max(){
            ref<T> elem = T(0);
            for(int i = 0;i<this->current;i++){
                if(arr[i].val > elem->val){
                    elem = arr[i];
                }
            }
            return ref<T>(elem);
        }
        auto pop(){current--;}
        T* begin() { return &this->arr[0];}
        const T* begin() const { return &this->arr[0];}
        T* end() { return &this->arr[this->current]; }
        const T* end() const { return &this->arr[this->current];}
};


template<typename T>
class DynamicSequence{
    public:
        T* arr;
        // capacity is the total storage
        int capacity;
        // current is the number of elements
        int current;
        (DynamicSequence)(){
            arr = new T[1];
            capacity = 1;
            current = 0;
        }
        auto update(ref<i32> index, ref<T> value){
            arr[index->val] = *value;
        }
        auto push(ref<T> data){
            // if the number of elements is equal to the
            // capacity, that means we don't have space to
            // accommodate more elements. We need to double the
            // capacity
            if (current == capacity) {
                T* temp = new T[2 * capacity];
    
                // copying old array elements to new array
                for (int i = 0; i < capacity; i++){
                    temp[i] = arr[i];
                }
    
                // deleting previous array
                delete[] arr;
                capacity *= 2;
                arr = temp;
            }
            // Inserting data
            arr[current] = *data;
            current++;
        }
        auto read(ref<i32> index){
            return ref<T>(arr[index->val]);
        }
        auto erase(ref<T> e){
            int i;
            for (i=0; i<this->current; i++)
                if (this->arr[i] == *e)
                    break;
            // If element found in array
            if (i < this->current)
            {
                // reduce size of array and move all
                // elements on space ahead
                this->current = this->current - 1;
                for (int j=i; j<this->current; j++)
                    arr[j] = arr[j+1];
            }
        }
        auto pop(){current--;}
        T* begin() { return &this->arr[0];}
        const T* begin() const { return &this->arr[0];}
        T* end() { return &this->arr[this->current]; }
        const T* end() const { return &this->arr[this->current];}
};

template<typename T>
class list{
    public:
        DynamicSequence<T> seq;
        list(){}
        list(std::initializer_list<T> ls){
            for(auto i : ls){
                seq.push(i);
            }
        }
        list(ref<list<T>> newls){
            this->seq = (*newls).seq;
        }
        void add(ref<T> elem){
            seq.push(elem);
        }
        auto read(ref<i32> index){
            return seq.read(index);
        }
        void update(ref<i32> index, ref<T> val){
            seq.update(index,val);
        }
        ref<i32> len(){
            return new i32(this->seq.current);
        }
        auto pop(){seq.pop();}
        auto iter(){
            T* ref_[4] = {};
        }
        T* begin() { return seq.begin();}
        const T* begin() const { return seq.begin();}
        T* end() { return seq.end(); }
        const T* end() const { return seq.end();}
};

//Range function for iter feature in for loop
ref<list<i32>> range(ref<i32> end_){
    list<i32> ls;
    for(int i=0;i<end_->val;i++){
        ls.add(i32(i));
    }
    return new list<i32>(ls);
}

ref<str> tostr(ref<str> s){
    return ref<str>(new str(s->__str__));
}

auto tostr(ref<f32> f32_){
    str s("");
    sprintf(s.__str__,"%f",f32_->val);
    return ref<str>(new str(s));
}

auto tostr(ref<f64> f64_){
    str s("");
    sprintf(s.__str__,"%lf",f64_->val);
    return ref<str>(new str(s));
}
auto tostr(ref<i32> i32_){
    str s("");
    sprintf(s.__str__,"%d",i32_->val);
    return ref<str>(new str(s));
}
auto to_str(i32 num)
{
    char *num_ = new char[2500];
    sprintf(num_, "%d", num.val);
    return str(num_);
}
auto tostr(ref<array<i32>> arr){
    str s("{ ");
    for(auto i : *arr){

        s += str(to_str((i)));
        s += ", ";
    }
    s += "}";
    return ref<str>(s);
}
auto tostr(ref<array<str>> arr){
    str s("{ ");
    for(auto i : *arr){

        s += str(i);
        s += ", ";
    }
    s += "}";
    return ref<str>(s);
}
template<typename T>
void print(T arg1){
    printf("%s\n",tostr((*arg1))->__str__);
}
template<typename T, typename... Args>
void print(T arg1,Args... more){
    printf("%s\n",tostr((*arg1))->__str__);
    print(more...);
}


/********************************MATH FIELD***********************/


#endif
