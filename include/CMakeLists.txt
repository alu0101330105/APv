add_library(libraries SHARED
  pushdownAutomata.h
  pushdownAutomata.cc
  state.cc
  state.h
  transition.cc
  transition.h
  )

target_include_directories(libraries PUBLIC
  .
)