// Coded by: Diksha Singhal
// Language used: C++
// dikshasinghal777@gmail.com

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> input_dict; //input dictionary in the form of map/hashing

map<int,string> days={  //maps that stores the days with their numbers
       {1 , "Mon"},
       {2 , "Tue"},
       {3 , "Wed"},
       {4 , "Thu"},
       {5 , "Fri"},
       {6 , "Sat"},
       {7 , "Sun"},
};

string findDayWithGivenDate(int date,int month,int year){ //function that finds the day of the week on input date
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    year -= month < 3;  
    int temp = ( year + year / 4 - year / 100 +  year / 400 + t[month - 1] + date)%7;
    if(temp==0) return days[7];
    return days[temp];
}

map<string,int> solution(){ // required function that returns the output dictionary

        map<string, int> output_dict; //output dictionary

        for(auto it:input_dict){
              string fullDate = it.first;
              int value = it.second;
              int year = (fullDate[0]-'0')*1000 + (fullDate[1]-'0')*100 + (fullDate[2]-'0')*10 + (fullDate[3]-'0');
              int month = (fullDate[5]-'0')*10 + (fullDate[6]-'0');
              int date = (fullDate[8]-'0')*10 + (fullDate[9]-'0');
              string day_of_week = findDayWithGivenDate( date, month, year);
              output_dict[day_of_week] += value;
        }

        for(int i=2;i<=6;i++){

            if(output_dict.find(days[i])==output_dict.end()){
                  // handling different cases of absence of days 
                 if(output_dict.find(days[i+1])!=output_dict.end()){

                      int val1 = output_dict[days[i-1]];
                      int val2 = output_dict[days[i+1]];
                      int difference = (val2 - val1)/(2);
                      output_dict[days[i]] = val1 + difference;
                 }

                 if(output_dict.find(days[i+1])==output_dict.end()&&output_dict.find(days[i+2])!=output_dict.end()){

                      int val1 = output_dict[days[i-1]];
                      int val2 = output_dict[days[i+2]];
                      int difference = (val2 - val1)/(3);
                      output_dict[days[i]] = val1 + difference;
                      output_dict[days[i+1]] = val1 + 2*difference;
                 }

                 else if(output_dict.find(days[i+1])==output_dict.end()&&output_dict.find(days[i+2])==output_dict.end()&&output_dict.find(days[i+3])!=output_dict.end()){

                      int val1 = output_dict[days[i-1]];
                      int val2 = output_dict[days[i+3]];
                      int difference = (val2 - val1)/(4);
                      output_dict[days[i]] = val1 + difference;
                      output_dict[days[i+1]] = val1 + 2*difference;
                      output_dict[days[i+2]] = val1 + 3*difference;

                 }

                 else if(output_dict.find(days[i+1])==output_dict.end()&&output_dict.find(days[i+2])==output_dict.end()&&output_dict.find(days[i+3])==output_dict.end()&&output_dict.find(days[i+4])!=output_dict.end()){

                      int val1 = output_dict[days[i-1]];
                      int val2 = output_dict[days[i+4]];
                      int difference = (val2 - val1)/(5);
                      output_dict[days[i]] = val1 + difference;
                      output_dict[days[i+1]] = val1 + 2*difference;
                      output_dict[days[i+2]] = val1 + 3*difference;
                      output_dict[days[i+3]] = val1 + 4*difference;

                 }

                 else if(output_dict.find(days[i+1])==output_dict.end()&&output_dict.find(days[i+2])==output_dict.end()&&output_dict.find(days[i+3])==output_dict.end()&&output_dict.find(days[i+4])==output_dict.end()&&output_dict.find(days[i+5])!=output_dict.end()){
                      int val1 = output_dict[days[i-1]];
                      int val2 = output_dict[days[i+5]];
                      int difference = (val2 - val1)/(6);
                      output_dict[days[i]] = val1 + difference;
                      output_dict[days[i+1]] = val1 + 2*difference;
                      output_dict[days[i+2]] = val1 + 3*difference;
                      output_dict[days[i+3]] = val1 + 4*difference;
                      output_dict[days[i+4]] = val1 + 5*difference;
                 }
            }
        }
        return output_dict;
}
int main() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
      int n; //number of items in the input dictionary
      cin>>n;
      string date;
      int value,i;
      for(i = 0; i < n; i++){
          cin >> date >> value;   // taking dates and their corresponding values as input
          input_dict[date] = value;
      }
      map<string,int> answer= solution(); // calling the required function

      for(i = 1; i <= 7; i++){ //printing the ouput 
      	   cout<<days[i]<<" "<<answer[days[i]]<<endl;
      }
   return 0;
} 

// *input format
// 6
// 2020-01-01 6
// 2020-01-04 12
// 2020-01-05 14
// 2020-01-06 2
// 2020-01-07 4

// *output format

// Mon 2
// Tue 4
// Wed 6
// Thu 8
// Fri 10
// Sat 12
// Sun 14

