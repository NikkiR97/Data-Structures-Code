#ifndef CMPE126F17_LABS_LIB_LAB05_INC_EXPRESSION_H
#define CMPE126F17_LABS_LIB_LAB05_INC_EXPRESSION_H

#include "queue.h"
#include "stack.h"

namespace lab5 {
    class expression {
        queue infix;
        queue postfix;
        stack Operators;
        stack Eval;

        int length;
        std::string origexp;
        std::string newexp;
        
    public:
        void convert_to_postfix(std::string &input_expression); //move back to private area
        void parse_to_infix(std::string &input_expression); //move back to private area
        
        expression();
        expression(std::string& input_expression);

        int calculate_postfix();
        void print_infix();
        void print_postfix();
        friend std::istream &operator>>(std::istream &steam, expression &RHS);
        
        bool is_number(std::string input_string);
        bool is_operator(std::string input_string);

        bool is_empty();

        int get_number(std::string input_string);

        std::string operCalc(std::string Op1, std::string Op2, std::string Op);

        bool findHigher(std::string currentOp, std::string topOperator);

        friend std::istream& operator>>(std::istream& steam, expression& RHS);

        int operator_priority(std::string operator_in);

    };
}

#endif //CMPE126F17_LABS_LIB_LAB05_INC_EXPRESSION_H
