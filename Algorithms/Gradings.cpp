#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades, int n) {

        int next_5 = 0;
        int temp_0;
        int temp_1;

        for(int i=0; i<n; i++){
            
            if(grades[i] < 38){
                grades[i] = grades[i];
                continue;
            }
            
            else{
                
                temp_0 = grades[i]%5;
                temp_1 = 5 - temp_0;

                next_5 = grades[i] + temp_1;
                //next_5 = ceil((grades[i]+5)/5) * 5;
        
                if(grades[i] >= 38){
            
                    if( (next_5 -grades[i])  < 3){
                        grades[i] = next_5;
                    }

                    if( (next_5 -grades[i])  >= 3){
                        grades[i] = grades[i];
                    }

                }
            }
            
        }

        return grades;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = gradingStudents(grades, grades_count);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

