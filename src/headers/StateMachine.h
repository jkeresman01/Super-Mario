#pragma once

#include <memory>
#include <stack>

#include "State.h"

namespace mario
{

typedef std::unique_ptr<State> StateRefT;

class StateMachine
{
  public:
    StateMachine() = default;
    ~StateMachine() = default;

    void addState(StateRefT state, bool isReplacing);
    void removeState();

    StateRefT &getActiveState();

  private:
    std::stack<StateRefT> m_states;
};

} // namespace mario
