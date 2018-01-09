#pragma once

/**
 * Simulate an interface that has the `display()` method.
 */
class IDisplay
{
  public:
    virtual void display() = 0;
    virtual ~IDisplay() {};
};
