////
//// Created by Bryan on 9/30/2017.
////
//
#include "expression.h"
#include <iostream>
//
///****Auxillary Function prototypes ****/
//bool is_number(std::string input_string);
//bool is_operator(std::string input_string);
//int get_number(std::string input_string);
//std::string get_operator(std::string input_string);
//int operator_priority(std::string operator_in);
///****end function prototypes****/
//
//
namespace lab5 {

    expression::expression() {
        length = 0;
    }

    expression::expression(std::string &input_expression) {
        //want to put each element of the string into one node each and omit all the spaces
        length = input_expression.length();


        /*
        char first[1];

        for (int i=0; i<length; i++){
            first[0] = input_expression.at(i);
            std::string newinput(first); //convert the first element of the string which has been converted to a character back into a string
            infix.enqueue(newinput); //separate out everything into a node for each
        }*/
        origexp = input_expression;

        parse_to_infix(input_expression);

        std::string a = " ";

        Operators.push(a);
        Eval.push(a);

        convert_to_postfix(newexp);
    }

/*
void expression::convert_to_postfix(std::string &input_expression) {
     // need to pop all the operators -> make sure to remove the parentheses (but that also indicates the operator calculation)
    // follow PEMDAS
    //need to have the two operands occur before its respective operator operators
    //numbers get added to the postfix queue, push the operators onto the stack
    //anything at tbe bottom of the stack gets utilized first (therefore indicates operator precedence)
    //push operators, and pop when you find out one succeding operator is lower or equal than this one -> add to postfix string -> push the succeeding operator


    char first[1];
    int length;
    length = input_expression.length();

    std::string Op;
    std::string Paren = "(";
    char stackTop;

    for (int i=0; i<length; i++){//-> next
        first[0] = input_expression.at(i);
        std::string newinput(first);
        std::string stackTop = Operators.top();

        // If character is operator, pop two elements from stack, perform operation and push the result back.
            if(input_expression.at(i) == ' '){
                continue;
            }
            else if(!is_operator(newinput)) {
                postfix.enqueue(newinput); //enqueue if it's a number
            }
            else if(is_operator(newinput)) //if it's a operator you need to push onto stack
            {//need to to check what's on the stack before you push this operator
                while(!Operators.isEmpty() && stackTop.at(0) != '(' && findHigher(newinput, Operators.top())) //want to stop when you reach a second parentheses
                {
                    Op = Operators.top();
                    postfix.enqueue(Op);
                    Operators.pop(); //want to pop when current operator is lower in precedence to the operator at the top of the stack
                }
                Operators.push(newinput);
            }
                // Else if character is an operand
            else if (input_expression.at(i) == '(')
            {
                Operators.push(newinput);
            }

            else if(input_expression.at(i) == ')')
            {
                while(!Operators.isEmpty() && stackTop.at(0) !=  '(') {
                    Op = Operators.top();
                    postfix.enqueue(Op);
                    Operators.pop();
                }
                Operators.pop();
            }
        }

        while(!Operators.isEmpty()) { //need to pop all the remaining operators
            Op = Operators.top();
            postfix.enqueue(Op);
            Operators.pop();
        }
        //if(is_operator(newinput)){
        //push onto the stack and pop off if
        //}
}*/
    void expression::convert_to_postfix(std::string &input_expression) {
        // need to pop all the operators -> make sure to remove the parentheses (but that also indicates the operator calculation)
        // follow PEMDAS
        //need to have the two operands occur before its respective operator
        //numbers get added to the postfix queue, push the operators onto the stack
        //anything at tbe bottom of the stack gets utilized first (therefore indicates operator precedence)
        //push operators, and pop when you find out one succeding operator is lower or equal than this one -> add to postfix string -> push the succeeding operator

        std::string Op;
        node *temp = infix.returnHead();
        std::string temp1;
        int newlen = length;

        for (int i = 0; i < length; i++) {//-> next
            std::string value = infix.top();
            //std::string stackTop = Operators.top();
            Op = Operators.top();

            // If character is operator, pop two elements from stack, perform operation and push the result back.
            if (value == " ") {
                continue;
            } else if (value == "(") {
                Operators.push(value);
                newlen--;
            } else if (value == ")") {
                while (!Operators.isEmpty() && Op != "(") {
                    Op = Operators.top();
                    if (Op != ")" && Op != "(" && Op != " ") {
                        postfix.enqueue(Op);
                    }
                    Operators.pop();
                }
                Operators.push(value);
                newlen--;
            } else if (is_operator(value)) //if it's a operator you need to push onto stack
            {//need to to check what's on the stack before you push this operator
                while (!Operators.isEmpty() && Op != "(" && findHigher(value, Operators.top())) //want to stop when you reach a second parentheses
                {
                    Op = Operators.top();
                    if (Op != ")" && Op != "(" && Op != " ") {
                        postfix.enqueue(Op);
                    }
                    Operators.pop(); //want to pop when current operator is lower in precedence to the operator at the top of the stack
                }
                    Operators.push(value);
            }
                // Else if character is an operand
            else if (!is_operator(value) && value != " ") {
                postfix.enqueue(value); //enqueue if it's a number
            }

            infix.dequeue();
        }

        while (!Operators.isEmpty()) { //need to pop all the remaining operators
            Op = Operators.top();
            if (Op != ")" && Op != "(") {
                postfix.enqueue(Op);
            }
            Operators.pop();
        }

        parse_to_infix(origexp); //reset infixexp so that it can be used for print

        length = newlen;
    }

