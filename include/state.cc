/**
 * @file state.cc
 * @author Jorge González Delgado (alu0101330105@ull.edu.es)
 * @brief Class that represents a state of a pushdown automaton.
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "state.h"

/**
 * @brief Construct a new empty State object
 * @details This constructor is used to create a state with empty values.
 */
State::State() {
  this->name = "";
  this->isInitial = false;
}

/**
 * @brief Construct a new State object
 * @details This constructor is used to create a state with the given values.
 * 
 * @param name - The name of the state.
 * @param isFinal - A boolean that indicates if the state is final.
 * @param isInitial - A boolean that indicates if the state is initial.
 */
State::State(std::string name, bool isInitial) {
  this->name = name;
  this->isInitial = isInitial;
}

/**
 * @brief Copy constructor of State.
 * @details This constructor is used to create a state with the values of another state.
 * 
 * @param state - The state to be copied.
 */
State::State(const State& state) {
  this->name = state.getName();
  this->isInitial = state.IsInitial();
  this->isFinal = state.IsFinal();
  this->transitions = state.getTransitions();
}

/**
 * @brief Add a transition to the state.
 * @details This method adds a transition to the state.
 * 
 * @param transition - The transition to be added.
 */
void State::addTransition(Transition transition) {
  this->transitions.push_back(transition);
}

/**
 * @brief Add a vector of transitions to the state.
 * @details This method adds a vector of transitions to the state.
 * 
 * @param transitions - The vector of transitions to be added.
 */
void State::addTransition(std::vector<Transition> transitions) {
  for (int i = 0; i < transitions.size(); i++) {
    this->transitions.push_back(transitions[i]);
  }
}

/**
 * @brief Get the transitions of the state.
 * @details This method returns the vector of transitions of the state.
 * 
 * @return std::vector<Transition> 
 */
std::vector<Transition> State::getTransitions() const {
  return this->transitions;
}

/**
 * @brief Get the name of the state.
 * @details This method returns the name of the state.
 * 
 * @return std::string 
 */
std::string State::getName() const {
  return this->name;
}

/**
 * @brief Get the isInitial value of the state.
 * @details This method returns the wether the state is the Initial state.
 * 
 * @return true 
 * @return false 
 */
bool State::IsInitial() const {
  return this->isInitial;
}

/**
 * @brief Get the isFinal value of the state.
 * @details This method returns wether the State is Final or acceptation.
 * 
 * @return true 
 * @return false 
 */
bool State::IsFinal() const {
  return this->isFinal;
}

/**
 * @brief Set the isInitial value of the state.
 * @details This method sets the isInitial value of the state.
 * 
 * @param isInitial - The new value of isInitial.
 */
void State::setInitial(bool isInitial) {
  this->isInitial = isInitial;
}

/**
 * @brief Set the name of the state.
 * @details This method sets the name of the state.
 * 
 * @param name - The new name of the state.
 */
void State::setName(std::string name) {
  this->name = name;
}