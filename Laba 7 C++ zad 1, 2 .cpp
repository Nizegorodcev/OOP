#include <iostream>
#include <cassert>
using namespace std;

class Expression {
public:
    virtual ~Expression() {}
    virtual double evaluate() const = 0;
};

class Number : public Expression
{
private:
    double value_;
public:
    Number(double value) : value_(value) {}
    double value() const { return value_; }
    double evaluate() const { return value_; }
};

class BinaryOperation :public Expression
{
private:
    Expression const* left_;
    Expression const* right_;
    int op_;
public:
    enum {
        PLUS = '+',
        MINUS = '-',
        DIV = '/',
        MUL = '*'
    };

    BinaryOperation(Expression const* left, int op, Expression const* right) :left_(left), op_(op), right_(right)
    {
        assert(left_ && right_);
    }

    ~BinaryOperation()
    {
        delete left_;
        delete right_;
    }

    Expression const* left() const { return left_; }
    Expression const* right() const { return right_; }

    int operation() const { return op_; }

    double evaluate() const
    {
        double left = left_->evaluate();
        double right = right_->evaluate();
        switch (op_)
        {
        case PLUS: return left + right;
        case MINUS: return left - right;
        case DIV: return left / right;
        case MUL: return left * right;
        }
        assert(0);
        return 0.0;
    }
};

class FunctionCall : public Expression
{
private:
    string name_;
    Expression const* arg_;
public:
    FunctionCall(string const& name, Expression const* arg) : name_(name), arg_(arg)
    {
        assert(arg_);
    }

    ~FunctionCall()
    {
        delete arg_;
    }

    double evaluate() const
    {
        double arg = arg_->evaluate();
        if (name_ == "sqrt") return sqrt(arg);
        else if (name_ == "abs") return abs(arg);
        else
        {
            assert(false);
            return 0.0;
        }
    }

    string const& name() const
    {
        return name_;
    }

    Expression const* arg() const
    {
        return arg_;
    }
};


int main()
{
    setlocale(LC_ALL, "RUS");

    Expression* e1 = new Number(1.234);
    Expression* e2 = new Number(-1.234);
    Expression* e3 = new BinaryOperation(e1, BinaryOperation::DIV, e2);
    cout << e3->evaluate() << endl;
    e3 = new BinaryOperation(e1, BinaryOperation::PLUS, e2);
    cout << e3->evaluate() << endl;
    e3 = new BinaryOperation(e1, BinaryOperation::MINUS, e2);
    cout << e3->evaluate() << endl;
    e3 = new BinaryOperation(e1, BinaryOperation::MUL, e2);
    cout << e3->evaluate() << endl;

    Expression* n32 = new Number(32.0);
    Expression* n16 = new Number(16.0);
    Expression* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
    Expression* callSqrt = new FunctionCall("sqrt", minus);

    Expression* n2 = new Number(2.0);
    Expression* mult = new BinaryOperation(n2, BinaryOperation::MUL, callSqrt);
    Expression* callAbs = new FunctionCall("abs", mult);

    cout << callAbs->evaluate() << endl;
}