    void expression::parse_to_infix(std::string &input_expression) {
        //set the numbers into a queue
        //set the operators into a queue

        //std::string newexp = "";
        int k = 0;

        int newlen = 0;
        //if see a number or a consecutive number put into a node in queue, do not append
        for (int i = 0; i < length; i++) {
            if (i < length - 1) {
                //     if (input_expression[i] >= 48 && input_expression[i] <= 57) {
                // newexp[k++] = input_expression[i];
                //     }
                // }
                // else{ // 9+20*8-3
                if (input_expression[i] >= 48 && input_expression[i] <= 57) { //add to string if 0-9
                    //newexp[k++] = input_expression[i];
                    newexp.push_back(input_expression[i]);
                }
                else if(input_expression[i] == ' '){
                    continue;
                }
                else {
                    infix.enqueue(newexp); //stores value from prev loop
                    newexp.clear(); //reset newexp
                    newexp = "";
                    k = 0; //reset counter
                    //newexp[k++] = input_expression[i];
                    newexp.push_back(input_expression[i]);
                    infix.enqueue(newexp);
                    newexp.clear(); //reset newexp
                    newexp = "";
                    k = 0;

                    newlen += 2;
                }
            } else {
                if (input_expression[i] >= 48 && input_expression[i] <= 57) { //add to string if 0-9
                    //newexp[k++] = input_expression[i];
                    newexp.push_back(input_expression[i]);
                    infix.enqueue(newexp);

                    newlen += 1;
                }
                else if(input_expression[i] == ' '){
                    continue;
                }
                else {
                    infix.enqueue(newexp); //stores value from prev loop
                    newexp.clear(); //reset newexp
                    newexp = "";
                    k = 0; //reset counter
                    //newexp[k++] = input_expression[i];

                    newexp.push_back(input_expression[i]);
                    infix.enqueue(newexp);

                    newlen += 2;
                }
            }
        }
        length = newlen;

/*
    node* temp = infix.returnHead(); // temp is set to equal to where head is

    while(temp != nullptr){//-> next
        std::cout << temp -> data << " ";
        temp = temp ->next;
    }*/
    }

