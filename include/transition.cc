/**
 * @file transition.cc
 * @author Jorge González Delgado (alu0101330105@ull.edu.es)
 * @brief Class that represents a transition of a pushdown automaton.
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "transition.h"

/**
 * @brief Construct a new empty Transition object.
 * @details This constructor is used to create a transition with empty values.
 */
Transition::Transition() {
  this->symbol = '\0';
  this->origin = "";
  this->destiny = "";
  this->stackSymbol = '\0' ;
  this->newStackSymbol = "";
}

/**
 * @brief Construct a new Transition object.
 * @details This constructor is used to create a transition with the given values.
 * 
 * @param origin - The origin state of the transition.
 * @param destiny - The destiny state of the transition.
 * @param symbol - The symbol that triggers the transition. 
 * @param stackSymbol - The symbol that must be on the top of the stack to trigger the transition.
 * @param newStackSymbol - The symbol that will be put on the top of the stack after the transition.
 */
Transition::Transition(std::string origin, std::string destiny, char symbol, char stackSymbol, std::string newStackSymbol) {
  this->symbol = symbol;
  this->origin = origin;
  this->destiny = destiny;
  this->stackSymbol = stackSymbol;
  this->newStackSymbol = newStackSymbol;
}

/**
 * @brief Copy constructor of Transition.
 * @details This constructor is used to create a transition with the values of another transition.
 * 
 * @param transition - The transition to be copied.
 */
Transition::Transition(const Transition& transition) {
  this->symbol = transition.getSymbol();
  this->origin = transition.getOrigin();
  this->destiny = transition.getDestiny();
  this->stackSymbol = transition.getStackSymbol();
  this->newStackSymbol = transition.getNewStackSymbol();
}

/**
 * @brief Get the Origin state of the transition.
 * @details This method returns the origin state name of the transition.
 * 
 * @return std::string 
 */
std::string Transition::getOrigin() const {
  return this->origin;
}

/**
 * @brief Get the Destiny state of the transition.
 * @details This method returns the destiny state name of the transition.
 * 
 * @return std::string 
 */
std::string Transition::getDestiny() const {
  return this->destiny;
}

/**
 * @brief Get the Symbol that triggers the transition.
 * @details This method returns the symbol that triggers the transition.
 * 
 * @return std::string 
 */
char Transition::getSymbol() const {
  return this->symbol;
}

/**
 * @brief Get the stack symbol of the transition.
 * @details This method returns the symbol that must be on the top of the stack to trigger the transition.
 * 
 * @return char 
 */
char Transition::getStackSymbol() const {
  return this->stackSymbol;
}

/**
 * @brief Get the new stack symbol of the transition.
 * @details This method returns the symbol that will be put on the top of the stack after the transition.
 * 
 * @return std::string 
 */
std::string Transition::getNewStackSymbol() const {
  return this->newStackSymbol;
}

/**
 * @brief Set the Origin state of the transition.
 * @details This method sets the origin state name of the transition.
 * 
 * @param origin - The origin state name of the transition.
 */
void Transition::setOrigin(std::string origin) {
  this->origin = origin;
}

/**
 * @brief Set the Destiny state of the transition.
 * @details This method sets the destiny state name of the transition.
 * 
 * @param destiny - The destiny state name of the transition.
 */
void Transition::setDestiny(std::string destiny) {
  this->destiny = destiny;
}

/**
 * @brief Set the Symbol that triggers the transition.
 * @details This method sets the symbol that triggers the transition.
 * 
 * @param symbol - The symbol that triggers the transition.
 */
void Transition::setSymbol(char symbol) {
  this->symbol = symbol;
}

/**
 * @brief Set the stack symbol of the transition.
 * @details This method sets the symbol that must be on the top of the stack to trigger the transition.
 * 
 * @param stackSymbol - The symbol that must be on the top of the stack to trigger the transition.
 */
void Transition::setStackSymbol(char stackSymbol) {
  this->stackSymbol = stackSymbol;
}

/**
 * @brief Set the new stack symbol of the transition.
 * @details This method sets the symbol that will be put on the top of the stack after the transition.
 * 
 * @param newStackSymbol - The symbol/s that will be put on the top of the stack after the transition.
 */
void Transition::setNewStackSymbol(std::string newStackSymbol) {
  this->newStackSymbol = newStackSymbol;
}

std::string Transition::toString() const {
  std::string output = "(" + this->origin + ", " + this->symbol + ", " + this->stackSymbol + 
      ") → (" + this->destiny + ", " + this->newStackSymbol + ")";
  return output; 
}