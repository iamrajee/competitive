#include <iostream> 
#include <queue> 
using namespace std; 
  
int main() 
{ 
    // Empty Queue 
    queue<int> myqueue; 
    myqueue.push(0); 
    myqueue.push(1); 
    myqueue.push(2); 
  
    // Printing content of queue 
    while (!myqueue.empty()) { 
        cout << ' ' << myqueue.front(); 
        myqueue.pop(); 
    } 
} 