    int expression::calculate_postfix() {
         //   convert_to_postfix(newexp);
        node *temp = postfix.returnHead();

        std::string tempVal1, tempVal2, tempRes, myOp;
        int finalVal;

        for (int i = 0; i < length; i++) {

            if (is_operator(temp->data)) {
                tempVal2 = Eval.top(); //there will never be only two numbers in the stack
                Eval.pop();
                tempVal1 = Eval.top();
                Eval.pop();

                myOp = temp->data;

                tempRes = operCalc(tempVal1, tempVal2, myOp);
                Eval.push(tempRes);
            } else {
                Eval.push(temp->data);
            }
            temp = temp->next;
        }

        finalVal = get_number(tempRes);

        return finalVal;
    }

    void expression::print_infix() {
        node *temp = infix.returnHead();
        int i=0;

        while (temp != nullptr) { //-> next
            if(i>0){
            std::cout << " ";}

            std::cout << temp->data;
            temp = temp->next;
            i++;
        }
    }

    void expression::print_postfix() {
        node *temp = postfix.returnHead();
        while (temp != nullptr) { //-> next
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    std::istream &operator>>(std::istream &steam, expression &RHS) {
        //takes in string
        std::string inputExp;

        std::cout << "Please enter expression you want to be evaluated" << std::endl;
        steam >> inputExp;

        RHS = expression(inputExp);

        return steam;
    }
//
//
////auxillary functions
//

    bool expression::is_number(std::string input_string) {
        if (input_string.at(0) <= 10000 && input_string.at(0) >= 0) {
            return true;
        } else {
            return false;
        }
    }

    bool expression::is_operator(std::string input_string) {
        if (input_string == "+")
            return true;
        else if (input_string == "-")
            return true;
        else if (input_string == "*")
            return true;
        else if (input_string == "/")
            return true;
//else if(input_string == "(")
//return true;
//else if(input_string == ")")
//return true;
        else
            return false;
    }

    bool expression::is_empty() {
        node *temp = Operators.returnHead();
        if (temp == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool expression::findHigher(std::string currentOp, std::string topOperator) {
        int precedence = 0;

        if (currentOp == "*")
            precedence = 6;
        else if (currentOp == "/")
            precedence = 5;
        else if (currentOp == "+")
            precedence = 4;
        else if (currentOp == "-")
            precedence = 3;
        else if (currentOp == "(")
            precedence = 2;
        else if (currentOp == ")")
            precedence = 1;

        if (topOperator == "*")
            precedence = 6;
        else if (topOperator == "/")
            precedence = 5;
        else if (topOperator == "+")
            precedence = 4;
        else if (topOperator == "-")
            precedence = 3;
        else if (topOperator == "(")
            precedence = 2;
        else if (topOperator == ")")
            precedence = 1;

        if (currentOp > topOperator) {
            return true;
        } else if (currentOp <= topOperator) {
            return false;
        }
    }

    int expression::get_number(std::string input_string) {
        //converts a string into a integer
        int actVal;

        actVal = std::atoi(input_string.c_str());//std::stoi (input_string,nullptr,input_string.length());

        return actVal;
    }

//std::string get_operator(std::string input_string){
//not needed for my code
//}

    int operator_priority(std::string operator_in) {
        int prec;
        if (operator_in == "*")
            prec = 6;
        else if (operator_in == "/")
            prec = 5;
        else if (operator_in == "+")
            prec = 4;
        else if (operator_in == "-")
            prec = 3;
        else if (operator_in == "(")
            prec = 2;
        else if (operator_in == ")")
            prec = 1;

        return prec;
    }

    std::string expression::operCalc(std::string Op1, std::string Op2, std::string Op) {
        //returns value of inputed expression

        //finds the appropriate operation to execute
        //converts to int
        //does calculation
        //converts back to string -> to_string function
        int v1, v2, result;
        v1 = get_number(Op1);
        v2 = get_number(Op2);

        std::string stResult;

        if (Op == "*")
            result = v1 * v2;
        else if (Op == "/")
        if(v2!=0) {
            result = v1 / v2; //will do integer division
        }
        else{
            result=1;
        }
        else if (Op == "+")
            result = v1 + v2;
        else if (Op == "-")
            result = v1 - v2;

        stResult = std::to_string(result);

        return stResult;
    }
}