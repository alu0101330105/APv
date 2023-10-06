/**
 * @file pushdownAutomata.cc
 * @author Jorge González Delgado (alu0101330105@ull.edu.es)
 * @brief Class that represents a pushdown automaton.
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pushdownAutomata.h"
#define EPSILON '.'

/**
 * @brief Construct a new Pushdown Automata object
 * @details This constructor is used to create a pushdown automaton with empty values.
 */
PushDownAutomata::PushDownAutomata() {
  this->alphabet = {};
  this->stackAlphabet = {};
  this->states = {};
  this->initialState = "";
  this->initialStackSymbol = "";
  this->finalState = "";
}

/**
 * @brief Copy constructor of Pushdown Automata.
 * @details This constructor is used to create a pushdown automaton with the values of another pushdown automaton.
 * 
 * @param automata - The pushdown automaton to be copied.
 */
PushDownAutomata::PushDownAutomata(PushDownAutomata& automata) {
  this->alphabet = automata.getAlphabet();
  this->stackAlphabet = automata.getStackAlphabet();
  this->states = automata.getStates();
  this->initialState = automata.getInitialState();
  this->initialStackSymbol = automata.getInitialStackSymbol();
  this->finalState = automata.getFinalState();
}

/**
 * @brief Add a state to the pushdown automaton.
 * @details This method adds a state to the pushdown automaton.
 * 
 * @param state - The state to be added.
 */
void PushDownAutomata::addState(State state) {
  this->states.push_back(state);
}

/**
 * @brief Add a vector of states to the pushdown automaton.
 * @details This method adds a vector of states to the pushdown automaton.
 * 
 * @param states - The vector of states to be added.
 */
void PushDownAutomata::addState(std::vector<State> states) {
  for (int i = 0; i < states.size(); i++) {
    this->states.push_back(states[i]);
  }
}

/**
 * @brief Add a vector of symbols to the alphabet of the pushdown automaton.
 * @details This method adds a vector of symbols to the alphabet of the pushdown automaton.
 * 
 * @param alphabet - The vector of symbols to be added.
 */
void PushDownAutomata::addAlphabet(std::vector<char> alphabet) {
  for (int i = 0; i < alphabet.size(); i++) {
    this->alphabet.push_back(alphabet[i]);
  }
}

/**
 * @brief Add a vector of symbols to the stack alphabet of the pushdown automaton.
 * @details This method adds a vector of symbols to the stack alphabet of the pushdown automaton.
 * 
 * @param stackAlphabet - The vector of symbols to be added.
 */
void PushDownAutomata::addStackAlphabet(std::vector<char> stackAlphabet) {
  for (int i = 0; i < stackAlphabet.size(); i++) {
    this->stackAlphabet.push_back(stackAlphabet[i]);
  }
}

/**
 * @brief Set the initial state of the pushdown automaton.
 * @details This method sets the initial state of the pushdown automaton.
 * 
 * @param initialState - The name of the initial state.
 */
void PushDownAutomata::setInitialState(std::string initialState) {
  this->initialState = initialState;
}

/**
 * @brief Set the initial stack symbol of the pushdown automaton.
 * @details This method sets the initial stack symbol of the pushdown automaton.
 * 
 * @param initialStackSymbol - The name of the initial stack symbol.
 */
void PushDownAutomata::setInitialStackSymbol(std::string initialStackSymbol) {
  this->initialStackSymbol = initialStackSymbol;
}

/**
 * @brief Get the states of the pushdown automaton.
 * @details This method returns the vector of states of the pushdown automaton.
 * 
 * @return std::vector<State> 
 */
std::vector<State> PushDownAutomata::getStates() const {
  return this->states;
}

/**
 * @brief Get the alphabet of the pushdown automaton.
 * @details This method returns the vector of symbols of the alphabet of the pushdown automaton.
 * 
 * @return std::vector<char> 
 */
std::vector<char> PushDownAutomata::getAlphabet() const {
  return this->alphabet;
}

/**
 * @brief Get the stack alphabet of the pushdown automaton.
 * @details This method returns the vector of symbols of the stack alphabet of the pushdown automaton.
 * 
 * @return std::vector<char> 
 */
std::vector<char> PushDownAutomata::getStackAlphabet() const {
  return this->stackAlphabet;
}

/**
 * @brief Get the initial state of the pushdown automaton.
 * @details This method returns the name of the initial state of the pushdown automaton.
 * 
 * @return char 
 */
std::string PushDownAutomata::getInitialState() const {
  return this->initialState;
}

/**
 * @brief Get the final state of the pushdown automaton.
 * @details This method returns the name of the final state of the pushdown automaton.
 * 
 * @return char 
 */
std::string PushDownAutomata::getFinalState() const {
  return this->finalState;
}

/**
 * @brief Get the initial stack symbol of the pushdown automaton.
 * @details This method returns the name of the initial stack symbol of the pushdown automaton.
 * 
 * @return std::string
 */
std::string PushDownAutomata::getInitialStackSymbol() const {
  return this->initialStackSymbol;
}

