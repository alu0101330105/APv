/**
 * @file pushdownAutomata.h
 * @author Jorge González Delgado (alu0101330105@ull.edu.es)
 * @brief Class that represents a pushdown automaton. This automata acceps with empty stack.
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef PUSHDOWNAUTOMATA_H
#define PUSHDOWNAUTOMATA_H

#include "state.h"
#include <stack>
#include <algorithm>

class PushDownAutomata {
  private:
    std::vector<State> states;
    std::vector<char> alphabet;
    std::vector<char> stackAlphabet;
    std::string initialState;
    std::string finalState;
    char initialStackSymbol;

  public:
    PushDownAutomata();
    PushDownAutomata(PushDownAutomata& automata);
    ~PushDownAutomata() {};
    void addState(const State state);
    void addState(std::vector<State> states);
    void addAlphabet(std::vector<char> alphabet);
    void addStackAlphabet(std::vector<char> stackAlphabet);
    void setInitialState(std::string initialState);
    void setInitialStackSymbol(char initialStackSymbol);
    void setFinalState(std::string finalState);
    std::vector<State> getStates() const;
    std::vector<char> getAlphabet() const;
    std::vector<char> getStackAlphabet() const;
    std::string getInitialState() const;
    std::string getFinalState() const;
    char getInitialStackSymbol() const;
    State getState(std::string name) const;
    std::vector<State> getNextStates(std::string stateName, char symbol, char stackSymbol) const;
    std::vector<Transition> getTransitions(State state, char stackSymbol, char symbol) const;
    bool isAccepted(std::string word, bool trace = false) const;
    bool isAccepted(const std::string& word, std::stack<char> pile, const State& currentState, bool trace = false) const;
};

#endif // PUSHDOWNAUTOMATA_H