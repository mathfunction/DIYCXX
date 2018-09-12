/*------------------------------------------------------------------------


source code from :
	plus:
		https://www.geeksforgeeks.org/sum-two-large-numbers/
	multiply:
		https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/






-------------------------------------------------------------------------*/

#ifndef __BIG_NUMBER_HPP__
#define __BIG_NUMBER_HPP__

	
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;




namespace big_number{
	


string addZero(string str){
    str.push_back('0');
    return str;
}//end_addZero

string addDot(string str){
    str.push_back('.');
    return str;
}//end_addDot


string positive_int_addition(string str1, string str2){
	// Before proceeding further, make sure length
    // of str2 is larger.
    if(str1.length() > str2.length()){
        swap(str1, str2);
    }//endif
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate lenght of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
 
    // Initialy take carry zero
    int carry = 0;
 
    // Traverse from end of both strings
    for(int i=n1-1;i>=0;i--){
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }//endfor
 
    // Add remaining digits of str2[]
    for(int i=n2-n1-1; i>=0; i--){
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }//endfor
 
    // Add remaining carry
    if (carry){
        str.push_back(carry+'0');
    }//endif
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}//end_addition





// Multiplies str1 and str2, and prints result.
string positive_int_multiply(string num1, string num2){
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0){
       return "0";
    }//endif
    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);
    // Below two indexes are used to find positions
    // in result. 
    int i_n1 = 0; 
    int i_n2 = 0; 
    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--){
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0; 
        // Go from right to left in num2             
        for (int j=n2-1; j>=0; j--){
            // Take current digit of second number
            int n2 = num2[j] - '0';
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position. 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            // Carry for next iteration
            carry = sum/10;
            // Store result
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }//endfor
 
        // store carry in next cell
        if (carry > 0){
            result[i_n1 + i_n2] += carry;
        }//endif
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }//endfor
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0){
       i--;
    }//end_while
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1){
       return "0";
    }//endif
 
    // generate the result string
    string s = "";
    while (i >= 0){
        s += to_string(result[i--]);
    }//end_while
 
    return s;
}//end_multiply



string positive_int_power(string base,string n){
	string output = "1";
	int n_int = atoi(n.c_str());
	for(int i=0;i<n_int;i++){
		output = positive_int_multiply(output,base);
	}//endfor
	return output;
}//end_power




bool positive_int_isSmaller(string str1, string str2){
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
    if (n1 < n2) return true;
    if (n2 < n1) return false;
    for (int i=0; i<n1; i++){
        if (str1[i] < str2[i]) return true;
        else if (str1[i] > str2[i]) return false;
    }//endfor
    return false;
}//end_isSmaller


string positive_int_diff(string str1,string str2){
    // Before proceeding further, make sure str1
    // is not smaller
    if (positive_int_isSmaller(str1, str2)){
        swap(str1, str2);
    }//endif
    // Take an empty string for storing result
    string str = "";
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i=0; i<n2; i++){
        // Do school mathematics, compute difference of
        // current digits    
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if(sub < 0){
            sub = sub + 10;
            carry = 1;
        }else{
            carry = 0;
        }//end_else
        str.push_back(sub + '0');
    }//endfor
 
    // subtract remaining digits of larger number
    for (int i=n2; i<n1; i++){
        int sub = ((str1[i]-'0') - carry); 
        // if the sub value is -ve, then make it positive
        if (sub < 0){
            sub = sub + 10;
            carry = 1;
        }else{
            carry = 0;
        }//end_else
        str.push_back(sub + '0');
    }//endfor
    // reverse resultant string
    reverse(str.begin(), str.end());
    
    return str;
}//end_positive_int_diff











}//end_namespace









#endif