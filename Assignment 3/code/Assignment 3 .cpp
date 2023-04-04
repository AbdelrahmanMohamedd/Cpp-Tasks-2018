/// Abdelrahman Mohamed Ahmed : 20170148   G1-old
/// Omar Sami   :  20170176    G1-old
///////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int n, MAX_CYCLES;

enum State{
    Empty,
    Micro
};

struct Block{
    char value;
    State state;
};

Block ** createSurface(int n)
{
    Block ** arr = new Block*[n];
    for(int i=0;i<n;++i) arr[i] = new Block[n];
    return arr;
}

void takeInput(Block **a)
{
    cout<<"Enter the initial state:\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) {
            cin>>a[i][j].value;
            if(a[i][j].value =='M') a[i][j].state = Micro;
            else if(a[i][j].value =='-') a[i][j].state = Empty;
        }
    }
}

void print(Block **a)
{
    for(int i=0;i<n;++i){
        cout<<"[ ";
        for(int j=0;j<n;++j) {
            cout<<a[i][j].value<<" ";
        }
        cout<<"]\n";
    }
}
// valid dimension (inside surface)
bool isValid(int i, int j)
{
    return i>=0 && i < n && j>=0 && j < n;
}

int calculateNearMicro(Block **a, int i, int j)
{
    int micro = 0;
    if(isValid(i,j+1) && a[i][j+1].value == 'M') micro++;
    if(isValid(i,j-1) && a[i][j-1].value == 'M') micro++;
    if(isValid(i-1,j) && a[i-1][j].value == 'M') micro++;
    if(isValid(i+1,j) && a[i+1][j].value == 'M') micro++;
    if(isValid(i-1,j-1) && a[i-1][j-1].value == 'M') micro++;
    if(isValid(i+1,j+1) && a[i+1][j+1].value == 'M') micro++;
    if(isValid(i-1,j+1) && a[i-1][j+1].value == 'M') micro++;
    if(isValid(i+1,j-1) && a[i+1][j-1].value == 'M') micro++;
    return micro;
}
// for blocks with micro in it
bool willBeEmpty(Block **a, int i, int j)
{
    int micro = calculateNearMicro(a, i, j);
    if(micro == 0 || micro == 1) return true;
    if(micro >= 4) return true;
    return false;
}
// for empty blocks
bool willAttract(Block **a, int i, int j)
{
    int micro = calculateNearMicro(a, i, j);
    return micro == 3;
}

void updateBlock(Block **a, int i, int j)
{
    if(a[i][j].value =='M')
    {
        if(willBeEmpty(a, i ,j))
        {
            a[i][j].state = Empty;
        }
    }
    else if(a[i][j].value =='-')
    {
        if(willAttract(a, i, j))
        {
            a[i][j].state = Micro;
        }
    }
}

void applyUpdates(Block **a)
{
    for(int i = 0; i <n; ++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j].state == Empty)
            {
                a[i][j].value = '-';
            }
            else{
                a[i][j].value = 'M';
            }
        }
    }
}

void updateState(Block **a)
{
    for(int i=0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            updateBlock(a, i , j);
        }
    }
    applyUpdates(a);
}

void freeAllocatedMemory(Block **a)
{
    for(int i=0;i<n;++i) delete []a[i];
    delete []a;
}

void RunProgram(Block **a)
{
    cout<<"Initial state\n";
    print(a);
    for(int i=0; i < MAX_CYCLES; ++i)
    {
        updateState(a);
        cout<<"State at cycle number: "<<i+1<<" is\n";
        print(a);
    }
    freeAllocatedMemory(a);
}

int main() {
    cout<<"Enter the surface dimension:\n";
    cin>>n;
    cout<<"Enter the number of cycles\n";
    cin>>MAX_CYCLES;
    Block **a = createSurface(n);
    takeInput(a);
    RunProgram(a);
}
