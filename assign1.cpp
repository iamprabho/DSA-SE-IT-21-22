#include<iostream>
#include<cstring>



using namespace std;
typedef struct student
{
    int roll_no;
    char name[20];
    float marks;   
}stud;
void create(stud s[20],int n );
void display(stud s[20],int n);
void bubblesort(stud s[20],int n);
void quicksort(stud s[20],int l,int u);
int partition(stud s[20],int l,int u);
void insertionsort(stud s[20],int n);
void search(stud s[20],int n,int key);
int bsearch(stud s[20],char x[20],int low,int high);

int main(){
    stud s[20];
    int ch,n,key,result;
    char x[20];
 do{
 
         cout<<"\n 1.create student database";
         cout<<"\n 2.display student database";
         cout<<"\n 3.bubblesort";
         cout<<"\n 4.quicksort";
         cout<<"\n 5.insertionsort";
         cout<<"\n 6.linearsearch";
         cout<<"\n 7.binearysearch";
         cout<<"\n 0.exit";
         cout<<"\n enter the choice";
         cin>>ch;
    
      switch (ch){

        case 1:
             cout<<"\n enter the no of records";
             cin>>n;
             create(s,n);
        
        break;
        case 2:
            display(s,n);
        break;
        case 3:
           bubblesort(s,n);
           cout<<"\n bubblesort completed";
        break;
        case 4:
           quicksort(s,0,n-1);
           cout<<"\n quicksort completed";
        break;
        case 5:
             insertionsort(s,n);
             cout<<"\n insertion  sort completed";
        break;
        case 6:
           cout<<"enter the marks u need to search \n";
           cin>>key;
           search(s,n,key);
        break;
        case 7:
            
            cout<<"enter name to search";

            cin>>x;
            insertionsort(s,n);
            result=bsearch(s,x,0,n-1);
            if(result==-1){
                cout<<"name of student not present";
            }
            else{
                cout<<"\n the student is present:"<<s[result].name;
            }
        break;
        case 0:
            return 0;
        break;


    
       default:
           cout<<"\n invalid choice please enter correct choice";


    
    } 




 } while (ch!=0);
 
}
void create(stud s[20],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<"\n enter the rollno:  ";
        cin>>s[i].roll_no;
        for(int j=0;j<i;j++){
            if(s[j].roll_no==s[i].roll_no){
                cout<<"enter unique no \n ";
                cin>>s[j].roll_no;
                break;
                i--;

              
            }
        }


       cout<<"\n enter name: ";
       cin>>s[i].name;
       cout<<"\n enter marks: ";
       cin>>s[i].marks; 
    }
    
}

void display(stud s[20],int n){
    cout<<"\n";
    cout<<"\tRoll no.";
    cout<<"\tname";
    cout<<"\tmarks";
    for (int i = 0; i < n; i++)
    {
        cout<<"\n";
        cout<<"\t";
        cout<<s[i].roll_no;
        cout<<"\t";
        cout<<s[i].name;
        cout<<"\t";
        cout<<s[i].marks;
        cout<<"\t";

    }
    
}

void bubblesort(stud s[20],int n){
    stud temp;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n-i-1; j++)
      {
          if(s[j].roll_no>s[j+1].roll_no){
              temp=s[j];
              s[j]=s[j+1];
              s[j+1]=temp;
            
          }
        
      }
      
    }
    
}
void quicksort( stud s[20],int l,int u){
    int j;
    if(j<u){
        j=partition(s,l,u);//j partition,u high ,l low 
        quicksort(s,l,j-1);
        quicksort(s,j+1,u);
    }
}
int partition(stud s[20],int l,int u){
    int i,j;
    stud temp,v;
    v=s[l];
    i=l;
    j=u+1;
    do{
        do{
            i++;
        }while(s[i].marks<v.marks && i<=u);
        if(i<j){
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;

        }
    }while(i<j);
    s[l]=s[j];
    s[j]=v;
    return(j);


}
void insertionsort(stud s[20],int n){
    int i,j;
    stud key;
    for (int i = 0; i < n; i++)
    {
        key=s[i];
        j=i-1;
        while(j>=0&&strcmp(s[j].name,key.name)>0){
            s[j+1]=s[j];
            j=j-1;
            s[j+1]=key;

        }
        
    }
}


void search(stud s[20],int n,int key){
    int i;
    cout<<"\n";
    cout<<"\t Roll no.";
    cout<<"\t";
    cout<<"name\t";
    cout<<"marks\n";

    for (int i = 0; i < n; i++)
    {
        if(key==s[i].marks){
          cout<<"\t"<<s[i].roll_no<<"\t\t"<<s[i].name<<"\t"<<s[i].marks;
        }
    }
    
}
int bsearch(stud s[20],char x[20],int low,int high){
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(strcmp(x,s[mid].name)==0){
            return mid;

        }
        else if (strcmp(x,s[mid].name)<0)
        {
            high=mid-1;

        }
        else{
            low=mid+1;

        }
    }
    return -1;

}
    