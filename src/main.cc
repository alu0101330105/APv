/**
 * @file main.cc
 * @author Jorge González Delgado (alu0101330105@ull.edu.es)
 * @brief Main program for the pushdown automata 
 * @version 0.1
 * @date 2023-10-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../include/pushdownAutomata.h"
#include <fstream>
#include <sstream>

void readFromFile(std::string filename, PushDownAutomata APv) {
  std::fstream file;
  file.open(filename, std::ios::in);

  if(!file.is_open()) {
    std::cerr << "Error oppening file\n";
    exit(EXIT_FAILURE);
  }

  std::string line;
  std::getline(file, line);
  while(line[0] == '#') {
    getline(file, line);
  }

  std::vector<std::string> statesRaw;
  std::istringstream ss(line);
  std::string token;
  char delimeter = ' ';
  while(std::getline(ss, token, delimeter)) {
    statesRaw.push_back(token);
  }

  std::getline(file, line);
  ss.clear();
  ss.str(line);
  std::vector<char> alphabet;
  while(std::getline(ss, token, delimeter)) {
    alphabet.push_back(token[0]);
  }

  std::getline(file, line);
  ss.clear();
  ss.str(line);
  std::vector<char> stackAlphabet;
  while(std::getline(ss, token, delimeter)) {
    stackAlphabet.push_back(token[0]);
  }

  std::string initialState;
  std::getline(file, initialState);

  std::vector<State> stateVector;
  for(std::string name : statesRaw) {
    State state(name);
    if(name == initialState) state.setInitial(true);
    stateVector.push_back(state);
  }

  std::string stackInitialSymbol;
  std::getline(file, stackInitialSymbol);

  std::vector<Transition> transitions;
  while(std::getline(file, line)) {
    ss.clear();
    ss.str(line);
    std::vector<std::string> trans;
    while(std::getline(ss, token, delimeter)) {
      trans.push_back(token);
    }

    Transition newTrans(trans[0], trans[3], trans[1][0], trans[2][0], trans[4]);
    transitions.push_back(newTrans);
  }

  for(Transition actual : transitions) {
    for(State state : stateVector) {
      if(actual.getOrigin() == state.getName()) state.addTransition(actual);
    } 
  }

  std::cout << "read automata:\n  alphabet = {";
  for(char c : alphabet) {
    std::cout << c << " ";
  }
  std::cout << "  }\n  stack alphabet = {";
  for(char c : stackAlphabet) {
    std::cout << c << " ";
  }
  std::cout << "  }\n  states = {";
  for(State s : stateVector) {
    std::cout << s.getName() << " ";
  }
  std::cout << "  }\n  transitions = {\n";
  for(State s : stateVector) {
    for(Transition t : s.getTransitions()) {
      std::cout << "    " + t.toString() + "\n";
    }
  }
  std::cout << "  }\n";


  APv.addAlphabet(alphabet);
  APv.addStackAlphabet(stackAlphabet);
  APv.addState(stateVector);
}

void testLoop(PushDownAutomata APv) {
  std::string word;
  while(true) {
    std::cin >> word;
    bool accepted = APv.isAccepted(word, true);
    std::cout << "The word " + word + " is";
    if(!accepted) std::cout << " not";
    std::cout << " accepted by the languaje.\n";
  }
}

int main(int argc, char* argv[]) {
  std::string filename = argv[1];
  PushDownAutomata APv;

  readFromFile(filename, APv);
  
  testLoop(APv);
}