#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<windows.h>
#include<limits>

class Bill{
    private:
    std::string iteam ;
    int rate , quantity;

    public:
    Bill():iteam(" "),rate(0),quantity(0) {}

    void setIteam(std::string iteam){
        this->iteam=iteam;
    }

    void setRate(int rate){
        this->rate=rate;
    }

    void setQuantity(int quantity){
        this->quantity=quantity;
    }

    std::string getIteam (){
        return iteam;
    }

    int getRate(){
        return rate;
    }

    int getQuantity(){
        return quantity;
    }
};

void addIteam(Bill b){
    bool close = false ;

    while (!close){
        int choice;
        std::cout<<"\n1. ADD"<<std::endl;
        std::cout<<"\n2.Close"<<std::endl;
        std::cout<<"\nEnter choice : "<<std::endl;
        std::cin>>choice;

        switch(choice){
            case 1 :{
                system("cls");
            std::string item ;
            int rate , quantity ;

            std::cout<<"\nEnter the Iteam Name : ";
            std::getline(std::cin,item);
            b.setIteam(item);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout<<"\nEnter the Rate : ";
            std::cin>>rate;
            b.setRate(rate);
            std::cout<<"\nEnter the Quantity : ";
            std::cin>>quantity;
            b.setQuantity(quantity);
             
            std::ofstream out("bill.txt",std::ios::out);
            if(!out){
                std::cout<<"Error"<<std::endl;
            }

            else {
                out<<"\n"<<b.getIteam()<<" : "<<b.getRate() <<" : "<<b.getQuantity()<<std::endl<<std::endl;
            }
            out.close();
            std::cout<<"Iteam Added Sucessfully "<<std::endl;
            Sleep(3000);
            break;
            }
            case 2 :
                close = true;
                std::cout<<"\nBack To Main Menu ! "<<std::endl;
                Sleep(3000);
                break ; 
            defult :
            std::cout<<"Error \n Enter 1 or 2\n";
        } 
    }

}


int main(){
    Bill b;
    bool exit = false ;

    while(!exit){
        std::system("cls");
        int val ;

        std::cout<<"\nWELCOME TO SUPER MARKET BILLING SYSTEM"<<std::endl;
        std::cout<<"\n--------------------------------------\n"<<std::endl;
        std::cout<<"\n1. Add Item."<<std::endl;
        std::cout<<"\n2. Print Bill."<<std::endl;
        std::cout<<"\n3. Exit."<<std::endl;
        std::cout<<"\n\nEnter the choice : ";
        std::cin>>val;

        switch(val){
            case 1 :{
                addIteam(b);
                break;
            }
            break;
            case 2 :
            break;
            case 3 :
            break;
        }


    }
    return 0;
}
