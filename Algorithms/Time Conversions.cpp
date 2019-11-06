#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    
    int temp = stoi(s);
    string str_temp;

    if(s == "12:00:00AM"){
        return "00:00:00";
    }

    if(s == "12:00:00PM"){
        return "12:00:00";
    }

    if(temp < 12 && s.substr(s.length()-2) == "PM"){
        temp += 12;
    }

    if(temp < 12 && s.substr(s.length()-2) == "AM"){
        str_temp = std::to_string(temp);
        str_temp.insert(0, "0");
        s.replace(0, 2, str_temp);
        s.erase(8);
        return s;
    }
    
    if(s.substr(s.length() -2) == "PM" || s.substr(s.length() -2) == "AM"){

        if(temp == 12 && s.substr(s.length()-2) == "AM"){
            str_temp = "00";
        }

        else{
            str_temp = std::to_string(temp);
        }
        
        s.replace(0, 2, str_temp);
        s.erase(8);
    }

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