/**
 * @brief Get the state with the given name.
 * @details This method returns the state with the given name.
 * 
 * @param name - The name of the state to be returned.
 * @return State 
 */
State PushDownAutomata::getState(std::string name) const {
  for (int i = 0; i < this->states.size(); i++) {
    if (this->states[i].getName() == name) {
      return this->states[i];
    }
  }
  State empty;
  return empty;
}

/**
 * @brief Get the next states of the pushdown automaton.
 * @details This method returns the vector of next states of the pushdown automaton.
 * 
 * @param stateName - The name of the state.
 * @param symbol - The symbol that triggers the transition.
 * @param stackSymbol - The symbol that must be on the top of the stack to trigger the transition.
 * @return std::vector<State> 
 */
std::vector<State> PushDownAutomata::getNextStates(std::string stateName, char symbol, char stackSymbol) const {
  std::vector<State> nextStates;
  for (int i = 0; i < this->states.size(); i++) {
    if (this->states[i].getName() == stateName) {
      std::vector<Transition> transitions = this->states[i].getTransitions();
      for (int j = 0; j < transitions.size(); j++) {
        if (transitions[j].getSymbol() == symbol && transitions[j].getStackSymbol() == stackSymbol) {
          nextStates.push_back(this->getState(transitions[j].getDestiny()));
        }
      }
    }
  }
  return nextStates;
}

std::vector<Transition> PushDownAutomata::getTransitions(std::string actualStateName, char stackSymbol, char actualSymbol) const{
  // std::cout << "entered getTransitiona of automata\n";
  State actualState = getState(actualStateName);
  std::vector<Transition> transitions = actualState.getTransitions();
  std::vector<Transition> compatibleTrans;

  // std::cout << "actual state = " + actualState.getName();
  // std::cout << "Debug transition:\n";
  // for(Transition t : transitions) std::cout << t.toString() + "\n";


  for(int j = 0; j < transitions.size(); j++) {
    // std::cout << transitions[j].getStackSymbol() << transitions[j].getSymbol();
    if(transitions[j].getStackSymbol() == stackSymbol && transitions[j].getSymbol() == actualSymbol) {
      compatibleTrans.push_back(transitions[j]);
    }
  }
  return compatibleTrans;
}

bool PushDownAutomata::isAccepted(std::string word, bool trace) const {
  std::stack<char> pile;
  std::string initialSS = this->initialStackSymbol;
  while (initialSS.size() > 0) {
    if(initialSS.back() != EPSILON) pile.push(initialSS.back());
    initialSS.pop_back();
  }

  // std::cout << "calling for recursion: started\n";
  return isAccepted(word, pile, initialState, true);
}

/**
 * @brief Check if the word is accepted by the pushdown automaton.
 * @details This method checks if the word is accepted by the pushdown automaton.
 * 
 * @param word - The word to be checked.
 * @param trace - If true, the trace of the execution will be printed.
 * @return true 
 * @return false 
 */
bool PushDownAutomata::isAccepted(const std::string& word, std::stack<char> pile, const std::string currentStateName, bool trace) const {

  if(trace) {
    std::cout << "Actual string: " + (word.empty() ? "." : word) + "\nPile: ";
    std::stack<char> showPile = pile;
    std::string showString = "";
    while (!showPile.empty()) { 
      showString = showString + showPile.top() + ' ';
      showPile.pop();
    }
    std::cout << showString + "\n";
  }
  // if(word.empty()) std::cout << "word empty\n";
  // if(pile.empty()) std::cout << "pile empty\n";
  if (word.empty() && pile.empty()) {
    // Si la cadena y la pila están vacías, se acepta
    return true;
  }

  // std::cout << "entered recursive isAccepted\n";
  char actualSymbol = (word.empty()) ? '\0' : word[0];

  State currentState = getState(currentStateName);
  // std::cout << "getting transitions\n";
  std::vector<Transition> compatibleTrans = getTransitions(currentStateName, pile.top(), actualSymbol);

  if(trace) {
  }

  for (const Transition& trans : compatibleTrans) {
    std::string newSS = trans.getNewStackSymbol();

    if (trace) {
      std::cout << "Trying transition: \n";
      std::cout << "  (" << currentState.getName() << ", " << actualSymbol << ", " <<
        pile.top() << ") → (" << trans.getDestiny() << ", " << newSS << ")\n";
    }

    State newState = getState(trans.getDestiny());

    // Actualiza la pila con el nuevo símbolo
    pile.pop();
    while (newSS.size() > 0) {
      if(newSS.back() != EPSILON) pile.push(newSS.back());
      newSS.pop_back();
    }

    std::string newWord = word;
    newWord.erase(newWord.begin());
    // Llama recursivamente a isAccepted con la nueva configuración
    if (isAccepted(newWord, pile, newState.getName(), trace)) {
      return true; // Si se encontró una ruta válida, regresa true
    } else {
      if(trace) std::cout << "Transition Dead End - Trying another\n";
    }
  }

  return false; // Si no se encontraron rutas válidas, regresa false
}
