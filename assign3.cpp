#include<iostream>
using namespace std;

int cqueue[5];
int front=-1,rear=-1,n=5;
void insertcq(int val){
    if ((front==0 && rear==n-1)||(front==rear+1)){
        cout<<"queue overflow\n";
        return;
    }
    if(front==-1){
        front=0;
        rear=0;

    }
    else{
        rear=rear+n;

    }
    cqueue[rear]=val;
 
}
void deletecq(){
    if (front==-1) {
        cout<<"queue underflow\n";
        return;
    }
    cout<<"element deleted from queue is"<<cqueue[front]<<endl;

    if(front==rear){
        front=-1;
        rear=-1;

    }
    else{
        if(front=n-1){
            front=0;

        }
        else{
            front=front+1;

        }

    }
    

}

void displaycq(){
    int f=front,r=rear;

    
    if(front==-1){
       cout<<"queue is empty\n";
       return;


    }
    cout<<"queue elments are\n";
    if(f<=r){
        while(f<=r){
            cout<<cqueue[f]<<" ";
            f++;

        }
    }
    else{
        while(f<=n-1){
            cout<<cqueue[f]<<" ";
            f++;


        }
        f=0;
        while(f<=r){
            cout<<cqueue[f]<<" ";
            f++;
        }
        

    }
    cout<<endl;

}
void reverse_displaycq(){
    int f=front,r=rear;

    
    if(front==-1){
       cout<<"queue is empty\n";
       return;


    }
    cout<<"queue elments are\n";
    if(f<=r){
        while(f<=r){
            cout<<cqueue[r]<<" ";
            r--;

        }
    }
    else{
        while(r>=0){
            cout<<cqueue[r]<<" ";
            r--;


        }
        r=n-1;
        while(r>=f){
            cout<<cqueue[r]<<" ";
            r--;
        }
        

    }
    cout<<endl;
}

int main(){
    int ch,n,val;
    do{
        cout<<"1. insert elements in queue\n";
        cout<<"2. delete elements in queue\n";
        cout<<"3. display elements in queue\n";
        cout<<"4. display elements in  reverse order queue\n";
        cout<<"0. exit\n";
        cout<<"enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
              for(int i=0;i<=5;i++){
                  cout<<"enter element:\n";
                  cin>>val;
                  insertcq(val);

              }
            break;
            case 2:
               deletecq();
                for(int i=0;i<=5;i++){
                  cout<<"last element in queue iis delleted:\n";
                   break;

                  
                }
            break; 
            case 3:
             displaycq();
             cout<<endl;

            break;
            case 4:
             reverse_displaycq();
              cout<<endl;
            break; 
            case 0:
              cout<<"exit";
            return 0;
            default:
             cout<<" invalid choice";
            break;



        }
        

                    

    }while(ch!=0);
    return 0;
}

 

