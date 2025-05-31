#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
using namespace std;

class Hostel{
    private:
    string Name;
    int Rent,Bed;
    public:
    Hostel(string name,int rent,int bed){
        Name=name;
        Rent=rent;
        Bed=bed; 
    }
    string getName(){
        return Name;
    }
    int getRent(){
        return Rent;
    }
    int getBed(){
        return Bed;
    } 
   void reserve(){
        ifstream in("E:/hostel.txt");
        ofstream out("E:/hostel temp.txt");

        string line;
        while(getline(in,line)){
            int pos=line.find("3star");
            if(pos!=string::npos){

                int bed=Bed-1;
                Bed=bed;

                stringstream ss;
                ss<<bed;
                string strBed=ss.str();

                int bedPos=line.find_last_of(':');
                line.replace(bedPos+1,string::npos,strBed);
            }
            out<<line<<endl;
        }
        out.close();
        in.close();
        remove("E:/hostel.txt");
        rename("E:/hostel temp.txt", "E:/hostel.txt");
        cout<<"\tBed reserved successfully"<<endl;
    }
};

class Student{
    private:
    string Name,RollNo,Address;
    public:
    Student():Name(""),RollNo(""),Address(""){}

    void setName(string name){
        Name=name;
    }
   void setRollNo(string rollNo){
        RollNo=rollNo;
    }
    void setAddress(string address){
        Address=address;
    }
   string getName(string name){
        return Name;
    }
    string getRollNo(string rollNo){
        return RollNo;
    }
   string getAddress(string address){
        return Address;
}
} ;

int main(){
    Hostel h("3star",5000,2);
    ofstream out("E:/hostel.txt");
    out<<"\t"<<h.getName()<<":"<<h.getRent()<<":"<<h.getBed()<<endl;
    cout<<"Hostel data saved"<<endl;
    out.close(); 


    Student s;
     
    bool exit=false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tWelcome to Hostel Accomodation System"<<endl;
        cout<<"\t*************************************"<<endl;
        cout<<"\t1.Reserve a bed."<<endl;
        cout<<"\t2.Exit."<<endl;
        cout<<"\tEnter Choice: ";
        cin>>val;

        if(val==1){
            system("cls");
            string name,rollNo,address;
            cout<<"\tEnter name of a student: ";
            cin>>name;
            s.setName(name);

            cout<<"\tEnter RollNo of a student: ";
            cin>>rollNo;
            s.setRollNo(rollNo);

            cout<<"\tEnter address of a student: ";
            cin>>address;
            s.setAddress(address);
            if(h.getBed()>0){
                h.reserve();
            }
            else if(h.getBed()==0){
                cout<<"\tSorry bed not available"<<endl;

            }


            ofstream outFile("E:/student.txt",ios::app);
            outFile<<"\t"<<s.getName(name)<<":"<<s.getRollNo(rollNo)<<":"<<s.getAddress(address)<<endl;
        }
            else if(val==2){
            system("cls");
            exit=true;
            cout<<"good luck"<<endl;
            
        }
    }
      
}


