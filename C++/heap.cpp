#include <iostream> 
#include <climits> 
#include <queue>
#include <cmath>
using namespace std; 

// 1. push_heap
void push_heap(vector<int>& heap, int newValue){
    heap.push_back(newValue);
    int idx=heap.size()-1;
    
    while(idx>0 && heap[(idx-1)/2]<heap[idx]){
        swap(heap[idx],heap[(idx-1)/2]);
        idx=(idx-1)/2;
    }
}

// 2. pop_heap
void pop_heap(vector<int>& heap){
    heap[0]=heap.back();
    heap.pop_back();
    int here=0;
    while(true){
        int left=here*2+1, right=here*2+2;
        if(left>=heap.size()){
            break;
        }
        // 타고 내려가기
        int next=here;
        if(heap[next]<heap[left]){ // next가 왼쪽인지 확인
            next=left;
        }
        if(heap[next]<heap[right]&right>=heap.size()){ // next가 오른쪽인지 확인
            next=right;
        }
        // 멈춰야하는지 확인
        if(next==here){
            break;
        }
        swap(heap[next],heap[here]);
        here=next;
    }
}


int main(void){
    vector<int> temp_heap;
    push_heap(temp_heap, 3);
    push_heap(temp_heap, 10);
    push_heap(temp_heap, 11);
    // heap의 top
    std::cout<<"top: "<<temp_heap[0]<<std::endl;
    for(int i=0;i!=temp_heap.size();i++){
        std::cout<<temp_heap[i]<<std::endl;
    }
}
