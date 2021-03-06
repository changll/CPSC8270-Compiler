#include <cmath>

#include "node.h"
#include "poolOfNodes.h"

class Literal : public Node {
public:
  virtual ~Literal() {}

  virtual const Literal* operator+(const Literal& rhs) const = 0;
  virtual const Literal* opPlus(float) const = 0;
  virtual const Literal* opPlus(int) const = 0;

  virtual const Literal* operator*(const Literal& rhs) const = 0;
  virtual const Literal* opMult(float) const = 0;
  virtual const Literal* opMult(int) const = 0;

  virtual const Literal* operator-(const Literal& rhs) const = 0;
  virtual const Literal* opSubt(float) const = 0;
  virtual const Literal* opSubt(int) const = 0;

  virtual const Literal* operator/(const Literal& rhs) const = 0;
  virtual const Literal* opDiv(float) const = 0;
  virtual const Literal* opDiv(int) const = 0;
  
  virtual const Literal* intDiv(const Literal& rhs) const = 0;
  virtual const Literal* opIntDiv(float) const = 0;
  virtual const Literal* opIntDiv(int) const = 0;

  virtual const Literal* operator%(const Literal& rhs) const = 0;
  virtual const Literal* opMod(float) const = 0;
  virtual const Literal* opMod(int) const = 0;

  virtual const Literal* operator^(const Literal& rhs) const = 0;
  virtual const Literal* opExp(float) const = 0;
  virtual const Literal* opExp(int) const = 0;

  virtual const Literal* eval() const = 0;
  virtual void print() const { 
    std::cout << "No Way" << std::endl; 
  }
};

class FloatLiteral: public Literal {
public:
  FloatLiteral(float _val): val(_val) {}

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node; 
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(lhs) * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* intDiv(const Literal& rhs) const {
    return rhs.opIntDiv(val);
  }
  virtual const Literal* opIntDiv(float lhs) const {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opIntDiv(int lhs) const {
    return this->opIntDiv((float)lhs);
  }

  virtual const Literal* operator%(const Literal& rhs) const {
    return rhs.opMod(val);
  }

  virtual const Literal* opMod(float lhs) const {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float r = fmod((fmod(lhs, val) + val), val);
    const Literal* node = new FloatLiteral(r);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* opMod(int lhs) const {
    return this->opMod((float)lhs);
  }

  virtual const Literal* operator^(const Literal& rhs) const {
    return rhs.opExp(val);
  }
  virtual const Literal* opExp(float lhs) const {
    if ( lhs == 0 && val < 0 ) {
      throw std::string("ZeroDivisionError: 0.0 cannot be raised to a negative power");
    }
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opExp(int lhs) const {
    if ( lhs == 0 && val < 0 ) {
      throw std::string("ZeroDivisionError: 0 cannot be raised to a negative power");
    }
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    if ((int)val == val) {
      std::cout << val << ".0" << std::endl;
    } else {
      std::cout << val << std::endl;
    }
  }
private:
  float val;
};

class IntLiteral: public Literal {
public:
  IntLiteral(int _val): val(_val) {}

  virtual const Literal* operator+(const Literal& rhs) const  {
    return rhs.opPlus(val);
  }
  virtual const Literal* opPlus(float lhs) const  {
    const Literal* node = new FloatLiteral(static_cast<float>(val) + lhs);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opPlus(int lhs) const  {
    const Literal* node = new IntLiteral(lhs + val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator-(const Literal& rhs) const  {
    return rhs.opSubt(val);
  }
  virtual const Literal* opSubt(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opSubt(int lhs) const  {
    const Literal* node = new IntLiteral(lhs - val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator*(const Literal& rhs) const  {
    return rhs.opMult(val);
  }
  virtual const Literal* opMult(float lhs) const  {
    const Literal* node = new FloatLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opMult(int lhs) const  {
    const Literal* node = new IntLiteral(lhs * val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator/(const Literal& rhs) const  {
    return rhs.opDiv(val);
  }
  virtual const Literal* opDiv(float lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(lhs / val);
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opDiv(int lhs) const  {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float res = (float)lhs / val;
    const Literal* node = new IntLiteral(std::floor(res));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* intDiv(const Literal& rhs) const {
    return rhs.opIntDiv(val);
  }
  virtual const Literal* opIntDiv(float lhs) const {
    if ( val == 0 ) throw std::string("Zero Division Error");
    const Literal* node = new FloatLiteral(std::floor(lhs / val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opIntDiv(int lhs) const {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float res = (float)lhs / val;
    const Literal* node = new IntLiteral(std::floor(res));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator%(const Literal& rhs) const {
    return rhs.opMod(val);
  }

  virtual const Literal* opMod(float lhs) const {
    if ( val == 0 ) throw std::string("Zero Division Error");
    float r = fmod((fmod(lhs, val) + val), val);
    const Literal* node = new FloatLiteral(r);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* opMod(int lhs) const {
    if ( val == 0 ) throw std::string("Zero Division Error");
    int r = ((lhs % val) + val) % val;
    const Literal* node = new IntLiteral(r);
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* operator^(const Literal& rhs) const {
    return rhs.opExp(val);
  }
  virtual const Literal* opExp(float lhs) const {
    if ( lhs == 0 && val < 0 ) {
      throw std::string("ZeroDivisionError: 0.0 cannot be raised to a negative power");
    }
    const Literal* node = new FloatLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }
  virtual const Literal* opExp(int lhs) const {
    if ( lhs == 0 && val < 0 ) {
      throw std::string("ZeroDivisionError: 0 cannot be raised to a negative power");
    }
    const Literal* node = new IntLiteral(pow(lhs, val));
    PoolOfNodes::getInstance().add(node);
    return node;
  }

  virtual const Literal* eval() const { return this; }
  virtual void print() const { 
    std::cout << val << std::endl; 
  }
private:
  int val;
};

