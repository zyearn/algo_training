#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


string MONTHS[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

int getMonth(string mon){
    for(int i = 0; i <  12; ++ i){
        if(mon == MONTHS[i]) return i+1;
    }
    return 0;
}

bool judgeLeapYear(int year){
    if(((year%4 == 0) && (year%100!=0)) || (year%400 == 0)) return true;
    else return false;
}

int getLeapYearNum(int startYear, int endYear){
    int startNum = startYear/4-startYear/100+startYear/400;
    int endNum = endYear/4-endYear/100+endYear/400;
    return endNum-startNum;
}

int main(){
    int T;
    cin >> T;
    string dot; //逗号
    for( int icase = 1; icase <= T; ++ icase ){
        string monthStr;
        int startDay,startYear;
        cin >>monthStr>>startDay>>dot>>startYear;
        int startMonth = getMonth(monthStr);

        int endDay,endYear;
        cin >> monthStr >> endDay >> dot>>endYear;
        int endMonth = getMonth(monthStr);

        int result= getLeapYearNum(startYear,endYear);
        if(startYear==endYear){
            if(judgeLeapYear(startYear) && startMonth <=2 &&  (endMonth >= 3 || (endMonth == 2 && endDay == 29))) result++;
        }else{
            if(judgeLeapYear(startYear) && startMonth <= 2) result++;
            if(judgeLeapYear(endYear) && (endMonth == 1 || (endMonth == 2 && endDay != 29))) result--;
        }
        cout<<"Case #"<<icase<<": "<<result<<endl;
    }

}
