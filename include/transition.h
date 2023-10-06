/**
 * @file transition.h
 * @author Jorge González Delgado (alu0101330105@ull.edu.es)
 * @brief Class that represents a transition of a pushdown automaton.
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <vector>
#include <string>

class Transition {
  private:
    std::string origin = "";
    std::string destiny = "";
    char symbol = '\0';
    char stackSymbol = '\0';
    std::string newStackSymbol = "";
  
  public:
    Transition();
    ~Transition() {};
    Transition(std::string origin, std::string destiny,
      char symbol, char stackSymbol, std::string newStackSymbol);
    Transition(const Transition& transition);
    std::string getOrigin() const;
    std::string getDestiny() const;
    char getSymbol() const;
    char getStackSymbol() const;
    std::string getNewStackSymbol() const;
    void setOrigin(std::string origin);
    void setDestiny(std::string destiny);
    void setSymbol(char symbol);
    void setStackSymbol(char stackSymbol);
    void setNewStackSymbol(std::string newStackSymbol);
    std::string toString() const;

};

#endif // TRANSITION_H