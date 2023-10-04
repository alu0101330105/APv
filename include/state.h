/**
 * @file state.h
 * @author Jorge González Delgado (alu0101330105@ull.edu.es)
 * @brief  Class that represents a state of a pushdown automaton.
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef STATE_H
#define STATE_H

#include "transition.h"

class State {
  private:
    std::string name;
    std::vector<Transition> transitions;
    bool isInitial;
    bool isFinal;

  public:
    State();
    ~State() {};
    State(std::string name, bool isInitial = false);
    State(const State& state);
    void addTransition(Transition transition);
    void addTransition(std::vector<Transition> transitions);
    std::vector<Transition> getTransitions() const;
    std::string getName() const;
    bool IsInitial() const;
    bool IsFinal() const;
    void setInitial(bool isInitial);
    void setName(std::string name);
};

#endif // STATE_H