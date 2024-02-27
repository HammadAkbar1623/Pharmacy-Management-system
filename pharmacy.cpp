#include <iostream>
#include <iomanip>
using namespace std;

int maxMedicine = 10;
// Structure to store medicines details
struct pharmacy {
    int get_price;
    int total_products;
    string sellerName;
    int set_price;
    int remaining_products;
    string med_name;
    int numBox;
};

// Declaration of the sellMedicine function
void sellMedicine(pharmacy med[], int count, int index, int& amount, double& dailySales, double& dailyProfit);

// Function to enter new stock of medicines
void enterProducts(pharmacy med[], int& count) {
    cout << "Enter the number of medicines " << endl;
    cin>>count;
    
    for (int i = 0; i < count; i++) {
        cout << "Enter details for medicine " << i + 1 << endl;
        cout << "Name : ";
        cin >> med[i].med_name;
        cout << "Seller name : ";
        cin >> med[i].sellerName;
        cout << "Buying price per box : ";
        cin >> med[i].get_price;
        cout << "Selling price per box :";
        cin >> med[i].set_price;
        cout << "Boxes purchased :";
        cin >> med[i].total_products;
    }
}

// Function to search for a medicine from stock
void searchMedicine(pharmacy med[], int count, string targetMedicine, double& dailySales, double& dailyProfit) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (med[i].med_name == targetMedicine) {
            cout << "Here's the details: " << endl;
            cout <<"Medicine name:" <<med[i].med_name << endl <<"Seller name: "<< med[i].sellerName << endl <<"Price: "<< med[i].set_price<<" Rs." << endl;
        

            
            int amount; 
            // Call sellMedicine function
            sellMedicine(med, count, i, amount, dailySales, dailyProfit);
            
            found = true;
            break;
        }
        
        
        
    }
    if(!found){
            cout<<"No medicine found OR Out of stock "<<endl;
        }
    
}

// Definition of the sellMedicine function
void sellMedicine(pharmacy med[], int count, int index, int& amount, double& dailySales, double& dailyProfit) {
    cout << "How many boxes you want to sell? " << endl;
    cin >> med[index].numBox;
    if(med[index]. numBox <= med[index].total_products){
        amount = med[index].total_products - med[index].numBox;
        int bill = med[index].set_price * med[index].numBox;
        cout<<"Bill:"<<bill<<" Rs. "<<endl;
        cout<<"Remaining Stock:"<<amount<<" Boxes "<<endl;
    
        char choice;
        cout<<"Press d for 5% discount to special customers "<<endl;
        cout<<"OR Press c to continue "<<endl;
        cin>>choice;
        
        if(choice == 'd' || choice == 'D'){
            double discount = 0.05;
            int discount_Amount = discount * bill;
            cout<<"Bill after 5% discount: "<<bill - discount_Amount<<" Rs."<<endl;
            cout<<"Remaining Stock:"<<amount<<" Boxes "<<endl;
        }
        if(choice == 'c' || choice == 'C'){
        cout<<"Remaining Stock:"<<amount<<" Boxes "<<endl;
        }
        
        // Update daily sale
        dailySales = dailySales + bill;
        // Update daily profit
        double cogs = med[index].get_price * med[index].numBox;
        dailyProfit = dailyProfit + cogs;
    }
          
    if(med[index]. numBox > med[index].total_products){
        cout<<"Not enough stock "<<endl;
    }
}

int main() {
    pharmacy med[maxMedicine];
    int num_medicine = 0;
    int choice;
    // Variable to store daily sales
    double dailySales = 0;
    // Variable to store daily profit
    double dailyProfit = 0;
    cout<<"Pharmacy Management System" << endl;
    cout<<"---------------------------------------------"<<endl;


    do {
        
        cout <<"Press 1 for Entering new records"<< endl;
        cout <<"Press 2 to search for a medicine"<< endl;
        cout <<"Press 3 to check Today's Sale"<<endl;
        cout <<"Press 4 to Exit"<<endl;
        cout <<"Enter your choice:";
        cin >> choice;

        switch (choice) {
            case 1:
                enterProducts(med, num_medicine);
                break;
            case 2:
                {
                    string targetMedicine;
                    cout<< "Enter the name of the medicine to search: ";
                    cin >> targetMedicine;
                    searchMedicine(med, num_medicine, targetMedicine, dailySales, dailyProfit);
                    break;
                }
            case 3:
                cout << "Today's total sale:"<<dailySales << endl;
                cout<<"Today's Total profit:"<<(dailySales - dailyProfit)<<" Rs"<<endl;
                break;
            case 4:
                cout<< "Exiting....Good bye" << endl;
                break;
            default :
            cout<<"Invalid choise.... Try again" <<endl;
                
        }
    } 
    while (choice != 4);
    

    return 0;
}