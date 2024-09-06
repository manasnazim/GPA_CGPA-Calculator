#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
void signup() {
    string name, username, email, password;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your password: ";
    getline(cin, password);
    
    ofstream outFile("users.txt", ios::app);
    if (outFile.is_open()) {
        outFile << name << "\t" << username << "\t" << email << "\t" << password << endl;
        outFile.close();
        cout << "User created successfully!" << endl;
    }
    else {
        cout << "Error opening file" << endl;
    }
}

bool login() {
    string username, password;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your password: ";
    getline(cin, password);
    
    ifstream inFile("users.txt");
    string line;
    while (getline(inFile, line)) {
        string name, username_from_file, email, password_from_file;
        istringstream iss(line);
        iss >> name >> username_from_file >> email >> password_from_file;
        if (username == username_from_file && password == password_from_file) {
            cout << "Login successful! Welcome back " << name << endl;
            return true;
        }
    }
    cout << "Invalid username or password" << endl;
    return false;
}

int display_menu(int &menu_choice)
{
    cout << "   ---------------------------  "<<endl;
    cout << "  |     1. GPA Calculator     |" << endl;
    cout << "  |     2. CGPA Calculator    |" << endl;
    cout << "  |     3. Grading Details    | " << endl;
    cout << "  |     4. Exit               |" << endl;
    cout << "   ---------------------------    "<<endl;
    cout<<" Enter Your Choice: ";
    cin>>menu_choice;
    return menu_choice;
}
float gpa_calculator()
{
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << "|             GPA Calculator            |" << endl;
    cout << "-----------------------------------------" << endl;
    float gpa=0, credit_and_gradepoints=0, total_grade_points=0;
    int sum=0, total_credit_hours=0;
    int size;
    cout<<" Enter the number of subjects: ";
    cin>>size;
    cout << "-----------------------------------------" << endl;
    int marks[size];
    float grade_points[size];
    int credit_hours[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter marks in "<<i+1<<" subject: ";
        cin>>marks[i];
        if (marks[i]<=100)
        {
        cout<<"Enter the credit Hours of the "<<i+1<<" subject: ";
        cin>>credit_hours[i]; 
        cout << "-----------------------------------------" << endl;
        total_credit_hours+=credit_hours[i];
        }
        else
        {
            cout<<"Enter Invalid Marks";
        }
        
    }
    
    
    for (int i = 0; i < size; i++)
    {
        if (marks[i]>=85 )
        {
            grade_points[i]=4;
        }
        else if (marks[i]>=80)
        {
            grade_points[i]=3.75;
        }
        else if (marks[i]>=75)
        {
            grade_points[i]=3.50;
        }
        else if (marks[i]>=70)
        {
            grade_points[i]=3.00;
        }
        else if (marks[i]>=65)
        {
            grade_points[i]=2.50;
        }
        else if (marks[i]>=60)
        {
            grade_points[i]=2.00;
        }
        else if (marks[i]>=55)
        {
            grade_points[i]=1.50;
        }
        else if (marks[i]>=50)
        {
            grade_points[i]=1.00;
        }
        else
        {
            grade_points[i]=0;
        }
        credit_and_gradepoints=credit_hours[i]*grade_points[i];
        total_grade_points+=credit_and_gradepoints;

    }
    gpa=total_grade_points/total_credit_hours;
    return gpa;
}
float cgpa_calculator()
{
    system("cls");
    cout << "-----------------------------------------" << endl;
    cout << "|            CGPA Calculator            |" << endl;
    cout << "-----------------------------------------" << endl;
    int semester;
    cout<<"Enter the number of semesters: ";
    cin>>semester;
    float sgpa[semester], credit_gpa=0, total_credit_gpa=0, cgpa=0;
    int credit_hour[semester], total_credit_hours=0;
    for (int i = 0; i < semester; i++)
    {
        cout<<"Enter your GPA in "<<i+1<<" semester: ";
        cin>>sgpa[i];
        if(sgpa[i]<=4)
        {

        
        cout<<"Enter your credit hours in "<<i+1<<" semester: ";
        cin>>credit_hour[i];
        cout << "-----------------------------------------" << endl;
        total_credit_hours+=credit_hour[i];
        credit_gpa=sgpa[i]*credit_hour[i];
        total_credit_gpa+=credit_gpa;
        cgpa=total_credit_gpa/total_credit_hours;
        }
        else
        {
            cout<<"Invalid GPA range.";
        }
        
    }

    return cgpa;
}
void display_result(int choose, float result)
{
    string calculator_type;
    if (choose==0)
    {
        calculator_type="GPA";
    }
    else
    {
        calculator_type="CGPA";
    }
    
    cout<<"    -------------------------------    "<<endl;
    cout<< "         Your "<<calculator_type<<" is: "<<result<<endl;
    cout<<"    -------------------------------    "<<endl;
}
void grading_details()
{
     cout<<" Here is a table that tells you about your Grades according to your marks "<<endl;
            cout<<"     _____________________________________________"<<endl;
            cout<<"     |           |                  |            |"<<endl;
            cout<<"     |   Grade   |  Marks Obtained  |   Points   |"<<endl;
            cout<<"     |___________|__________________|____________|"<<endl;
            cout<<"     |     A     |       85-100     |     4.00   |"<<endl;
            cout<<"     |___________|__________________|____________|"<<endl;
            cout<<"     |     A-    |       80-84      |     3.75   |"<<endl;
            cout<<"     |___________|__________________|____________|"<<endl;
            cout<<"     |     B+    |       75-79      |     3.50   |"<<endl;
            cout<<"     |___________|__________________|____________|"<<endl;
            cout<<"     |     B     |       70-74      |     3.00   |"<<endl;
            cout<<"     |___________|__________________|____________|"<<endl;
            cout<<"     |     C+    |       65-69      |     2.50   |"<<endl;
            cout<<"     |___________|__________________|____________|"<<endl;
            cout<<"     |     C     |       60-64      |     2.00   |"<<endl;
            cout<<"     |___________|__________________|____________|"<<endl;
            cout<<"     |     D+    |       55-59      |     1.50   |"<<endl;
            cout<<"     |___________|__________________|____________|"<<endl;
            cout<<"     |     D     |       50-54      |     1.00   |"<<endl;
            cout<<"     |___________|__________________|____________|"<<endl;
            cout<<"     |     F     |     Below  50    |     0.00   |"<<endl;
            cout<<"     |___________|__________________|____________|"<<endl;
}
int main()
{   
    int login_choice;
    bool allow_user;
    do
    {
    cout << "Enter your choice:" << endl;
    cout << "1. Signup" << endl;
    cout << "2. Login" << endl;
    cin >> login_choice;
    cin.ignore(); 
    
    switch (login_choice) {
        case 1:
            signup();
            allow_user=true;
            break;
        case 2:
            allow_user=login();
            break;
        default:
            cout << "Invalid choice" << endl;
            allow_user=false;
            break;
    }
    } while (!allow_user);
    char choice;
    do
    {
        
        float result=0;
        int menu_choice=0, choose_calculator;
        display_menu(menu_choice);
        if (menu_choice==1)
        {
            choose_calculator=0;
            result=gpa_calculator();
            display_result(choose_calculator, result);
        }
        else if (menu_choice==2)
        {
            choose_calculator=1;
            result=cgpa_calculator();
            display_result(choose_calculator, result);
        }
        else if (menu_choice==3)
        {
            grading_details();
        }
        else
        {
            break;
        }
        
        cout<<"Press Y or main menu and N for exit: ";
        cin>>choice;
        system("cls");
        
    } while (choice== 'Y' ||choice== 'y' );
    
    

return 0;
}





