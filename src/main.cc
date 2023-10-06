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

void readFromFile(std::string filename, PushDownAutomata& APv) {
  std::fstream file;
  file.open(filename, std::ios::in);

  if(!file.is_open()) {
    std::cerr << "Error oppening file\n";
    exit(EXIT_FAILURE);
  }

  std::string line = "";
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

  std::string initialState = "";
  std::getline(file, initialState);

  std::vector<State> stateVector;
  for(std::string name : statesRaw) {
    State state(name);
    if(name == initialState) state.setInitial(true);
    stateVector.push_back(state);
  }

  std::string stackInitialSymbol = "";
  std::getline(file, stackInitialSymbol);

  std::vector<Transition> transitions;
  while(std::getline(file, line)) {
    ss.clear();
    ss.str(line);
    std::vector<std::string> trans;
    while(std::getline(ss, token, delimeter)) {
      trans.push_back(token);
    }
    std::string newSS;
    for(int i = 4; i < trans.size(); i++) newSS = newSS + trans[i];

    Transition newTrans(trans[0], trans[3], trans[1][0], trans[2][0], newSS);
    transitions.push_back(newTrans);
  }

  // for(Transition t : transitions) std::cout << "Debug Transitiosn: " + t.toString() + "\n";


  for(Transition actual : transitions) {
    for(int i = 0; i < stateVector.size(); i++) {
      // std::cout << "Debug Transitiosn: " + actual.toString() + "\n";
      // std::cout << "Debug State: " + stateVector[i].getName() + "\n";
      if(actual.getOrigin() == stateVector[i].getName()) {
        // std::cout << "found " + actual.getOrigin() + " for state " + stateVector[i].getName() + "\n";
        stateVector[i].addTransition(actual);
        // std::cout << "checking state transition insertion: ";
        // for(Transition t : stateVector[i].getTransitions()) std::cout << t.toString() + "\n";
      }
    } 
  }

  APv.addAlphabet(alphabet);
  APv.addStackAlphabet(stackAlphabet);
  APv.addState(stateVector);
  APv.setInitialState(initialState);
  APv.setInitialStackSymbol(stackInitialSymbol);


  std::cout << "read automata:\n  alphabet = {";
  for(char c : APv.getAlphabet()) {
    std::cout << c << " ";
  }
  std::cout << "}\n  stack alphabet = {";
  for(char c : APv.getStackAlphabet()) {
    std::cout << c << " ";
  }

  std::cout << "}\n  initial stack simbols = {";
  for(char c : APv.getInitialStackSymbol()) {
    std::cout << c << " ";
  }

  std::cout << "}\n  states = {";
  for(State s : APv.getStates()) {
    std::cout << s.getName() << " ";
  }

  std::cout << "}\n  initial state = {" + APv.getInitialState();
  std::cout << "}\n  transitions = {\n";
  for(State s : APv.getStates()) {
    for(Transition t : s.getTransitions()) {
      std::cout << "    " + t.toString() + "\n";
    }
  }
  std::cout << "  }\n";

}

void testLoop(PushDownAutomata& APv, bool trace) {
  std::cout << (trace ? " trace" : " noTrace") << std::endl;

  std::string word = "";
  while(true) {
    std::cin >> word;
    bool accepted = APv.isAccepted(word, trace);
    std::cout << "The word " + word + " is";
    if(!accepted) std::cout << " not";
    std::cout << " accepted by the languaje.\n";
  }
}

int main(int argc, char* argv[]) {
  std::string filename = argv[1];
  PushDownAutomata APv;
  bool trace = false;
  if(argc > 2) trace = bool(argv[2]);
  std::cout << filename + (trace ? " trace" : " noTrace") + "\n";

  readFromFile(filename, APv);
  
  testLoop(APv, trace);
}